#ifndef THREADTASK_H
#define THREADTASK_H

#include <QObject>
#include <QRunnable>




class ThreadTask : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit ThreadTask(QObject *parent = nullptr);
    ThreadTask(int portType);
    void run();
    void run232();
    void run422();
    void run429();
    void runDIO();
    void runAutoTest();
    void run422Manchester();
    //int fd[4]={0};
    int fdm[4];
signals:
    void threadSendMsg(int busType,int fd, QByteArray msgPack, int size, bool checkHexSend);
    void recvAutoTestStringChanged(QByteArray data,int length);
    void recvAutoTestStringChanged(QString revcString);
    void recvRS232Changed(int fd,QByteArray data,int length);

    void recvRS422Changed(int fd,QByteArray data,int length);

    void recvDIOChanged(int fd,bool highLevel);
    void directionDIOChanged(int fd,bool highLevel);
    void enableDIOChanged(int fd,bool highLevel);

    void runAutoTestComplete();

    void recvDIOLowChanged();

    void recvArinc429Changed(int fd,QString data,int length);

private slots:
    void onClosed();
    void onRecvSend422ManData(int fd,QByteArray data,int length);
    //void setManchesterRate(int fd, int baudrate, int bits, int parity, int stop);
private:
    int m_PortType;
    int m_PortNum;
    bool isCloseThread=false;
    bool send422ManFlag[4]={false};
    QByteArray send422ManData;
};

#endif // THREADTASK_H
