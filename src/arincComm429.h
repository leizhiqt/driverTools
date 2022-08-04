#ifndef ARINC429_H
#define ARINC429_H
#include <QObject>
#include <drv_global.h>
#include "threadtask.h"
#include "callc.h"
#include <QQuickView>


class arincComm429 : public QObject
{
    Q_OBJECT
//    bool hexArinc429[arinc429PortNum];

public:
    explicit arincComm429(QObject *parent = nullptr);
    static arincComm429 *getInstance();
    QObject* qmlObject;
    bool isSaveFile[arinc429PortNum];
    QFile saveFileName[arinc429PortNum];
    ThreadTask *arinc429Thread;
    bool isArinc429Open[arinc429PortNum];
    QString recvArinc429[arinc429PortNum];
    long recvBytesArinc429[arinc429PortNum];
    long sendBytesArinc429[arinc429PortNum];
    bool enableDisplay[arinc429PortNum];
    bool isTimerSend[arinc429PortNum];
    bool hexARINC429[arinc429PortNum];

    Q_INVOKABLE void setRecvArinc429(const int fd, const QString recvArinc429);
    Q_INVOKABLE void setRecvArincComm429(const int fd,const QString &recvArinc429);
    Q_INVOKABLE void setRecvBytesArinc429(const int fd,long recvBytesArinc429);
    Q_INVOKABLE void setSendBytesArinc429(const int fd,int len);
    Q_INVOKABLE void saveFileClick(int fd,bool saveFile);
    Q_INVOKABLE void setDisplayHexArinc429(int fd,bool hexARINC429);

    int openArinc429();
    int closeArinc429();

    QString GetCorrectUnicode(const QByteArray& ba);

    Q_INVOKABLE int arinc429Config(int fd, int baudrate=115200, int parity=0, int encmode=0);
    int sendMsg429(int fd, QByteArray msgPack, int size,bool isHex);

    Q_INVOKABLE void setRecvArincMsg(const int fd,const QString recvArinc429);

signals:
    void recvArinc429Changed(const int fd);
    void recvBytesArinc429Changed(const int fd);
    void sendBytesArinc429Changed(const int fd);
    void hexArinc429Changed(const int fd);
    void onCloseThread();

public slots:
    void onArinc429RecvMsg(const int fd,QString data,int length);
    void onClosed();

private:
    QString m_recvArinc429[arinc429PortNum];
    long m_recvBytesArinc429[arinc429PortNum]={0};
    long m_sendBytesArinc429[arinc429PortNum]={0};
    bool m_HexArinc429[arinc429PortNum]={false};
    static arincComm429 * pThis;   //静态对象指针
};


#endif // ARINC429_H
