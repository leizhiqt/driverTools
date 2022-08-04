#include "rs422comm.h"
#include <drv_global.h>
#include <QtCore>
#include <stdio.h>
#include <QDebug>
#include "threadtask.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "callc.h"
#include "uartfunc.h"
#include "bclog.h"
#include "QtStrConvert.h"

uint8_t rxbuf422[rs422PortNum][2048];
rs422Comm *rs422Comm::pThis = 0;
/**
 * @brief
 * @return
 */
rs422Comm *rs422Comm::getInstance()
{
    if (!pThis) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!pThis) {
            pThis = new rs422Comm;
        }
    }

    return pThis;
}
rs422Comm::rs422Comm(QObject *parent) : QObject(parent)
{

}



void rs422Comm::saveFileClick(int fd,bool saveFile)
{
    if(saveFile)
    {
        QDateTime currtime = QDateTime::currentDateTime();
        QString fileName="./rs422_"+QString::number(fd)+"_"+currtime.toString("yyyyMMddhhmmss")+".txt";
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

void rs422Comm::setHexRS422(int fd,bool hexRS422)
{
    if(m_HexRS422[fd-1]==hexRS422)
        return;
    m_HexRS422[fd-1]=hexRS422;

    if ((m_recvRS422[fd-1]).length()>1024*4)
    {
        m_recvRS422[fd-1]=m_recvRS422[fd-1].mid(1024*4,m_recvRS422[fd-1].length()-1024*4);
    }

    QString tempStr=m_recvRS422[fd-1];
    tempStr.replace(" ","");

    m_recvRS422[fd-1]="";

    if(m_HexRS422[fd-1]){
        tempStr=tempStr.toLatin1().toHex(' ');

        setRecvRS422(fd,tempStr);
    } else {
        QByteArray ab=QByteArray::fromHex(tempStr.toLatin1());
        QString returnData=GetCorrectUnicode(ab);
        LOG_INFO("setRecvRS422 %s",returnData.toLatin1().data());

        setRecvRS422(fd,returnData);
    }
}

void rs422Comm::setRecvRS422(const int fd, const QString &recvRS422)
{
    LOG_INFO("setRecvRS422 fd=%d %s",fd,recvRS422.toLatin1().data());

    //if (recvRS422 == m_recvRS422[fd-1]  && recvRS422!="")
    //    return;

    if (recvRS422=="")
    {
        m_recvBytesRS422[fd-1]=0;
        m_recvRS422[fd-1]=recvRS422;
    }else{
        m_recvRS422[fd-1] += " "+recvRS422;
    }

    QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs422GroupBox");
    LOG_INFO("setRecvRS422 fd=%d count=%d",fd,objList.count());

    if(objList.count()>=fd){
        //result = (int)rs422_write(rs422PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> rs422RecvItemTextAreaList=objList[fd-1]->findChildren<QObject*>("rs422RecvItemTextArea");
        if (rs422RecvItemTextAreaList.count()>0){
            QObject* rs422RecvItemTextArea= rs422RecvItemTextAreaList.first();
            if(rs422RecvItemTextArea)
            {
                QString m_recvStr=QString("%1").arg(m_recvRS422[fd-1]);
                rs422RecvItemTextArea->setProperty("text",m_recvStr);

                bool bRet=QMetaObject::invokeMethod(rs422RecvItemTextArea,"clear");
                bRet=QMetaObject::invokeMethod(rs422RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }
        QList<QObject*> labelRecvBytesRS422List=objList[fd-1]->findChildren<QObject*>("lbl422RecvBytes");
        if (labelRecvBytesRS422List.count()>0){
            QObject* labelRecvBytesRS422= labelRecvBytesRS422List.first();
            if(labelRecvBytesRS422)
            {
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesRS422[fd-1]);
                labelRecvBytesRS422->setProperty("text",m_recvBytesStr);

                bool bRet=QMetaObject::invokeMethod(labelRecvBytesRS422,"doLayout");
                LOG_INFO("setRecvRS422 fd=%d",fd);
            }
        }
    }
    LOG_INFO("setRecvRS422 fd=%d",fd);
}

void rs422Comm::setRecvBytesRS422(const int fd, long recvBytesRS422)
{
    if (m_recvBytesRS422[fd-1] == recvBytesRS422)
        return;
    m_recvBytesRS422[fd-1] = recvBytesRS422;
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs422GroupBox");
    if(objList.count()>=fd){
        //result = (int)rs422_write(rs422PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> labelRecvBytesRS422List=objList[fd-1]->findChildren<QObject*>("lbl422RecvBytes");
        if (labelRecvBytesRS422List.count()>0){
            QObject* labelRecvBytesRS422= labelRecvBytesRS422List.first();
            if(labelRecvBytesRS422)
            {
                //QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS422[fd-1],3,10,QChar('0'));
                QString m_recvBytesStr=QString("%1").arg(m_recvBytesRS422[fd-1]);
                labelRecvBytesRS422->setProperty("text",m_recvBytesStr);
                bool bRet=QMetaObject::invokeMethod(labelRecvBytesRS422,"doLayout");
            }
        }
    }
}

void rs422Comm::setSendBytesRS422(const int fd,long sendBytesRS422)
{
    m_sendBytesRS422[fd-1] = sendBytesRS422;
    if (enableDisplay[fd-1])
    {
        QList<QObject*> objList=qmlObject->findChildren<QObject*>("rs422GroupBox");
        if(objList.count()>=fd){
            //result = (int)rs422_write(rs422PortReadAddress[fd-1], msg_buf, (uint16_t)size);
            QList<QObject*> labelSendBytesRS422List=objList[fd-1]->findChildren<QObject*>("lbl422SendBytes");
            if (labelSendBytesRS422List.count()>0){
                QObject* labelSendBytesRS422= labelSendBytesRS422List.first();
                if(labelSendBytesRS422)
                {
                    //QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS422[fd-1],3,10,QChar('0'));
                    QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS422[fd-1]);
                    labelSendBytesRS422->setProperty("text",m_sendBytesStr);
                    bool bRet=QMetaObject::invokeMethod(labelSendBytesRS422,"doLayout");
                }
            }
        }
    }
}

void rs422Comm::appendRecvRS422(int fd,const QString &recvRS422)
{
    LOG_INFO("appendRecvRS422 %s",recvRS422.toLatin1().data());
//    if(m_HexRS422[fd-1] && m_recvBytesRS422[fd-1]>0)
//    {
//        LOG_INFO("appendRecvRS422");
//        m_recvRS422[fd-1] =m_recvRS422[fd-1]+" "+recvRS422;
//        if(isSaveFile[fd-1]){
//            LOG_INFO("appendRecvRS422");
//           saveFileName[fd-1].write((" "+recvRS422).toLocal8Bit());
//        }
//    }
//    else
//    {
//        LOG_INFO("appendRecvRS422");
//        m_recvRS422[fd-1] += recvRS422;
//        if(isSaveFile[fd-1]){
//          saveFileName[fd-1].write(recvRS422.toLocal8Bit());
//        }
//    }
//    if (m_recvRS422[fd-1].length()>1024*16*2){
//        LOG_INFO("appendRecvRS422");
//        m_recvRS422[fd-1]=m_recvRS422[fd-1].mid(1024*16,m_recvRS422[fd-1].length()-1024*16);
//    }
//    LOG_INFO("appendRecvRS422");
//    if (enableDisplay[fd-1])
//    {
        LOG_INFO("appendRecvRS422");
        setRecvRS422(fd,recvRS422);
        //emit recvRS42208Changed();
        //emit recvBytesRS42208Changed();
//        enableDisplay[fd-1]=false;
//    }
//    LOG_INFO("appendRecvRS422");
}

void rs422Comm::onRS422RecvMsg(int fd, QByteArray data,int length)
{
    LOG_INFO("onRS422RecvMsg %d %s",length,data.begin());

    m_recvBytesRS422[fd-1]+=length;
    if(m_HexRS422[fd-1]){
        QString str1(data);
        str1.replace(" ","");
        QByteArray ba;
        convertStringToHex(str1,ba);

        QString hexs = ByteArrayToHexString(ba);

        appendRecvRS422(fd,hexs);
    } else {
        QString returnData=GetCorrectUnicode(data);

        appendRecvRS422(fd,returnData);
    }
}

int rs422Comm::openRS422()
{
    //open422Manchester();
    rs422ManchesterThread=new ThreadTask(6);
    rs422Thread=new ThreadTask(2);
    connect(rs422Thread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRS422RecvMsg(int,QByteArray,int)));
    connect(rs422ManchesterThread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRS422RecvMsg(int,QByteArray,int)));

    //connect(rs422ManchesterThread,SIGNAL(setManPara(int*)),this,SLOT(onRecv422ManPara(int*)));
    connect(this,SIGNAL(send422ManData(int,QByteArray,int)),rs422ManchesterThread,SLOT(onRecvSend422ManData(int,QByteArray,int)));

    connect(this,SIGNAL(onCloseThread()),rs422Thread,SLOT(onClosed()));
    connect(this,SIGNAL(onCloseThread()),rs422ManchesterThread,SLOT(onClosed()));
    //connect(&serial_port, &QSerialPort::readyRead, this,&rs422Comm::reciveSerialData);//串口打开就接收消息
    QThreadPool::globalInstance()->start(rs422Thread);
    QThreadPool::globalInstance()->start(rs422ManchesterThread);

    QTextCodec *gbk=QTextCodec::codecForName("GB18030");
    decoder=gbk->makeDecoder();
    //use ttyS1 test serial
    //QString portname="/dev/ttyS1";
    //serial_port.setPortName(portname);
    //serial_port.setBaudRate(115200);
    //serial_port.setParity(QSerialPort::NoParity);
    //serial_port.setDataBits(QSerialPort::Data8);
    //serial_port.setStopBits(QSerialPort::OneStop);
    //serial_port.open(QSerialPort::ReadWrite);
    //is_open_serailport=true;
    for(int i=0;i<rs422PortNum;i++){
        isRS422Open[i]=true;
        m_HexRS422[i]=true;
    }
    return 0;
}



 /*void rs422Comm::reciveSerialData()
 {
     if(!this->is_open_serailport) return;
     const QByteArray& rcv_data = serial_port.readAll();
     if(rcv_data.length() <= 0) return ;
     onRS42201RecvMsg(rcv_data,rcv_data.length());
 }*/




int rs422Comm::closeRS422()
{
    int result=0;
    for(int i=0;i<rs422PortNum;i++)
    {
        result=rs422_close(rs422PortReadAddress[i]);
        result=rs422_close(rs422PortWriteAddress[i]);
    }
    return result;

}

void rs422Comm::onRecv422ManPara(int* fdmPara)
{
    for(int i=0;i<4;i++)
        fdm[i]=fdmPara[i];
}

int rs422Comm::rs422Config(int fd, int baudrate, int bits, int parity, int stop)
{
    int result=crs422_config((uint32_t)fd, (uint32_t)baudrate, (uint32_t)(bits-5), (uint32_t)parity, (uint32_t)stop);
    return result;
}

QString rs422Comm::GetCorrectUnicode(const QByteArray& ba)
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

int rs422Comm::sendMsg422(int fd, QByteArray msgPack, int size,bool isHex)
{
    int result = -1;

    LOG_INFO("sendMsg422 %s",msgPack.data());
    LOG_INFO("setRecvRS232 m_recvRS422[fd-1] %s",m_recvRS422[fd-1].data());

    m_sendBytesRS422[fd-1] += size;
    m_HexRS422[fd-1] = isHex;
    LOG_INFO("setHexRS232 %d %d",m_HexRS422,m_sendBytesRS422[fd-1]);
    setSendBytesRS422(fd, m_sendBytesRS422[fd-1]);


    //QTextCodec* gbk = QTextCodec::codecForName("gbk");
    //QByteArray send_arr = gbk->fromUnicode(msgPack.toLocal8Bit().data());


    /*QByteArray send_arr=msgPack;
    size=send_arr.length();
    char msg_buf[size];
    memset(msg_buf,0,size*sizeof(char));
    memcpy(msg_buf,send_arr,size);
    if(fd==2 || fd==4 || fd==6 || fd==8)
    {
        emit send422ManData(fd,msgPack,size);
    }
    if(isRS422Open[fd-1])
    {
        result = (int)rs422_write(rs422PortWriteAddress[fd-1], msg_buf, size);
        m_sendBytesRS422[fd-1]+=size;
        setSendBytesRS422(fd, m_sendBytesRS422[fd-1]);
    }
    else
        qDebug()<<"RS422_TX_"<< fd-1 <<" is not Open\n";
    */
    return 0;
}

void rs422Comm::onClosed()
{
    emit onCloseThread();
    for(int i=0;i<rs422PortNum;i++)
    {
        if(isSaveFile[i])
            saveFileName[i].close();
    }
}
