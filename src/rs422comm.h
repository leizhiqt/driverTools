#ifndef RS422COMM_H
#define RS422COMM_H

#include <QObject>
#include <drv_global.h>
#include <QFile>
#include <QTextDecoder>
#include "threadtask.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include "callc.h"

class rs422Comm : public QObject
{
    Q_OBJECT
    bool hexRs422[rs422PortNum];

public:
    explicit rs422Comm(QObject *parent = nullptr);
    static rs422Comm *getInstance();

    ThreadTask *rs422Thread;
    ThreadTask *rs422ManchesterThread;
    QObject* qmlObject;

  QSerialPort serial_port;

    bool isSaveFile[rs422PortNum];
    QFile saveFileName[rs422PortNum];
    bool isRS422Open[rs422PortNum];

    bool is_open_serailport = false;
    QString recvRS422[rs422PortNum];
    long recvBytesRS422[rs422PortNum];
    long sendBytesRS422[rs422PortNum];
    bool hexRS422[rs422PortNum];

    bool enableDisplay[rs422PortNum];
    bool isTimerSend[rs422PortNum];

    Q_INVOKABLE void setRecvRS422(const int fd, const QString &recvRS422);
    Q_INVOKABLE void setRecvBytesRS422(const int fd, long recvBytesRS422);
    Q_INVOKABLE void setSendBytesRS422(const int fd,long sendBytesRS422);
    Q_INVOKABLE void setHexRS422(int fd,bool hexRS422);
    Q_INVOKABLE void saveFileClick(int fd,bool saveFile);





    void appendRecvRS422(int fd,const QString &recvRS422);



    int openRS422();
    int closeRS422();

    Q_INVOKABLE int rs422Config(int fd, int baudrate=115200, int bits=8, int parity=0, int stop=1);
    QString GetCorrectUnicode(const QByteArray& ba);

    int sendMsg422(int fd, QByteArray msgPack, int size);
    //int sendMsg422(int fd, QString msgPack, int size);


signals:
    void recvRS422Changed(const int fd);
    void recvBytesRS422Changed(const int fd);
    void sendBytesRS422Changed(const int fd);
    void hexRS422Changed(const int fd);
    void onCloseThread();
    void send422ManData(int fd, QByteArray data,int length);
public slots:
    void onRS422RecvMsg(int fd,QByteArray data,int length);
    void onClosed();
  // void reciveSerialData();
    void onRecv422ManPara(int* fdmPara);


private:
    QString m_recvRS422[rs422PortNum];
    long m_recvBytesRS422[rs422PortNum]={0};
    long m_sendBytesRS422[rs422PortNum]={0};
    bool m_HexRS422[rs422PortNum]={true};

    QTextDecoder *decoder;
    int fdm[4];

    static rs422Comm * pThis;   //静态对象指针
};

#endif // RS422_H
