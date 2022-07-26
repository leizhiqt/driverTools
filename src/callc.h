#ifndef CALLC_H
#define CALLC_H
#include <QTypeInfo>

int cio_read();
int crs232_config(uint32_t fd, uint32_t baudrate=115200, uint32_t bits=3, uint32_t parity=0, uint32_t stop=0);
int crs422_config(uint32_t fd, uint32_t baudrate=115200, uint32_t bits=3, uint32_t parity=0, uint32_t stop=1);
int carinc429_config(uint32_t fd, uint32_t baudrate=115200, uint32_t parity=0, uint32_t encmode=0);
int kbhit(void);
int lowconvert(QByteArray sourceArray,QByteArray *targetArray);
unsigned char shift_fun2(unsigned char data);

#define RS232PORTNUM 14
extern int RS232PORTREADADDRESS[RS232PORTNUM];

static const int rs232PortNum=14;
static int rs232PortReadAddress[rs232PortNum];
static int rs232PortWriteAddress[rs232PortNum];

static const int rs422PortNum=18;
static int rs422PortReadAddress[rs422PortNum];
static int rs422PortWriteAddress[rs422PortNum];

static const int arinc429PortNum=8;
static int arinc429PortReadAddress[arinc429PortNum];
static int arinc429PortWriteAddress[arinc429PortNum];

static const int dioPortNum=25;
static int dioPortAddress[dioPortNum];
static int dioPortWriteAddress[dioPortNum];
#endif
