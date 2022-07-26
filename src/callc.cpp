#include <drv_global.h>
#include "callc.h"
#include "uartfunc.h"
#include <QByteArray>
#include <QDebug>

int RS232PORTREADADDRESS[RS232PORTNUM];

int crs232_config(uint32_t fd, uint32_t baudrate, uint32_t bits, uint32_t parity, uint32_t stop)
{
    int result=0;
    result = rs232_close(rs232PortReadAddress[fd-1]);
    result = rs232_close(rs232PortWriteAddress[fd-1]);
    result = rs232_open(rs232PortReadAddress[fd-1]);
    result = rs232_open(rs232PortWriteAddress[fd-1]);
    result=rs232_config(rs232PortReadAddress[fd-1],baudrate, bits, parity, stop);
    result=rs232_config(rs232PortWriteAddress[fd-1],baudrate, bits, parity, stop);
    return result;
}


int crs422_config(uint32_t fd, uint32_t baudrate, uint32_t bits, uint32_t parity, uint32_t stop)
{
    int result=0;
    switch (fd) {
    case 1:
        result = rs422_close(RS422_TX_01);
        result = rs422_close(RS422_RX_01);
        result = rs422_open(RS422_TX_01);
        result = rs422_open(RS422_RX_01);
        result=rs422_config(RS422_TX_01,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_01,baudrate, bits, parity, stop);
        break;
    case 2:
        //dev/ttyUSB%d
        result = rs422_close(RS422_TX_02);
        result = rs422_close(RS422_RX_02);
        result = rs422_open(RS422_TX_02);
        result = rs422_open(RS422_RX_02);
        result=rs422_config(RS422_TX_02,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_02,baudrate, bits, parity, stop);
        break;
    case 3:
        result = rs422_close(RS422_TX_03);
        result = rs422_close(RS422_RX_03);
        result = rs422_open(RS422_TX_03);
        result = rs422_open(RS422_RX_03);
        result=rs422_config(RS422_TX_03,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_03,baudrate, bits, parity, stop);
        break;
    case 4:
        result = rs422_close(RS422_TX_04);
        result = rs422_close(RS422_RX_04);
        result = rs422_open(RS422_TX_04);
        result = rs422_open(RS422_RX_04);
        result=rs422_config(RS422_TX_04,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_04,baudrate, bits, parity, stop);
        break;
    case 5:
        result = rs422_close(RS422_TX_05);
        result = rs422_close(RS422_RX_05);
        result = rs422_open(RS422_TX_05);
        result = rs422_open(RS422_RX_05);
        result=rs422_config(RS422_TX_05,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_05,baudrate, bits, parity, stop);
        break;
    case 6:
        result = rs422_close(RS422_TX_06);
        result = rs422_close(RS422_RX_06);
        result = rs422_open(RS422_TX_06);
        result = rs422_open(RS422_RX_06);
        result=rs422_config(RS422_TX_06,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_06,baudrate, bits, parity, stop);
        break;
    case 7:
        result = rs422_close(RS422_TX_07);
        result = rs422_close(RS422_RX_07);
        result = rs422_open(RS422_TX_07);
        result = rs422_open(RS422_RX_07);
        result=rs422_config(RS422_TX_07,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_07,baudrate, bits, parity, stop);
        break;
    case 8:
        result = rs422_close(RS422_TX_08);
        result = rs422_close(RS422_RX_08);
        result = rs422_open(RS422_TX_08);
        result = rs422_open(RS422_RX_08);
        result=rs422_config(RS422_TX_08,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_08,baudrate, bits, parity, stop);
        break;
    case 9:
        result = rs422_close(RS422_TX_09);
        result = rs422_close(RS422_RX_09);
        result = rs422_open(RS422_TX_09);
        result = rs422_open(RS422_RX_09);
        result=rs422_config(RS422_TX_09,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_09,baudrate, bits, parity, stop);
        break;
    case 10:
        result = rs422_close(RS422_TX_10);
        result = rs422_close(RS422_RX_10);
        result = rs422_open(RS422_TX_10);
        result = rs422_open(RS422_RX_10);
        result=rs422_config(RS422_TX_10,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_10,baudrate, bits, parity, stop);
        break;
    case 11:
        result = rs422_close(RS422_TX_11);
        result = rs422_close(RS422_RX_11);
        result = rs422_open(RS422_TX_11);
        result = rs422_open(RS422_RX_11);
        result=rs422_config(RS422_TX_11,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_11,baudrate, bits, parity, stop);
        break;
    case 12:
        result = rs422_close(RS422_TX_12);
        result = rs422_close(RS422_RX_12);
        result = rs422_open(RS422_TX_12);
        result = rs422_open(RS422_RX_12);
        result=rs422_config(RS422_TX_12,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_12,baudrate, bits, parity, stop);
        break;
    case 13:
        result = rs422_close(RS422_TX_13);
        result = rs422_close(RS422_RX_13);
        result = rs422_open(RS422_TX_13);
        result = rs422_open(RS422_RX_13);
        result=rs422_config(RS422_TX_13,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_13,baudrate, bits, parity, stop);
        break;
    case 14:
        result = rs422_close(RS422_TX_14);
        result = rs422_close(RS422_RX_14);
        result = rs422_open(RS422_TX_14);
        result = rs422_open(RS422_RX_14);
        result=rs422_config(RS422_TX_14,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_14,baudrate, bits, parity, stop);
        break;
    case 15:
        result = rs422_close(RS422_TX_15);
        result = rs422_close(RS422_RX_15);
        result = rs422_open(RS422_TX_15);
        result = rs422_open(RS422_RX_15);
        result=rs422_config(RS422_TX_15,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_15,baudrate, bits, parity, stop);
        break;
    case 16:
        result = rs422_close(RS422_TX_16);
        result = rs422_close(RS422_RX_16);
        result = rs422_open(RS422_TX_16);
        result = rs422_open(RS422_RX_16);
        result=rs422_config(RS422_TX_16,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_16,baudrate, bits, parity, stop);
        break;
    case 17:
        result = rs422_close(RS422_TX_17);
        result = rs422_close(RS422_RX_17);
        result = rs422_open(RS422_TX_17);
        result = rs422_open(RS422_RX_17);
        result=rs422_config(RS422_TX_17,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_17,baudrate, bits, parity, stop);
        break;
    case 18:
        result = rs422_close(RS422_TX_18);
        result = rs422_close(RS422_RX_18);
        result = rs422_open(RS422_TX_18);
        result = rs422_open(RS422_RX_18);
        result=rs422_config(RS422_TX_18,baudrate, bits, parity, stop);
        result=rs422_config(RS422_RX_18,baudrate, bits, parity, stop);
        break;

    }
    return result;

}

int carinc429_config(uint32_t fd, uint32_t baudrate, uint32_t parity, uint32_t encmode)
{
    int result=0;
    switch (fd) {
    case 1:
        result = arinc429_close(ARINC429_TX_01);
        result = arinc429_close(ARINC429_RX_01);
        result = arinc429_open(ARINC429_TX_01);
        result = arinc429_open(ARINC429_RX_01);
        result=arinc429_config(ARINC429_TX_01,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_01,baudrate, parity, encmode);
        break;
    case 2:
        result = arinc429_close(ARINC429_TX_02);
        result = arinc429_close(ARINC429_RX_02);
        result = arinc429_open(ARINC429_TX_02);
        result = arinc429_open(ARINC429_RX_02);
        result=arinc429_config(ARINC429_TX_02,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_02,baudrate, parity, encmode);
        break;
    case 3:
        result = arinc429_close(ARINC429_TX_03);
        result = arinc429_close(ARINC429_RX_03);
        result = arinc429_open(ARINC429_TX_03);
        result = arinc429_open(ARINC429_RX_03);
        result=arinc429_config(ARINC429_TX_03,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_03,baudrate, parity, encmode);
        break;
    case 4:
        result = arinc429_close(ARINC429_TX_04);
        result = arinc429_close(ARINC429_RX_04);
        result = arinc429_open(ARINC429_TX_04);
        result = arinc429_open(ARINC429_RX_04);
        result=arinc429_config(ARINC429_TX_04,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_04,baudrate, parity, encmode);
        break;
    case 5:
        result = arinc429_close(ARINC429_TX_05);
        result = arinc429_close(ARINC429_RX_05);
        result = arinc429_open(ARINC429_TX_05);
        result = arinc429_open(ARINC429_RX_05);
        result=arinc429_config(ARINC429_TX_05,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_05,baudrate, parity, encmode);
        break;
    case 6:
        result = arinc429_close(ARINC429_TX_06);
        result = arinc429_close(ARINC429_RX_06);
        result = arinc429_open(ARINC429_TX_06);
        result = arinc429_open(ARINC429_RX_06);
        result=arinc429_config(ARINC429_TX_06,baudrate, parity, encmode);
        result=arinc429_config(ARINC429_RX_06,baudrate, parity, encmode);


    }
    return result;

}

int cio_read()
{
    int status=(int)io_read();
    qDebug("status1=%x",status);
    return status;
}


int kbhit(void)
{
    struct termios oldt,newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO,&oldt);
    newt = oldt;
    newt.c_lflag &=~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);
    oldf = fcntl(STDIN_FILENO,F_GETFL,0);
    fcntl(STDIN_FILENO,F_SETFL,oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    fcntl(STDIN_FILENO,F_SETFL,oldf);
    if(ch != EOF)
    {
        ungetc(ch,stdin);
        return 1;
    }
    return 0;
}

unsigned char shift_fun2(unsigned char data)
{
    data=(data<<4)|(data>>4);
    data=((data<<2)&0xcc)|((data>>2)&0x33);
    data=((data<<1)&0xaa)|((data>>1)&0x55);
    return data;
}

int lowconvert(QByteArray sourceArray,QByteArray *targetArray)
{
    QByteArray tempArray;
    if (sourceArray.length()>=8)
    {
        //qDebug()<<"in:"<<sourceArray<<"\n";
        tempArray=QByteArray::fromHex(sourceArray);
        for(int i=0;i<tempArray.length()/4;i++)
        {
            tempArray[i*4+3]=shift_fun2(tempArray[i*4+3]);
        }
        *targetArray=tempArray.toHex();
        //qDebug()<<"out:"<<targetArray<<"\n";
    }
    return 0;
}

