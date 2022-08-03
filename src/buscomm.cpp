#include "buscomm.h"
#include <QDebug>
#include <QtCore>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <drv_global.h>
#include <qbytearray.h>
#include <QQmlApplicationEngine>
#include <QTime>
#include <QThreadPool>
#include "threadtask.h"
#include "convert_util.h"

void str_trim(char  *s1)
{
    char *s2;
    s2 = s1; //让我们的S2指向数组，以便更改数组里面的东西
    while (*s1) {
        if (*s1 == ' ') {
            s1++;
        } else {
            *s2 = *s1;
            s1++;
            s2++; //指向数组的指针往后移动
        }
    }
    *s2 = '\0';
}

busComm *busComm::pThis = 0;
/**
 * @brief
 * @return
 */
busComm *busComm::getInstance()
{
    if (!pThis) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!pThis) {
            pThis = new busComm;

        }
    }

    return pThis;
}



busComm::busComm(QObject *parent) : QObject(parent)
{    
    m_pTimer=new QTimer(this);
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    m_pTimer->start(1000);
}

QString busComm::recvString()
{
    return m_recvString;
}

void busComm::setRecvString(const QString &recvString)
{
    if (recvString == m_recvString)
        return;

    m_recvString = recvString;
    emit recvStringChanged();
}
void busComm::appendRecvString(const QString &recvString)
{
    //    m_recvString.append(recvString);
    //    if (enableDisplay)
    //    {
    //        emit recvStringChanged();
    //        enableDisplay=false;
    //    }
    if(recvString.indexOf("接收:")>-1)
    {
        m_tempString=recvString;
        isRecvData=true;
    }else if (recvString.indexOf("<br><br>")>-1 && isRecvData){
        if (m_tempString.length()<25)
        {
            m_tempString="<font color=\"#FF00FF\">"+m_tempString+"</font>";
            autoTestError=autoTestError+m_tempString;
        }
        m_tempString=m_tempString +recvString;
        m_recvString.append(m_tempString);
        m_tempString="";
        isRecvData=false;
        if (enableDisplay)
        {
            emit recvStringChanged();
            enableDisplay=false;
        }
    }
    else{
        if(isRecvData)
        {
            m_tempString=m_tempString+recvString;

        }else
        {
            if (recvString.indexOf("回环测试未通过")>-1){
                if(!isFirstIOError)
                {
                    autoTestError=autoTestError+"<br>";
                    isFirstIOError=true;
                }
                autoTestError=autoTestError+recvString;
            }
            if (recvString.indexOf("测试完毕")>-1 && autoTestError.length()>2){
                m_recvString.append("<br>有问题端口如下："+autoTestError+"<br><br>");
            }
            m_recvString.append(recvString);
            if (enableDisplay)
            {
                emit recvStringChanged();
                enableDisplay=false;
            }
        }
    }



}

uint32_t busComm::HexToDex(QString DataLineData)
{
    bool ok;
    return DataLineData.toUInt(&ok,16);
}

void busComm::handleTimeout()
{
    if(rs232!=nullptr)
    {
        for(int i=0;i<rs232PortNum;i++)
        {
            if (!rs232->enableDisplay[i])
            {
                emit rs232->recvRS232Changed(i+1);
                emit rs232->recvBytesRS232Changed(i+1);
                emit rs232->sendBytesRS232Changed(i+1);
                rs232->enableDisplay[i]=true;
            }
        }

        if(rs422!=nullptr)
        {
            for(int i=0;i<rs422PortNum;i++)
            {
                if (!rs422->enableDisplay[i])
                {
                    emit rs422->recvRS422Changed(i+1);
                    emit rs422->recvBytesRS422Changed(i+1);
                    emit rs422->sendBytesRS422Changed(i+1);
                    rs422->enableDisplay[i]=true;
                }
            }
        }
        if(arinc429!=nullptr)
        {
            for(int i=0;i<arinc429PortNum;i++)
            {
                if (!arinc429->enableDisplay[i])
                {
                    emit arinc429->recvArinc429Changed(i+1);
                    emit arinc429->recvBytesArinc429Changed(i+1);
                    emit arinc429->sendBytesArinc429Changed(i+1);
                    arinc429->enableDisplay[i]=true;
                }
            }
        }
        if (!enableDisplay)
        {
            emit recvStringChanged();
            enableDisplay=true;
        }
    }
}

void busComm::onRecvStringMsg(int fd,QByteArray data,int length)
{
    onRecvStringMsg(data,length);
}
void busComm::onRecvStringMsg(QByteArray data,int length)
{
    LOG_INFO("%s",data.begin());

    char msg_buf[length];
    memset(msg_buf,0,length*sizeof(uint8_t));
    memcpy(msg_buf,data,length);
    QByteArray byte(msg_buf,length);
    appendRecvString(byte);
}


void busComm::onRecvStringMsg(int fd,QString data,int length)
{
    appendRecvString(data);
}

void busComm::onRecvStringMsg(int fd,QString revcString)
{
    appendRecvString(revcString);
}
void busComm::onRecvStringMsg(QString revcString)
{
    LOG_INFO("onRecvStringMsg=%s",revcString.toUtf8().data());
    appendRecvString(revcString);
}

void busComm::onRecvStringMsg1(int fd,QByteArray data,int length)
{
    data=data.toHex(' ');
    appendRecvString(data);
}

void busComm::onRunAutoTestComplete()
{
    //disconnect(autoTestThread,SIGNAL(recvAutoTestStringChanged(QByteArray,int)),this,SLOT(onRecvStringMsg(QByteArray,int)));
    //disconnect(autoTestThread,SIGNAL(recvAutoTestStringChanged(QString)),this,SLOT(onRecvStringMsg(QString)));
    //disconnect(autoTestThread,SIGNAL(threadSendMsg(int,int,QByteArray,int,bool)),this,SLOT(onTheadSendMsg(int,int,QByteArray,int,bool)));
    //disconnect(autoTestThread,SIGNAL(runAutoTestComplete()),this,SLOT(onRunAutoTestComplete()));

    disconnect(rs232->rs232Thread,SIGNAL(recvRS232Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg(int,QByteArray,int)));
    disconnect(rs422->rs422Thread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg(int,QByteArray,int)));
    disconnect(arinc429->arinc429Thread,SIGNAL(recvArinc429Changed(int,QString,int)),this,SLOT(onRecvStringMsg(int,QString,int)));
    disconnect(rs422->rs422ManchesterThread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg1(int,QByteArray,int)));
    QObject* btnAutoTest=qmlobj->findChild<QObject*>("btnAutoTest");
    if (btnAutoTest){
        btnAutoTest->setProperty("enabled",true);
    }
}

void busComm::btnAutoTestClicked()
{
    int result = 0;
    isFirstIOError=false;
    autoTestThread=new ThreadTask(5);
    connect(autoTestThread,SIGNAL(recvAutoTestStringChanged(QByteArray,int)),this,SLOT(onRecvStringMsg(QByteArray,int)));
    connect(autoTestThread,SIGNAL(recvAutoTestStringChanged(QString)),this,SLOT(onRecvStringMsg(QString)));
    connect(autoTestThread,SIGNAL(threadSendMsg(int,int,QByteArray,int,bool)),this,SLOT(onTheadSendMsg(int,int,QByteArray,int,bool)));
    connect(autoTestThread,SIGNAL(runAutoTestComplete()),this,SLOT(onRunAutoTestComplete()));

    connect(rs232->rs232Thread,SIGNAL(recvRS232Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg(int,QByteArray,int)));
    connect(rs422->rs422Thread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg(int,QByteArray,int)));
    connect(rs422->rs422ManchesterThread,SIGNAL(recvRS422Changed(int,QByteArray,int)),this,SLOT(onRecvStringMsg1(int,QByteArray,int)));
    connect(arinc429->arinc429Thread,SIGNAL(recvArinc429Changed(int,QString,int)),this,SLOT(onRecvStringMsg(int,QString,int)));

    QThreadPool::globalInstance()->start(autoTestThread);

    //    result = rs232->openRS232();
    //    result = rs422->openRS422();
    //    result = arinc429->openArinc429();
    //    result = diocomm->openDIO();

}

//void busComm::RS232RecvMsg(uint8_t fd, QByteArray data,uint16_t length)
//{
//    //QString str = data;
//    //setRecvRS23202(&str);
//    //uint8_t msg_buf[length];
//    //memset(msg_buf,0,length*sizeof(uint8_t));
//    //memcpy(msg_buf,data,length);
//    //emit pThis->recvMsg(3,fd,msg_buf,length);
//    //emit pThis->recvMsg(3,fd,data,length);
//    QQmlApplicationEngine engine;   //QML引擎
//    engine.load(QUrl(QStringLiteral("qrc:/qml/PageRS232.qml")));
//    QObject* root = engine.rootObjects().first();
//    //QString objectName="rs232GroupBox"+QString("%1").arg(fd);
//    QString objectName="rs232GroupBox";
//    QList<QObject *> pctrlobjList = root->findChildren<QObject*>("rs232GroupBox");
//    foreach(QObject * pctrlobj  , pctrlobjList )
//    {
//        QVariant rValue;
//        QString qs(data);
//        QMetaObject::invokeMethod(pctrlobj,  "recvMsg",  Q_RETURN_ARG(QVariant,rValue),  Q_ARG(QVariant, fd),Q_ARG(QVariant, qs),Q_ARG(QVariant, length));
//    }


void busComm::open()
{
    QThreadPool::globalInstance()->setMaxThreadCount(10);
    rs232=rs232Comm::getInstance();
    rs422=rs422Comm::getInstance();
    arinc429=arincComm429::getInstance();
    diocomm=dioComm::getInstance();
    connect(this,SIGNAL(onCloseThread()),rs232,SLOT(onClosed()));
    connect(this,SIGNAL(onCloseThread()),rs422,SLOT(onClosed()));
    connect(this,SIGNAL(onCloseThread()),arinc429,SLOT(onClosed()));
    connect(this,SIGNAL(onCloseThread()),diocomm,SLOT(onClosed()));


    int result = 0;

    //RS232 begin
    result = rs232->openRS232();
    result = rs422->openRS422();
    result = arinc429->openArinc429();
    result = diocomm->openDIO();
    /*
    result = arinc429->openArinc429(fd42901);
    result = arinc429->openArinc429(fd42902);
    result = arinc429->openArinc429(fd42903);
    result = arinc429->openArinc429(fd42904);
    result = arinc429->openArinc429(fd42905);
    result = arinc429->openArinc429(fd42906);*/
}


int busComm::close()
{
    int size = 0;
    char *data;
    int result=-1;
    emit onCloseThread();
    result = rs232->closeRS232();
    result = rs422->closeRS422();
    result = arinc429->closeArinc429();
    result = diocomm->closeDIO();
    m_pTimer->stop();
    return 0;
}






int busComm::pinConfig(int pin,char pinMode)
{
    return 1;
    /*if (pinMode==1)
        //return io_set_outputmode(pin);
    else
        //return io_set_inputmode(pin);
        */
}


int busComm::readDigital(int pin)
{
    return io_out(pin);
}

int busComm::writeDigital(int pin, int value)

{
    //return digital_write(pin, value);
    return -1;
}

int busComm::recvMsgTest(int busType,int recFd, QByteArray data,int length)
{
    LOG_INFO("recvMsgTest %s",data.begin());

    int result = -1;
    switch(busType)
    {
    case 1:
        arinc429->onArinc429RecvMsg(recFd,data,length);
        break;
    case 2:
        rs422->onRS422RecvMsg(recFd,data,length);
        break;
    case 3:
        rs232->onRS232RecvMsg(recFd,data,length);
        break;

    }
    return result;
}

void busComm::onTheadSendMsg(int busType, int fd, QByteArray msgPack, int size, bool checkHexSend)
{
    LOG_INFO("onTheadSendMsg busType=%d size=%d",busType,size);
    sendMsg(busType,  fd,  msgPack,  size,  checkHexSend);
}

int busComm::sendMsg(int busType, int fd, QByteArray msgPack, int size, bool checkHexSend)
{
    //checkHexSend = false
//    LOG_INFO("sendMsg busType=%d size=%d",busType,size);

//    char *s_p = msgPack.begin();
//    char *buf_p=(char *) malloc(sizeof(char)*size);
//    strncpy(buf_p,s_p,size);
//    str_trim(buf_p);

//    int buf_len=strlen(buf_p);
//    int hbuf_len=buf_len/2;

//    char *hbuf_p=(char *) malloc(sizeof(char)*buf_len);
//    memset(hbuf_p,'\0',buf_len);
//    hexs_to_binary(buf_p,buf_len,(uchar_8 *)hbuf_p);

//    LOG_INFO("sendMsg busType=%d size=%d",busType,size);

    int result = -1;
    switch(busType)
    {
    case 1:
        if (checkHexSend)
        {
            QString str=QString(msgPack);
            QByteArray ab=QByteArray::fromHex(str.replace(" ","").toLatin1());
            result=arinc429->sendMsg429(fd,ab,ab.length());
//            LOG_INFO("arinc429 checkHexSend %02x %02x %02x %02x ",*hbuf_p,*(hbuf_p+1),*(hbuf_p+2),*(hbuf_p+3));
        }
        else
        {
            result=arinc429->sendMsg429(fd,msgPack,size);
            LOG_INFO("arinc429 assic size=%d",size);
        }
        break;
    case 2:
        if (checkHexSend)
        {
            QString str=QString(msgPack);
            QByteArray ab=QByteArray::fromHex(str.replace(" ","").toLatin1());
            result=rs422->sendMsg422(fd,ab,ab.length());
        }
        else
        {
            result=rs422->sendMsg422(fd,msgPack,size);
        }
        break;
    case 3:
        if (checkHexSend)
        {
            QString str=QString(msgPack);
            QByteArray ab=QByteArray::fromHex(str.replace(" ","").toLatin1());
            result=rs232->sendMsg232(fd,ab,ab.length());
        }
        else
        {
            result=rs232->sendMsg232(fd,msgPack,size);
        }
        break;

    }

    if (checkHexSend)
    {
        QString str=QString(msgPack);
        QByteArray ab=QByteArray::fromHex(str.replace(" ","").toLatin1());

        LOG_INFO("arinc429 assic size=%d",size);

        recvMsgTest(busType, fd, ab,ab.length());
    }
    else
    {
        LOG_INFO("arinc429 assic size=%d",size);

        recvMsgTest(busType, fd, msgPack, size);
    }

//    delete buf_p;
//    delete hbuf_p;

    return result;
}

