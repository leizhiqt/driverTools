#include "diocomm.h"
#include <drv_global.h>
#include <QThreadPool>
#include <QtCore>
#include <QDebug>
#include "threadtask.h"
dioComm::dioComm(QObject *parent) : QObject(parent)
{

}

dioComm *dioComm::pThis = 0;
/**
 * @brief
 * @return
 */
dioComm *dioComm::getInstance()
{
    if (!pThis) {
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if (!pThis) {
            pThis = new dioComm;
        }
    }

    return pThis;
}




bool dioComm::directionDIO(int fd)
{
    return m_directionDIO[fd-1];
}


bool dioComm::enableDIO(int fd)
{
    return m_enableDIO[fd-1];
}


void dioComm::setRecvDIO(int fd,bool recvDIO)
{

    if (recvDIO == m_recvDIO[fd-1])
        return;
    if(m_directionDIO[fd-1])
        return;
    m_recvDIO[fd-1]=recvDIO;

    //emit recvRS42210Changed();
    //emit recvBytesRS42210Changed();
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("dioGroupBox");
    if(objList.count()>fd){
        //result = (int)rs422_write(rs232PortReadAddress[fd-1], msg_buf, (uint16_t)size);
        QList<QObject*> btnChannelList=objList[fd-1]->findChildren<QObject*>("btnChannel");
        if (btnChannelList.count()>0){
            QObject* btnChannel= btnChannelList.first();
            if(btnChannel)
            {
                //QString m_sendBytesStr=QString("%1").arg(m_sendBytesRS232[fd-1],3,10,QChar('0'));
                //QString m_recvStr=QString("%1").arg(m_recvDIO[fd-1]);
                btnChannel->setProperty("checked",m_recvDIO[fd-1]);
                //bool bRet=QMetaObject::invokeMethod(btnChannel,"clear");
                //bRet=QMetaObject::invokeMethod(rs232RecvItemTextArea,"append",Q_ARG(QString,m_recvStr));
            }
        }
    }
}


void dioComm::setDirectionDIO(int fd, bool directionDIO)
{
    if (directionDIO ==  m_directionDIO[fd-1])
        return;

    m_recvDIO[fd-1]=directionDIO;

    if (qmlObject->children().count()>0)
    {
        QList<QObject*> objList=qmlObject->findChildren<QObject*>("dioGroupBox");
        if(objList.count()>fd){
            QList<QObject*> comBoxDirectionList=objList[fd-1]->findChildren<QObject*>("comBoxDirection");
            if (comBoxDirectionList.count()>0){
                QObject* comBoxDirection= comBoxDirectionList.first();
                if(comBoxDirection)
                {
                    comBoxDirection->setProperty("checked",m_recvDIO[fd-1]);
                }
            }
        }
    }
}



void dioComm::qmlSetRecvDIO(int fd,bool recvDIO)
{
    m_recvDIO[fd-1] = recvDIO;
    if (m_directionDIO[fd-1])  //out mode
    {
        if (!m_recvDIO[fd-1])
        {
            io_set_outputmode(dioPortAddress[fd-1]);
            io_out_low(dioPortAddress[fd-1]);
        }else
        {
            io_set_outputmode(dioPortAddress[fd-1]);
            io_out_high(dioPortAddress[fd-1]);
        }
    }
}


void dioComm::qmlSetDirectionDIO(int fd,bool directionDIO)
{
    if (directionDIO == m_directionDIO[fd-1])
        return;
    m_directionDIO[fd-1] = directionDIO;
    if (m_directionDIO[fd-1])
        io_set_outputmode(dioPortAddress[fd-1]);
    else
        io_set_inputmode(dioPortAddress[fd-1]);
}



void dioComm::setEnableDIO(int fd,bool enableDIO)
{
    if (enableDIO == m_enableDIO[fd-1])
        return;
    m_enableDIO[fd-1] = enableDIO;
    QList<QObject*> objList=qmlObject->findChildren<QObject*>("dioGroupBox");
    if(objList.count()>fd){
        QList<QObject*> checkEnabelList=objList[fd-1]->findChildren<QObject*>("checkEnabel");
        if (checkEnabelList.count()>0){
            QObject* checkEnabel= checkEnabelList.first();
            if(checkEnabel)
            {
                checkEnabel->setProperty("checked",m_recvDIO[fd-1]);
            }
        }
    }
}


void dioComm::onDIORecvMsg(int fd,bool highLevel)
{
    setRecvDIO(fd,highLevel);
}


void dioComm::onDIODirectionMsg(int fd,bool highLevel)
{
    setDirectionDIO(fd,highLevel);
}


void dioComm::onDIOEnableMsg(int fd,bool highLevel)
{
    setEnableDIO(fd,highLevel);
}


int dioComm::openDIO()
{
    ThreadTask * dioThread;
    dioThread=new ThreadTask(4);
    for(int i=0;i<dioPortNum;i++)
    {
        dioPortAddress[i]=0X0001 << i;
    }
    connect(dioThread,SIGNAL(recvDIOChanged(int,bool)),this,SLOT(onDIORecvMsg(int,bool)));
    connect(dioThread,SIGNAL(directionDIOChanged(int,bool)),this,SLOT(onDIODirectionMsg(int,bool)));
    connect(dioThread,SIGNAL(enableDIOChanged(int,bool)),this,SLOT(onDIOEnableMsg(int,bool)));
    connect(dioThread,SIGNAL(recvDIOLowChanged()),this,SLOT(onDIOLowMsg()));
    connect(this,SIGNAL(onCloseThread()),dioThread,SLOT(onClosed()));
    QThreadPool::globalInstance()->start(dioThread);
    for(int i=0;i<dioPortNum;i++)
    {
        isDIOOpen[i] = true;
        //setDirectionDIO(i+1,true);
        qmlSetRecvDIO(i+1,true);
    }

    return 0;
}

int dioComm::closeDIO()
{
    int result=-1;

    return result;

}

void dioComm::onClosed()
{
    emit onCloseThread();
}

void dioComm::onDIOLowMsg()
{
    for(int i=0;i<dioPortNum;i++)
    {
        if(!m_directionDIO[i])
        {
            if (m_recvDIO[i])
                setRecvDIO(i+1,false);
        }
    }


}
