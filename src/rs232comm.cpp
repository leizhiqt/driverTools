#include "rs232comm.h"
#include <drv_global.h>
#include <QThreadPool>
#include <QQuickItem>
#include <QtCore>
#include <QDebug>
#include "threadtask.h"
#include "buscomm.h"
#include "callc.h"
#include <QMetaObject>
#include "bclog.h"
#include "convert_util.h"
#include "QtStrConvert.h"

uint8_t rxbuf232[rs232PortNum][2048];

rs232Comm *rs232Comm::pThis = 0;
/**
 * @brief
 * @return
 */
rs232Comm *rs232Comm::getInstance()
{
    if (!pThis) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!pThis) {
            pThis = new rs232Comm;
        }
    }
    return pThis;
}

rs232Comm::rs232Comm(QObject *parent) : QObject(parent)
{

}

int rs232Comm::openRS232()
{
    rs232Thread=new ThreadTask(3);
    for(int i=0;i<rs232PortNum;i++)
    {
        rs232PortReadAddress[i]=0x0000+i*0x10;
        rs232PortWriteAddress[i]=0x00E0+i*0x10;
        rs232Config(i+1);
    }

    connect(rs232Thread,SIGNAL(recvRS232Changed(int,QByteArray,int)),this,SLOT(onRS232RecvMsg(int,QByteArray,int)));

    connect(this,SIGNAL(onCloseThread()),rs232Thread,SLOT(onClosed()));
    QThreadPool::globalInstance()->start(rs232Thread);

    for(int i=0;i<rs232PortNum;i++)
    {
        isRS232Open[i]=true;
        m_HexRS232[i]=true;
        LOG_INFO("===============m_HexRS232 %d %d",i,m_HexRS232[i]);
    }
    return 0;
}


int rs232Comm::closeRS232()
{
    int result=-1;
    for(int i=0;i<rs232PortNum;i++)
    {
        result=rs232_close(rs232PortReadAddress[i]);
        result=rs232_close(rs232PortWriteAddress[i]);
    }
    return result;

}


int rs232Comm::rs232Config(int fd, int baudrate, int bits, int parity, int stop)
{
    int result=crs232_config((uint32_t)fd, (uint32_t)baudrate, (uint32_t)(bits-5), (uint32_t)parity, (uint32_t)stop);
    return result;
}

QString rs232Comm::GetCorrectUnicode(const QByteArray& ba)
{
    QTextCodec::ConverterState state;
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QString text = codec->toUnicode(ba.constData(), ba.size(), &state);
    if(state.invalidChars > 0)
    {
        text = QTextCodec::codecForName("GBK")->toUnicode(ba);
    }
    else
    {
        text = ba;
    }
    return text;
}

void rs232Comm::setHexRS232(int fd,bool hexRS232)
{
    LOG_INFO("setHexRS232 %d %d",hexRS232,m_HexRS232[fd-1]);

    if(m_HexRS232[fd-1]==hexRS232)
        return;

    m_HexRS232[fd-1]=hexRS232;

    if ((m_recvRS232[fd-1]).length()>1024*4)
    {
        m_recvRS232[fd-1]=m_recvRS232[fd-1].mid(1024*4,m_recvRS232[fd-1].length()-1024*4);
    }

    QString tempStr=m_recvRS232[fd-1];
    tempStr.replace(" ","");

    LOG_INFO("setHexRS232 %s",tempStr.toLatin1().data());

    m_recvRS232[fd-1]="";

    if(m_HexRS232[fd-1]){
        tempStr=tempStr.toLatin1().toHex(' ');
        LOG_INFO("setHexRS232 %s",tempStr.toLatin1().data());

        setRecvRS232(fd,tempStr);
    } else {
        QByteArray ab=QByteArray::fromHex(tempStr.toLatin1());
        QString returnData=GetCorrectUnicode(ab);
        LOG_INFO("setHexRS232 %s",returnData.toLatin1().data());

        setRecvRS232(fd,returnData);
    }
}

void rs232Comm::setRecvRS232(const int fd, const QString &recvRS232)
{
    LOG_INFO("setRecvRS232 m_recvRS232[fd-1] %s",m_recvRS232[fd-1].toLatin1().data());
    LOG_INFO("setRecvRS232 recvRS232 %s",recvRS232.toLatin1().data());

//    if (recvRS232 == m_recvRS232[fd-1]  && recvRS232!="")
//        return;

//    LOG_INFO("setRecvRS232 %s",recvRS232.toLatin1().data());

    if (recvRS232=="")
    {
        m_recvBytesRS232[fd-1]=0;
        m_recvRS232[fd-1]=recvRS232;
    }else{
        m_recvRS232[fd-1] += " "+recvRS232;
    }

    QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs232GroupBox");
    LOG_INFO("setRecvRS422 fd=%d count=%d recvRS232=%s",fd,objList.count(),recvRS232.toLatin1().data());

    if(objList.count()>=fd){
        QList<QObject*> rs232RecvItemTextAreaList=objList[fd-1]->findChildren<QObject*>("rs232RecvItemTextArea");
        if (rs232RecvItemTextAreaList.count()>0){
            QObject* rs232RecvItemTextArea= rs232RecvItemTextAreaList.first();
            if(rs232RecvItemTextArea)
            {
                QString m_recvStr = m_recvRS232[fd-1];
                rs232RecvItemTextArea->setProperty("text",m_recvStr);
                LOG_INFO("setRecvRS232 =%s",m_recvStr.toLatin1().data());

                bool bRet=QMetaObject::invokeMethod(rs232RecvItemTextArea,"clear");
                bRet=QMetaObject::invokeMethod(rs232RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }
        QList<QObject*> labelRecvBytesRS232List=objList[fd-1]->findChildren<QObject*>("lbl232RecvBytes");
        if (labelRecvBytesRS232List.count()>0){
            QObject* labelRecvBytesRS232= labelRecvBytesRS232List.first();
            if(labelRecvBytesRS232)
            {
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesRS232[fd-1]);
                LOG_INFO("setRecvRS232 =%s",m_recvBytesStr.toLatin1().data());

                labelRecvBytesRS232->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesRS232,"doLayout");
            }
        }
    }
}

void rs232Comm::setRecvBytesRS232(const int fd, long recvBytesRS232)
{
    if (m_recvBytesRS232[fd-1] == recvBytesRS232)
        return;
    m_recvBytesRS232[fd-1] = recvBytesRS232;
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs232GroupBox");
    if(objList.count()>=fd){
        //result = (int)rs422_write(rs232PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> labelRecvBytesRS232List=objList[fd-1]->findChildren<QObject*>("lbl232RecvBytes");
        if (labelRecvBytesRS232List.count()>0){
            QObject* labelRecvBytesRS232= labelRecvBytesRS232List.first();
            if(labelRecvBytesRS232)
            {
                //QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS232[fd-1],3,10,QChar('0'));
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesRS232[fd-1]);
                labelRecvBytesRS232->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesRS232,"doLayout");
            }
        }
    }
}

void rs232Comm::setSendBytesRS232(const int fd,long sendBytesRS232)
{    
//    m_sendBytesRS232[fd-1] = sendBytesRS232;
    if (enableDisplay[fd-1])
    {
        QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs232GroupBox");
        if(objList.count()>=fd){
            QList<QObject*> labelSendBytesRS232List=objList[fd-1]->findChildren<QObject*>("lbl232SendBytes");
            if (labelSendBytesRS232List.count()>0){
                QObject* labelSendBytesRS232= labelSendBytesRS232List.first();
                if(labelSendBytesRS232)
                {
                    QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS232[fd-1]);
                    labelSendBytesRS232->setProperty("text",m_sendBytesStr);
                    bool bRet=QMetaObject::invokeMethod(labelSendBytesRS232,"doLayout");
                }
            }
        }
    }
}

void rs232Comm::saveFileClick(int fd,bool saveFile)
{
    if(saveFile)
    {
        QDateTime currtime = QDateTime::currentDateTime();
        QString fileName="./rs232_"+QString::number(fd)+"_"+currtime.toString("yyyyMMddhhmmss")+".txt";
        FILE *fp=fopen(fileName.toLocal8Bit().data(),"wb");
        if (saveFileName[fd-1].open(fp,QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
            return;
        isSaveFile[fd-1]=true;
    }
    else
    {
        if(isSaveFile[fd-1])
          saveFileName[fd-1].close();
    }
}

void rs232Comm::appendRecvRS232(int fd,const QString &recvRS232)
{
    LOG_INFO("appendRecvRS232 %s",recvRS232.toLatin1().data());

//    if(m_HexRS232[fd-1] && m_recvBytesRS232[fd-1]>0)
//    {
//        m_recvRS232[fd-1] =m_recvRS232[fd-1]+" "+recvRS232;
//        if(isSaveFile[fd-1])
//           saveFileName[fd-1].write((" "+recvRS232).toLocal8Bit());
//    }
//    else
//    {
//        m_recvRS232[fd-1] += recvRS232;
//        if(isSaveFile[fd-1])
//          saveFileName[fd-1].write(recvRS232.toLocal8Bit());
//    }if (m_recvRS232[fd-1].length()>1024*16*2)
//        m_recvRS232[fd-1]=m_recvRS232[fd-1].mid(1024*16,m_recvRS232[fd-1].length()-1024*16);
//    if (enableDisplay[fd-1])
//    {
//        m_recvRS232[fd-1]=recvRS232;
        setRecvRS232(fd,recvRS232);
//        enableDisplay[fd-1]=false;
//    }
}
void rs232Comm::onRS232RecvMsg(int fd, QByteArray data,int length)
{
    if(m_HexRS232[fd-1]){
//        QByteArray ab;
        LOG_INFO("onRS232RecvMsg %d %s",length,data.begin());
        m_recvBytesRS232[fd-1] += data.length();

        QString str1(data);
        str1.replace(" ","");
        QByteArray ba;
        convertStringToHex(str1,ba);

        QString hexs = ByteArrayToHexString(ba);

        appendRecvRS232(fd,hexs);
    } else {
        QString returnData=GetCorrectUnicode(data);
        LOG_INFO("appendRecvRS232 %d",length);
        m_recvBytesRS232[fd-1] += returnData.length();
        appendRecvRS232(fd,returnData);
    }
}

int rs232Comm::sendMsg232(int fd, QString msgPack, int size,bool isHex)
{
    int result = -1;

    LOG_INFO("sendMsg232 %s",msgPack.toLatin1().data());
    LOG_INFO("setRecvRS232 m_recvRS232[fd-1] %s",m_recvRS232[fd-1].toLatin1().data());

    /*
//    QTextCodec* gbk = QTextCodec::codecForName("gbk");
//    QByteArray send_arr = gbk->fromUnicode(msgPack.toLocal8Bit().data());
//    size=send_arr.length();
//    char msg_buf[size];
//    memset(msg_buf,0,size*sizeof(char));
//    memcpy(msg_buf,send_arr,size);

//    if(isRS232Open[fd-1])
//        result = (int)rs232_write(rs232PortWriteAddress[fd-1], send_arr, send_arr.length());
*/
    m_sendBytesRS232[fd-1] += size;
    m_HexRS232[fd-1] = isHex;
    LOG_INFO("setHexRS232 %d %d",hexRS232,m_HexRS232[fd-1]);

    setSendBytesRS232(fd, m_sendBytesRS232[fd-1]);

    LOG_INFO("setRecvRS232 m_recvRS232[fd-1] %s",m_recvRS232[fd-1].toLatin1().data());

//    m_recvBytesRS232[fd-1] += size;
//    setRecvRS232(fd,msgPack);
    LOG_INFO("setRecvRS232 m_recvRS232[fd-1] %s",m_recvRS232[fd-1].toLatin1().data());

    return 0;
}

void rs232Comm::onClosed()
{
    emit onCloseThread();
    for(int i=0;i<rs232PortNum;i++)
    {
        if(isSaveFile[i])
            saveFileName[i].close();
    }
}

