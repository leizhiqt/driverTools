#include "arincComm429.h"
#include <drv_global.h>
#include <QtCore>
#include <QDebug>
#include <QThread>
#include "threadtask.h"
#include "callc.h"
#include "bclog.h"
#include "convert_util.h"
#include "QtStrConvert.h"

extern void str_trim(char  *s1);

uint8_t rxbuf429[arinc429PortNum][2048];

arincComm429 *arincComm429::pThis = 0;
/**
 * @brief
 * @return
 */
arincComm429 *arincComm429::getInstance()
{
    if (!pThis) {
        QMutex         mutex;
        QMutexLocker locker(&mutex);
        if (!pThis) {
            pThis = new arincComm429;
        }
    }

    return pThis;
}

arincComm429::arincComm429(QObject *parent) : QObject(parent)
{

}


void arincComm429::setRecvArinc429(const int fd, const QString recvArinc429)
{
    LOG_INFO("setRecvArinc429 [%s]",recvArinc429.toLatin1().data());

    if (recvArinc429=="")
    {
        m_recvBytesArinc429[fd-1]=0;
        m_recvArinc429[fd-1]=recvArinc429;
    }else{
        m_recvArinc429[fd-1] += " "+recvArinc429;
    }

    QList<QObject*> objList=qmlObject->findChildren<QObject*>("arinc429GroupBox");
    if(objList.count()>=fd){

        QList<QObject*> arinc429RecvItemTextAreaList=objList[fd-1]->findChildren<QObject*>("arinc429RecvItemTextArea");
        if (arinc429RecvItemTextAreaList.count()>0){
            QObject* arinc429RecvItemTextArea= arinc429RecvItemTextAreaList.first();
            if(arinc429RecvItemTextArea)
            {
                QString m_recvStr = m_recvArinc429[fd-1];;
                arinc429RecvItemTextArea->setProperty("text",m_recvStr);
                bool bRet;
                LOG_INFO("setRecvArinc429 [%s]",recvArinc429.toLatin1().data());
                bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"clear");
                bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }

        QList<QObject*> labelRecvBytesArinc429List=objList[fd-1]->findChildren<QObject*>("lbl429RecvBytes");
        if (labelRecvBytesArinc429List.count()>0){
            QObject* labelRecvBytesArinc429= labelRecvBytesArinc429List.first();
            if(labelRecvBytesArinc429)
            {
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesArinc429[fd-1]);
                LOG_INFO("setRecvArinc429 [%s]",recvArinc429.toLatin1().data());

                labelRecvBytesArinc429->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesArinc429,"doLayout");
            }
        }
        LOG_INFO("setRecvArinc429 end");
    }
}

void arincComm429::setRecvArincMsg(const int fd, const QString recvArinc429)
{
    LOG_INFO("setRecvArincMsg");

    if (recvArinc429=="") m_recvBytesArinc429[fd-1]=0;
    m_recvArinc429[fd-1] = recvArinc429;

    qDebug()<<"recvArinc429:"<<m_recvArinc429[fd-1];

    QList<QObject*> objList=qmlObject->findChildren<QObject*>("arinc429GroupBox");
    if(objList.count()>=fd){
        //显示数据
        QList<QObject*> arinc429RecvItemTextAreaList=objList[fd-1]->findChildren<QObject*>("arinc429RecvItemTextArea");
        if (arinc429RecvItemTextAreaList.count()>0){
            QObject* arinc429RecvItemTextArea= arinc429RecvItemTextAreaList.first();
            if(arinc429RecvItemTextArea)
            {
                QString m_recvStr=m_recvArinc429[fd-1];
                arinc429RecvItemTextArea->setProperty("text",m_recvStr);

                bool bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"clear");
                bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }
        //显示长度
        QList<QObject*> labelRecvBytesArinc429List=objList[fd-1]->findChildren<QObject*>("lbl232RecvBytes");
        if (labelRecvBytesArinc429List.count()>0){
            QObject* labelRecvBytesArinc429= labelRecvBytesArinc429List.first();
            if(labelRecvBytesArinc429)
            {
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesArinc429[fd-1]);

                labelRecvBytesArinc429->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesArinc429,"doLayout");
            }
        }
    }
}

void arincComm429::setRecvArincComm429(const int fd,const QString &recvArinc429)
{
    LOG_INFO("setRecvArincComm429");

    if (recvArinc429=="") m_recvBytesArinc429[fd-1]=0;
    m_recvArinc429[fd-1] = recvArinc429;
    //emit recvRS42210Changed();
    //emit recvBytesRS42210Changed();
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("Arinc429GroupBox");
    if(objList.count()>fd){
        //result = (int)rs422_write(Arinc429PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> arinc429RecvItemTextAreaList=objList[fd-1]->findChildren<QObject*>("arinc429RecvItemTextArea");
        if (arinc429RecvItemTextAreaList.count()>0){
            QObject* arinc429RecvItemTextArea= arinc429RecvItemTextAreaList.first();
            if(arinc429RecvItemTextArea)
            {
                QString m_recvStr=m_recvArinc429[fd-1];
                arinc429RecvItemTextArea->setProperty("text",m_recvStr);

                bool bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"clear");
                bRet=QMetaObject::invokeMethod(arinc429RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }
        QList<QObject*> labelRecvBytesArinc429List=objList[fd-1]->findChildren<QObject*>("lbl232RecvBytes");
        if (labelRecvBytesArinc429List.count()>0){
            QObject* labelRecvBytesArinc429= labelRecvBytesArinc429List.first();
            if(labelRecvBytesArinc429)
            {
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesArinc429[fd-1]);
                labelRecvBytesArinc429->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesArinc429,"doLayout");
            }
        }
    }


}

void arincComm429::setRecvBytesArinc429(const int fd, long recvBytesArinc429)
{
    LOG_INFO("setRecvBytesArinc429");

    if (m_recvBytesArinc429[fd-1] == recvBytesArinc429)
        return;
    m_recvBytesArinc429[fd-1] = recvBytesArinc429;
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("arinc429GroupBox");
    if(objList.count()>=fd){
        //result = (int)rs422_write(arinc429PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> labelRecvBytesArinc429List=objList[fd-1]->findChildren<QObject*>("lbl429RecvBytes");
        if (labelRecvBytesArinc429List.count()>0){
            QObject* labelRecvBytesArinc429= labelRecvBytesArinc429List.first();
            if(labelRecvBytesArinc429)
            {
                //QString m_sendBytesStr=QString("%1").arg(m_sendBytesArinc429[fd-1],3,10,QChar('0'));
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesArinc429[fd-1]);
                LOG_INFO("%s",m_recvBytesStr.toUtf8().data());
                labelRecvBytesArinc429->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesArinc429,"doLayout");
            }
        }
    }
}
//QByteArray msgPack, int size
void arincComm429::setSendBytesArinc429(const int fd,int len)
{
    LOG_INFO("setSendBytesArinc429 size=%d",len);

    QString m_sendBytesStr=QString("%1").arg(len);
    //    LOG_INFO("size=%d",len);
    //    LOG_INFO("%s",m_sendBytesStr.toLatin1().data());

    if (enableDisplay[fd-1])
    {
        QList<QObject*> objList=qmlObject->findChildren<QObject*>("arinc429GroupBox");
        if(objList.count()>=fd)
        {
            QList<QObject*> labelSendBytesArinc429List=objList[fd-1]->findChildren<QObject*>("lbl429SendBytes");
            if (labelSendBytesArinc429List.count()>0)
            {
                QObject* labelSendBytesArinc429= labelSendBytesArinc429List.first();
                if(labelSendBytesArinc429)
                {
                    labelSendBytesArinc429->setProperty("text",m_sendBytesStr);
                    bool bRet=QMetaObject::invokeMethod(labelSendBytesArinc429,"doLayout");
                }
            }
        }
    }
}

void arincComm429::saveFileClick(int fd,bool saveFile)
{
    if(saveFile)
    {
        QDateTime currtime = QDateTime::currentDateTime();
        QString fileName="./arinc429_"+QString::number(fd)+"_"+currtime.toString("yyyyMMddhhmmss")+".txt";
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

QString arincComm429::GetCorrectUnicode(const QByteArray& ba)
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

void arincComm429::setDisplayHexArinc429(int fd,bool hexARINC429)
{
    LOG_INFO("setDisplayHexArinc429 %d %d",hexARINC429,m_HexArinc429[fd-1]);

    if(m_HexArinc429[fd-1]==hexARINC429)
        return;

    m_HexArinc429[fd-1]=hexARINC429;

    if ((m_recvArinc429[fd-1]).length()>1024*4)
    {
        m_recvArinc429[fd-1]=m_recvArinc429[fd-1].mid(1024*4,m_recvArinc429[fd-1].length()-1024*4);
    }

    QString tempStr=m_recvArinc429[fd-1];
    tempStr.replace(" ","");
    m_recvArinc429[fd-1]="";

    if(m_HexArinc429[fd-1]){
        tempStr=tempStr.toLatin1().toHex(' ');
        LOG_INFO("setDisplayHexArinc429 [%s]",tempStr.toLocal8Bit().data());
        setRecvArinc429(fd,tempStr);
    } else {
        QByteArray ab=QByteArray::fromHex(tempStr.toLatin1());
        QString returnData=GetCorrectUnicode(ab);
        LOG_INFO("setDisplayHexArinc429 %s",returnData.toLatin1().data());

        setRecvArinc429(fd,returnData);
    }
}

void arincComm429::onArinc429RecvMsg(const int fd, QString recvArinc429,int length)
{
    LOG_INFO("onArinc429RecvMsg [%s]",recvArinc429.toLocal8Bit().data());

    if(m_HexArinc429[fd-1]){
        m_recvBytesArinc429[fd-1] += length;
//        QString str1=recvArinc429.toLatin1();
//        str1.replace(" ","");
//        QByteArray ba;
//        convertStringToHex(str1,ba);

//        QString hexs = ByteArrayToHexString(ba);

//        LOG_INFO("onArinc429RecvMsg %d %s",length,hexs.toLatin1().begin());

        setRecvArinc429(fd,recvArinc429);
    } else {
        LOG_INFO("onArinc429RecvMsg %d %s",length,recvArinc429.toLatin1().begin());
        m_recvBytesArinc429[fd-1] += length;
        setRecvArinc429(fd,recvArinc429);
    }

//    m_recvBytesArinc429[fd-1] += length;

//    if(m_HexArinc429[fd-1] && m_recvBytesArinc429[fd-1]>0)
//    {

//        LOG_INFO("m_HexArinc429");
//        QString tempStr=recvArinc429;
////        tempStr.replace(" ","");

//        QTextCodec* gbk = QTextCodec::codecForName("gbk");
//        QByteArray temp_arr = gbk->fromUnicode(tempStr.toLocal8Bit().data());
//        tempStr=temp_arr.toHex(' ');

//        m_recvArinc429[fd-1] += " "+ tempStr;

//        if(isSaveFile[fd-1])
//            saveFileName[fd-1].write((" "+recvArinc429).toLocal8Bit());
//    }
//    else
//    {
//        LOG_INFO("text m_HexArinc429");

//        m_recvArinc429[fd-1] += " "+recvArinc429;

//        if(isSaveFile[fd-1])
//            saveFileName[fd-1].write(recvArinc429.toLocal8Bit());
//    }

//    if (m_recvArinc429[fd-1].length()>1024*16*2)
//        m_recvArinc429[fd-1]=m_recvArinc429[fd-1].mid(1024*16,m_recvArinc429[fd-1].length()-1024*16);

//    enableDisplay[fd-1]=true;
//    if (enableDisplay[fd-1])
//    {
//        LOG_INFO("setRecvArinc429 [%s]",m_recvArinc429[fd-1].toUtf8().data());

//        setRecvArinc429(fd,m_recvArinc429[fd-1]);
//        enableDisplay[fd-1]=false;
//    }
}

int arincComm429::openArinc429()
{

    arinc429Thread=new ThreadTask(1);
    for(int i=0;i<arinc429PortNum;i++)
    {
        arinc429PortReadAddress[i]=0x0400+i*0x10;
        arinc429PortWriteAddress[i]=0x0480+i*0x10;
        arinc429Config(i+1);
    }

    connect(arinc429Thread,SIGNAL(recvArinc429Changed(int,QString,int)),this,SLOT(onArinc429RecvMsg(int,QString,int)));

    connect(this,SIGNAL(onCloseThread()),arinc429Thread,SLOT(onClosed()));

    QThreadPool::globalInstance()->start(arinc429Thread);

    for(int i=0;i<arinc429PortNum;i++)
    {
        isArinc429Open[i]=true;
        m_HexArinc429[i]=false;
    }
    return 0;
}

int arincComm429::closeArinc429()
{
    int result=0;
    for(int i=0;i<arinc429PortNum;i++)
    {
        result=arinc429_close(arinc429PortReadAddress[i]);
        result=arinc429_close(arinc429PortWriteAddress[i]);
    }
    return result;
}

int arincComm429::arinc429Config(int fd, int baudrate, int parity, int encmode)
{
    carinc429_config(fd, baudrate, parity, encmode);
    return 0;
}

int arincComm429::sendMsg429(int fd, QByteArray msgPack, int size,bool isHex)
{
    int result = -1;

    LOG_INFO("sendMsg429 %s %d",msgPack.begin(),size);

    m_sendBytesArinc429[fd-1] += size;
    m_HexArinc429[fd-1] = isHex;
    setSendBytesArinc429(fd, m_sendBytesArinc429[fd-1]);

    //     char *p = msgPack.begin();
    //     char buf[4];
    //     memcpy(buf,p,4);
    //     ntoh_32(buf);

    //    QByteArray tarArray(msgPack);
    //    lowconvert(msgPack,&tarArray);

    //    QString msg=QString(tarArray).toUpper();
    //    int dataLenth=size/8;
    //    if (size%8>0)
    //        dataLenth++;
    //    uint32_t msg_buf[dataLenth];
    //    bool ok;
    //    for(int i=0;i<dataLenth;i++)
    //    {
    //        if (i==dataLenth-1)
    //        {
    //            msg_buf[i]=msg.mid(i*8,msg.length()-i*8).toUInt(&ok,16);
    //        }
    //        else
    //        {
    //            msg_buf[i]=msg.mid(i*8,8).toUInt(&ok,16);
    //        }
    //    }

    //    if(isArinc429Open[fd-1]){
    //        result = (int)arinc429_write(arinc429PortWriteAddress[fd-1], msg_buf, dataLenth);
    //        m_sendBytesArinc429[fd-1]+=4;
    //        if (enableDisplay[fd-1])
    //        {
    //            setSendBytesArinc429(fd, m_sendBytesArinc429[fd-1]);
    //            setSendBytesArinc429(fd, m_sendBytesArinc429[fd-1]);
    //            setSendBytesArinc429(fd, *((int *)buf));
    //        }
    //    }
    //    else
    //        qDebug()<<"ARINC429_TX_"<< fd-1 <<" is not Open\n";

    return result;
}

void arincComm429::onClosed()
{
    emit onCloseThread();
}
