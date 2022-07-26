#ifndef DIOCOMM_H
#define DIOCOMM_H

#include <QObject>
#include <drv_global.h>
#include <QThreadPool>
#include "callc.h"

class dioComm : public QObject
{
    Q_OBJECT



public:
    explicit dioComm(QObject *parent = nullptr);
    static dioComm *getInstance();

    QObject* qmlObject;
    bool directionDIO(int fd);
    bool enableDIO(int fd);
    void setRecvDIO(int fd, bool recvDIO);

    Q_INVOKABLE void qmlSetRecvDIO(int fd,bool recvDIO01);
    void setDirectionDIO(int fd,bool directionDIO);
    Q_INVOKABLE void qmlSetDirectionDIO(int fd, bool directionDIO);
    Q_INVOKABLE void setEnableDIO(int fd,bool enableDIO);
    bool isDIOOpen[dioPortNum];
    //void setDIOCallBackFunc(int fd, rx_data_ST cbk);
    int sendMsgDIO(int fd, QByteArray msgPack, int size);
    int openDIO();
    int closeDIO();

signals:
    void recvDIOChanged(int fd);
    void enableDIOChanged(int fd);
    void onCloseThread();

public slots:
    void onDIORecvMsg(int fd,bool highLevel);


    void onDIODirectionMsg(int fd,bool highLevel);


    void onDIOEnableMsg(int fd,bool highLevel);

    void onClosed();
    void onDIOLowMsg();

private:
    bool m_recvDIO[dioPortNum]={true};
    bool m_directionDIO[dioPortNum]={true};
    bool m_enableDIO[dioPortNum]={true};

    QThread *dioThread;

    static dioComm * pThis;   //静态对象指针
};

#endif // DIOCOMM_H
