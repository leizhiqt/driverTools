#include "threadtask.h"
#include <drv_global.h>
#include <QThread>
#include <QDebug>
#include "callc.h"
#include "bclog.h"

#include "uartfunc.h"
pthread_mutex_t mutex;

ThreadTask::ThreadTask(QObject *parent) : QObject(parent)
{

}
ThreadTask::ThreadTask(int portType)
{
    m_PortType=portType;
}

void ThreadTask::runAutoTest()
{
    qDebug()<< "AutoTest Thread Begin!";
    int result=0;
    emit recvAutoTestStringChanged("一键测试开始<br><br>");
    QString sendString="Send RS23201 Test";
    QByteArray data=sendString.toLatin1();

    for(int i=0;i<rs232PortNum;i++)
    {

       sendString=QString("Send RS232_%1 Test").arg(i+1);
       emit recvAutoTestStringChanged(QString("测试RS232通道%1,发送:").arg(i+1)+sendString);
       data=sendString.toLatin1();
       emit threadSendMsg(3,i+1,data,data.length(),true);
       result = (int)rs232_write(rs232PortWriteAddress[i], data, data.length());
       emit recvAutoTestStringChanged(QString("<br>RS232通道%1,接收:").arg(i+1)+sendString);
       QThread::msleep(50);
       emit recvAutoTestStringChanged("<br><br>");
    }

    for(int i=0;i<rs422PortNum;i++)
    {
        sendString=QString("Send RS422_%1 Test").arg(i+1);
        emit recvAutoTestStringChanged(QString("测试RS422通道%1,发送:").arg(i+1)+sendString);
        data=sendString.toLatin1();
        emit threadSendMsg(2,i+1,data,data.length(),true);
        result = (int)rs422_write(rs422PortWriteAddress[i], data, data.length());
        emit recvAutoTestStringChanged(QString("<br>RS422通道%1,接收:").arg(i+1)+sendString);
        QThread::msleep(50);
        emit recvAutoTestStringChanged("<br><br>");
        if(i==0 || i==2 || i==4 )
            i++;
    }

    for(int i=0;i<4;i++)
    {
        sendString="5a a5 a9 9a 02 00 00 01 00 01 00 02 00 03 00 04 00 05 00 06 00 07 00 08 00 09 00 0a 00 0b 00 0c 00 0d 00 0e 00 0f 00 10 00 11 00 12 00 13 00 14 00 15 00 16 00 17 00 18 00 19 00 1a 00 1b 00 1c 00 1d 00 1e 00 1f 00 20 00 21 00 22 00 23 00 24 00 25 00 26 00 27 00 28 00 29 00 2a 00 2b 00 2c 00 2d 00 2e 00 2f 00 30 00 31 00 32 00 33 00 34 00 35 00 36 00 37 00 38 00 39 00 3a 00 3b 00 3c 00 3d 00 3e 00 3f 00 40 00 41 00 42 00 43 00 44 00 45 00 46 00 47 00 48 00 49 00 4a 00 4b 00 4c 00 4d 00 4e 00 4f 00 50 00 51 00 52 00 53 00 54 00 55 00 56 00 57 00 58 00 59 00 5a 00 5b 00 5c 00 5d 00 5e 00 5f 00 60 00 61 00 62 00 63 00 64 00 65 00 66 00 67 00 68 00 69 00 6a 00 6b 00 6c 00 6d 00 6e 00 6f 00 70 00 71 00 72 00 73 00 74 00 75 00 76 00 77 00 78 00 79 00 7a 00 7b 00 7c 00 7d 00 7e 00 7f 00 80 00 81 00 82 00 83 00 84 00 85 00 86 00 87 00 88 00 89 00 8a 00 8b 00 8c 00 8d 00 8e 00 8f 00 90 00 91 00 92 00 93 00 94 00 95 00 96 00 97 00 98 00 99 00 9a 00 9b 00 9c 00 9d 00 9e 00 9f 00 a0 00 a1 00 a2 00 a3 00 a4 00 a5 00 a6 00 a7 00 a8 00 a9 00 aa 00 ab 00 ac 00 ad 00 ae 00 af 00 b0 00 b1 00 b2 00 b3 00 b4 00 b5 00 b6 00 b7 00 b8 00 b9 00 ba 00 bb 00 bc 00 bd 00 be 00 bf 00 c0 00 c1 00 c2 00 c3 00 c4 00 c5 00 c6 00 c7 00 c8 00 c9 00 ca 00 cb 00 cc 00 cd 00 ce 00 cf 00 d0 00 d1 00 d2 00 d3 00 d4 00 d5 00 d6 00 d7 00 d8 00 d9 00 da 00 db 00 dc 00 dd 00 de 00 df 00 e0 00 e1 00 e2 00 e3 00 e4 00 e5 00 e6 00 e7 00 e8 00 e9 00 ea 00 eb 00 ec 00 ed 00 ee 00 ef 00 f0 00 f1 00 f2 00 f3 00 f4 00 f5 00 f6 00 f7 00 f8 00 f9 00 fa 11 22 33 44";
        emit recvAutoTestStringChanged(QString("测试RS422通道%1,发送:").arg(i*2+2)+sendString);
        data=sendString.toLatin1();
        emit threadSendMsg(2,i*2+2,data,data.length(),true);
        result = (int)rs422_write(rs422PortWriteAddress[i*2+2], data, data.length());
        emit recvAutoTestStringChanged(QString("<br>RS422通道%1,接收:").arg(i*2+2)+sendString);
        QThread::msleep(180);
        emit recvAutoTestStringChanged("<br><br>");
    }

    for(int i=0;i<arinc429PortNum;i++)//arinc429PortNum
    {
        sendString="12345678";
        sendString="41 41 35 35 35 41 30 31";
        emit recvAutoTestStringChanged(QString("测试Arinc429通道%1,发送:").arg(i+1)+sendString);

        data=sendString.toLatin1();
        emit threadSendMsg(1,i+1,data,data.length(),true);

        emit recvAutoTestStringChanged(QString("测试Arinc429通道%1,接收:").arg(i+1)+sendString);
        QThread::msleep(50);
        emit recvAutoTestStringChanged("<br><br>");
    }

    uint32_t status;
    bool isPass=false;
    for(int i=0;i<dioPortNum;i++)
    {
        isPass=false;
        emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输出模式，并输出高电平").arg(i+1));
        io_set_inputmode(0xFFFFFFFF);
        io_set_outputmode(dioPortAddress[i]);
        io_out_high(dioPortAddress[i]);
        QThread::QThread::msleep(50);
        status=io_read();
        qDebug("status=%x",status);
        uint16_t flag=0;
        uint16_t flag1=0;

        LOG_INFO("%d",flag);

        if (i!=0)
            flag=(((uint16_t)0x01) << i);
        if (i<7)
            flag1=(((uint16_t)0x01) << i+7);
        else
            flag1=(((uint16_t)0x01) << i-7);
        LOG_INFO("flag=%x",flag);
        LOG_INFO("flag1=%x",flag1);

        if (status==flag)
        {
            emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输入模式，并输出高电平<br>").arg(i+8));
            isPass=true;
        }
        else{
            emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输入模式，并输出低电平<br>").arg(i-8));
            isPass=false;
        }
        emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输出模式，并输出低电平").arg(i+1));
        io_set_inputmode(0xFFFFFFFF);
        io_set_outputmode(dioPortAddress[i]);
        io_out_low(dioPortAddress[i]);
        QThread::QThread::msleep(50);
        status=io_read();
        qDebug("status=%x",status);
        if (status==flag1)
        {
            emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输入模式，并输出低电平<br>").arg(i+8));
            if (isPass)
                emit recvAutoTestStringChanged("回环测试通过!<br>");
        }
        else{
            emit recvAutoTestStringChanged(QString("<br>设置IO_%1为输入模式，并输出高电平<br>").arg(i-8));
            isPass=false;
        }
        if (!isPass)
        {
            emit recvAutoTestStringChanged(QString("<font color=\"#FF00FF\">IO_%1回环测试未通过!</font><br>").arg(i+1));
        }
    }

    isPass=false;
    emit recvAutoTestStringChanged("<br>设置IO_15为输出模式，并输出高电平");
    io_set_inputmode(0xFFFFFFFF);
    io_set_outputmode(IO_15);
    io_out_high(IO_15);
    QThread::QThread::msleep(50);
    status=io_read();
    qDebug("status=%x",status);
    if (status==0x00)
    {
        emit recvAutoTestStringChanged("<br>设置IO_16为输入模式，并输出高电平<br>");
        isPass=true;
    }
    else{
        emit recvAutoTestStringChanged("<br>设置IO_16为输入模式，并输出低电平<br>");
        isPass=false;
    }
    emit recvAutoTestStringChanged("<br>设置IO_15为输出模式，并输出低电平");
    io_set_inputmode(0xFFFFFFFF);
    io_set_outputmode(IO_15);
    io_out_low(IO_15);
    QThread::QThread::msleep(50);
    status=io_read();
    qDebug("status=%x",status);
    if (status==0x80)
    {
        emit recvAutoTestStringChanged("<br>设置IO_16为输入模式，并输出低电平<br>");
        if (isPass)
            emit recvAutoTestStringChanged("回环测试通过!<br>");
    }
    else{
        emit recvAutoTestStringChanged("<br>设置IO_16为输入模式，并输出高电平<br>");
        isPass=false;
    }
    if (!isPass)
        emit recvAutoTestStringChanged("<font color=\"#FF00FF\">IO_15回环测试未通过!</font><br>");


    isPass=false;
    emit recvAutoTestStringChanged("<br>设置IO_16为输出模式，并输出高电平");
    io_set_inputmode(0xFFFFFFFF);
    io_set_outputmode(IO_16);
    io_out_high(IO_16);
    QThread::QThread::msleep(50);
    status=io_read();
    qDebug("status=%x",status);
    if (status==0x00)
    {
        emit recvAutoTestStringChanged("<br>设置IO_15为输入模式，并输出高电平<br>");
        isPass=true;
    }
    else{
        emit recvAutoTestStringChanged("<br>设置IO_15为输入模式，并输出低电平<br>");
        isPass=false;
    }
    emit recvAutoTestStringChanged("<br>设置IO_16为输出模式，并输出低电平");
    io_set_inputmode(0xFFFFFFFF);
    io_set_outputmode(IO_16);
    io_out_low(IO_16);
    QThread::QThread::msleep(50);
    status=io_read();
    qDebug("status=%x",status);
    if (status==0x4000)
    {
        emit recvAutoTestStringChanged("<br>设置IO_15为输入模式，并输出低电平<br>");
        if (isPass)
            emit recvAutoTestStringChanged("回环测试通过!<br>");
    }
    else{
        emit recvAutoTestStringChanged("<br>设置IO_15为输入模式，并输出高电平<br>");
        isPass=false;
    }
    if (!isPass)
        emit recvAutoTestStringChanged("<font color=\"#FF00FF\">IO_16回环测试未通过!</font><br>");
    for(int i=0;i<dioPortNum;i++)
    {
        io_set_outputmode(dioPortAddress[i]);
        io_out_high(dioPortAddress[i]);
    }

    emit recvAutoTestStringChanged("测试完毕<br><br>");

    qDebug()<< "AutoTest Thread Close!";
    emit runAutoTestComplete();
}

void ThreadTask::runDIO()
{
    int length=2048;
    uint32_t msg_buf[length];
    char msg_buf1[length];
    int dataLength;
    qDebug()<< "DIO Thread Begin!";
    QString returnString="";
    uint32_t status;
    while(!isCloseThread)
    {
        uint16_t flag=0;
        status=io_read();
        if (status==0x00)
            emit recvDIOLowChanged();
        for(int i=0;i<dioPortNum;i++)
        {
            flag=(((uint16_t)0x01) << i);
            if (status & flag)
                emit recvDIOChanged(1+1,false);
            else
                emit recvDIOChanged(1+1,true);
        }
        QThread::msleep(100);
    }
    qDebug()<< "DIO Thread Closed!";

}

void ThreadTask::run429()
{
    int length=512;
    uint32_t msg_buf[length];
    char msg_buf1[length*4];
    int dataLength;
    qDebug()<< "429 Thread Begin!";
    QString returnString="";
    while(!isCloseThread)
    {
        for(int i=0;i<arinc429PortNum;i++)
        {
            memset(msg_buf,0,length*sizeof(uint32_t));
            //memset(msg_buf1,0,length*4*sizeof(uint8_t));
            dataLength=arinc429_read_buffer_size(ARINC429_RX_01);
            returnString="";
            if (dataLength>0)
            {
                if (dataLength>length)
                {
                    arinc429_read(arinc429PortReadAddress[i],msg_buf,length);
                    //memcpy(msg_buf1,msg_buf,length*4);
                    for(int i=0;i<length;i++)
                    {
                        //QByteArray tempArray=QString::number(msg_buf[i],16).toLatin1();
                        QByteArray tempArray=QString("%1").arg(msg_buf[i],8,16,QChar('0')).toLatin1();
                        lowconvert(tempArray,&tempArray);
                        returnString=returnString+""+tempArray;
                    }
                    QString spacString="";
                    for(int i=0;i<returnString.length()/2;i++)
                        spacString=spacString+returnString.mid(i*2,2)+" ";
                    returnString=spacString;
                    emit recvArinc429Changed(i+1,returnString,returnString.length());
                    //emit recvArinc42901Changed(msg_buf1,length*4);
                }
                else
                {
                    arinc429_read(arinc429PortReadAddress[i],msg_buf,dataLength);
                    //memcpy(msg_buf1,msg_buf,dataLength*4);
                    for(int i=0;i<dataLength;i++)
                    {
                        //QByteArray tempArray=QString::number(msg_buf[i],16).toLatin1();
                        QByteArray tempArray=QString("%1").arg(msg_buf[i],8,16,QChar('0')).toLatin1();
                        lowconvert(tempArray,&tempArray);
                        returnString=returnString+""+tempArray;
                    }
                    QString spacString="";
                    for(int i=0;i<returnString.length()/2;i++)
                        spacString=spacString+returnString.mid(i*2,2)+" ";
                    returnString=spacString;

                    emit recvArinc429Changed(i+1,returnString,returnString.length());
                    //emit recvArinc42901Changed(msg_buf1,dataLength*4);
                }

            }
        }
        usleep(20000);
        //QThread::msleep(2);
    }
    qDebug()<< "429 Thread Closed!";
}

void ThreadTask::run232()
{

    int length=2048;
    uint8_t msg_buf[length];
    int dataLength;
    qDebug()<< "232 Thread Begin!";
    while(!isCloseThread)
    {
        for(int i=0;i<rs232PortNum;i++)
        {
            memset(msg_buf,0,length*sizeof(uint8_t));
            dataLength=rs232_read_buffer_size(rs232PortReadAddress[i]);
            if (dataLength>0)
            {
                if (dataLength>length)
                {
                    rs232_read(rs232PortReadAddress[i],msg_buf,length);
                    QByteArray byteArray((char*)msg_buf,length);
                    emit recvRS232Changed(i+1,byteArray,length);
                }
                else
                {
                    rs232_read(rs232PortReadAddress[i],msg_buf,dataLength);
                    QByteArray byteArray((char*)msg_buf,dataLength);
                    emit recvRS232Changed(i+1,byteArray,dataLength);
                }
            }
        }

        usleep(20000);
        //QThread::msleep(2);
    }

    qDebug()<< "232 Thread Closed!";
}

void ThreadTask::run422()
{
    int length=2048;
    uint8_t msg_buf[length];
    int dataLength;
    qDebug()<< "422 Thread Begin!";
    while(!isCloseThread)
    {

        for(int i=0;i<rs422PortNum;i++)
        {
            memset(msg_buf,0,length*sizeof(uint8_t));
            dataLength=rs422_read_buffer_size(rs422PortReadAddress[i]);
            if (dataLength>0)
            {
                if (dataLength>length)
                {
                    rs422_read(rs422PortReadAddress[i],msg_buf,length);
                    QByteArray byteArray((char*)msg_buf,length);
                    emit recvRS422Changed(i+1,byteArray,length);
                }
                else
                {
                    rs422_read(rs422PortReadAddress[i],msg_buf,dataLength);
                    QByteArray byteArray((char*)msg_buf,dataLength);
                    emit recvRS422Changed(i+1,byteArray,dataLength);
                }
            }
        }
        usleep(20000);
    }
    qDebug()<< "422 Thread Closed!";
}

void ThreadTask::onRecvSend422ManData(int fd,QByteArray data,int length)
{
    send422ManFlag[(fd-1)/2]=true;
    send422ManData=data;
}

/*void setManchesterRate(int fd, int baudrate, int bits, int parity, int stop)
{

}*/
void ThreadTask::run422Manchester()
{
    char ch[64]={0};
    int i=0,j=0;
    unsigned char buf[512]={0};
    unsigned char rbuf[512]={0};
    int ret=-1;
    unsigned int nLen;
    int flag=0,r[4]={0},t=0;
    fdm[4]={0};
    qDebug()<< "422Manchester Thread Begin!";
    for(i=0;i<4;i++)
    {
        sprintf(ch,"/dev/ttyUSB%d",i);
        fdm[i] = open_port(ch);
        if(fdm[i] == -1)
            continue;

        set_opt(fdm[i],8,'N', 1);
        set_speci_baud(fdm[i], 1000000);
    }

    if(fdm[0] != -1)
    {
        Cmd_Reset(fdm[0]);
        usleep(1000*200);
    }

    buf[0] = 0x5A;
    buf[1] = 0xA5;
    buf[2] = 0xA9;
    buf[3] = 0x9A;
    for(i=0;i<508;i++)
        buf[i+4] = i;


    int length=512;
    char msg_buf1[length];
    //emit setManPara(fdm);
    while( !isCloseThread)
    {
        for(i=0;i<4;i++)
        {
            if(fdm[i] == -1)
                continue;

            flag=0;
            memset(rbuf,0,512);
            //read data
            ret = Cmd_Read(fdm[i],i,rbuf);
            if(ret == 512)
            {
                memset(msg_buf1,0,length*sizeof(char));
                memcpy(msg_buf1,rbuf,length);
                QByteArray byteArray(msg_buf1,length);
                switch (i) {

                case 0:
                    emit recvRS422Changed(2,byteArray,length);
                    break;
                case 1:
                    emit recvRS422Changed(4,byteArray,length);
                    break;
                case 2:
                    emit recvRS422Changed(6,byteArray,length);
                    break;
                case 3:
                    emit recvRS422Changed(8,byteArray,length);
                    break;

                }

                /*for(j=0;j<512;j++)
                {
                    printf("CH[%d][%d]=%02X\n",i,j,rbuf[j]);
                }*/
            }//if(ret == 512)
            //check send data
            if (send422ManFlag[i])
            {
                //usleep(10000);
                unsigned char buf422man[512];
                memcpy(buf422man, send422ManData.data(),512);
                send_data(fdm[i],buf422man,512);
                send422ManFlag[i]=false;
            }
        }//for(i=0;i<4;i++)

        usleep(20000);
    } //while(!kbhit())

    for(i=0;i<4;i++)
    {
        close_port(fdm[i]);
        fdm[i] = -1;
    }
    qDebug()<< "422Manchester Thread Closed!";
    return ;
}


void ThreadTask::run()
{

    switch (m_PortType) {
    case 1:
        run429();
        break;
    case 2:
        run422();
        break;
    case 3:
        run232();
        break;
    case 4:
        runDIO();
        break;
    case 5:
        runAutoTest();
        break;
    case 6:
        run422Manchester();
        break;
    default:
        break;
    }

}

void ThreadTask::onClosed()
{
    isCloseThread=true;
}
