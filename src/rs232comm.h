#ifndef RS232COMM_H
#define RS232COMM_H

#include <QObject>
#include <drv_global.h>
#include <QThreadPool>
#include "threadtask.h"
#include "callc.h"
#include <QQuickView>



class rs232Comm : public QObject
{
    Q_OBJECT
public:
    explicit rs232Comm(QObject *parent = nullptr);
    static rs232Comm *getInstance();

    ThreadTask *rs232Thread;
    QObject* qmlObject;

        //获取到qml根对象的指针
    //QObject *qmlObj=view.rootObject();
    bool isSaveFile[rs232PortNum];
    QFile saveFileName[rs232PortNum];

    bool isRS232Open[rs232PortNum];
    QString recvRS232[rs232PortNum];
    long recvBytesRS232[rs232PortNum];
    long sendBytesRS232[rs232PortNum];
    bool hexRS232[rs232PortNum];

    bool enableDisplay[rs232PortNum];
    bool isTimerSend[rs232PortNum];

    bool m_HexRS232[rs232PortNum];

    Q_INVOKABLE void setRecvRS232(const int fd, const QString &recvRS232);
    Q_INVOKABLE void setRecvBytesRS232(const int fd, long recvBytesRS232);
    Q_INVOKABLE void setSendBytesRS232(const int fd,long sendBytesRS232);
    Q_INVOKABLE void saveFileClick(int fd,bool saveFile);

    void appendRecvRS232(int fd,const QString &recvRS232);
    Q_INVOKABLE void setHexRS232(int fd,bool hexRS232);
    int openRS232();
    int closeRS232();

    Q_INVOKABLE int rs232Config(int fd, int baudrate=115200, int bits=8, int parity=0, int stop=0);
    QString GetCorrectUnicode(const QByteArray& ba);
    //void setRS232CallBackFunc(int fd, rx_data_ST cbk);
    int sendMsg232(int fd, QString msgPack, int size,bool isHex);
    //int sendMsg232(int fd, QByteArray msgPack, int size);

signals:

    void recvRS232Changed(const int fd);
    void recvBytesRS232Changed(const int fd);
    void sendBytesRS232Changed(const int fd);
    void hexRS232Changed(const int fd);
    void onCloseThread();

public slots:    
    void onRS232RecvMsg(int fd, QByteArray data,int length);
    void onClosed();

private:
    QString m_recvRS232[rs232PortNum];
    long m_recvBytesRS232[rs232PortNum]={0};
    long m_sendBytesRS232[rs232PortNum]={0};
//    bool hexRs232[rs232PortNum];

    static rs232Comm * pThis;   //静态对象指针
};

#endif // RS232_H
