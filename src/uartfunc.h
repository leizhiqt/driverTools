#ifndef __UARTFUNC_H_
#define __UARTFUNC_H_

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>
#include <termios.h> 
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <linux/serial.h>
#include <sys/ioctl.h>

int open_port(char *dev);
int close_port(int fd);
int set_speed(int fd, int speed);
int set_speci_baud(int fd, int baud);
int set_opt(int fd,int nBits, char parity, int nStop);
int set_optEx(int fd,int nSpeed, int nBits, char parity, int nStop);
int send_data (int fd, unsigned char buf[],int buf_size);
int recv_date(int fd,unsigned char *recv_buf,int buf_size);

int Cmd_Reset(int fd);
int Cmd_Query(int fd,unsigned char Ch,unsigned int *nLen);
int Cmd_Read(int fd,unsigned char Ch,unsigned char *rbuf);
int seek_align(int fd,unsigned char reset);

#endif
