#ifndef BUSCOMM_H
#define BUSCOMM_H

#include <QObject>
#include <QTimer>
#include <drv_global.h>
#include "rs232comm.h"
#include "rs422comm.h"
#include "arincComm429.h"
#include "diocomm.h"


class busComm : public QObject
{
    Q_OBJECT

    //Q_PROPERTY    
    Q_PROPERTY(QString recvString READ recvString WRITE setRecvString NOTIFY recvStringChanged);

public:
    explicit busComm(QObject *parent = nullptr);

    static busComm *getInstance();
    ThreadTask *autoTestThread;
    Q_INVOKABLE void open();


    QObject *qmlobj;

    uint32_t HexToDex(QString DataLineData);

    bool enableDisplay=true;

    Q_INVOKABLE int close();

    QString recvString();
    Q_INVOKABLE void setRecvString(const QString &recvString);
    void appendRecvString(const QString &recvString);

    Q_INVOKABLE void btnAutoTestClicked();
    //send msg block
    Q_INVOKABLE int sendMsg(int busType,int fd, QByteArray msgPack, int size, bool checkHexSend);
    int recvMsgTest(int busType,int recFd, QByteArray data,int length);

    // digital read/write
    Q_INVOKABLE int pinConfig(int pin,char pinMode);
    Q_INVOKABLE int writeDigital(int pin, int value);
    Q_INVOKABLE int readDigital(int pin);

public:
    rs232Comm* rs232;
    rs422Comm* rs422;
    arincComm429* arinc429;
    dioComm* diocomm;

public slots:
    void handleTimeout();
    void onRecvStringMsg(int fd,QByteArray data,int length);
    void onRecvStringMsg(QByteArray data,int length);
    void onRecvStringMsg(int fd,QString data,int length);
    void onRecvStringMsg(int fd,QString revcString);
    void onRecvStringMsg(QString revcString);
    void onRecvStringMsg1(int fd,QByteArray data,int length);
    void onTheadSendMsg(int busType,int fd, QByteArray msgPack, int size, bool checkHexSend);
    void onRunAutoTestComplete();

signals:
    //void recvMsg(int busType,int recFd, QByteArray data,uint16_t length);
    //Q_INVOKABLE void recvMsg(int busType,int recFd, QByteArray data,uint16_t length);
    void recvStringChanged();
    void onCloseThread();




private:

    int pin;
    bool isARINC429RecvOpen;
    bool isARINC429Send1Open;
    bool isARINC429Send2Open;

    QTimer* m_pTimer;

    bool isRS422Open;
    bool isRS232Open;
    bool isArinc429Open;

    QString m_recvString;
    QString m_tempString;
    bool isRecvData=false;

    QString autoTestError="";
    bool isFirstIOError=false;

    static busComm * pThis;   //静态对象指针
};

#endif // BUSCOMM_H
