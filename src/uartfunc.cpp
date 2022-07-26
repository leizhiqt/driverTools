
#include "uartfunc.h"

static int speed_arr[] = {B230400, B115200, B57600, B38400, 
		B19200, B9600, B4800, B2400, B1800, B1200, B600, B300};
static int name_arr[]  = {230400,  115200,  57600,  38400,  
		19200,  9600,  4800,  2400,  1800,  1200,  600,  300};

int open_port(char *dev)
{
	int fd =-1;
	fd = open( dev, O_RDWR|O_NOCTTY); //open("/dev/tttyS0",O_RDWR | O_NOCTTY);  //O_NDELAY
	if (-1 == fd)
	{
		printf("Can't Open Serial Port: %s \r\n", dev);
		return(-1);
	}
	
  if(fcntl(fd, F_SETFL, 0)<0)        // if(fcntl(fd, F_SETFL, FNDELAY)<0) 
  {
      printf("fcntl failed!\n");
  }
 
  if(isatty(STDIN_FILENO)==0)
  {
      printf("standard input is not a terminal device\n");
  }
 
  return fd;
}


int close_port(int fd)
{
	 return close(fd);
}


int set_speed(int fd, int speed)
{ 
	int32_t i;   
	int32_t status;   
	struct termios Opt; 
	
	tcgetattr(fd, &Opt);   
	
	for ( i= 0; i < sizeof(speed_arr) / sizeof(int32_t); i++)
	{   
		if (speed == name_arr[i]) 
		{   
			tcflush(fd, TCIOFLUSH);   
			cfsetispeed(&Opt, speed_arr[i]);   
			cfsetospeed(&Opt, speed_arr[i]);  
			
			status = tcsetattr(fd, TCSANOW, &Opt);   
			if (status != 0) 
			{   
				perror("tcsetattr fd1");   
				return -1;
			}  
			
			tcflush(fd,TCIOFLUSH);  
			return 0;
		}  
    } 
	
   return 0;
}

int set_speci_baud(int fd, int baud)
{
	struct serial_struct ss_get, ss_set;
	int ret = 0;
	int i=0;
	for(i=0;i<2;i++)
	{
		if(0 != set_speed(fd,38400))
			printf("BAUT: error to set the serial base38400 info");

		if (ioctl(fd, TIOCGSERIAL, &ss_get) < 0) {
			printf("BAUT: error to get the serial_struct info:%s!\n", strerror(errno));
			return ret;
		}
		ss_get.flags = ASYNC_SPD_CUST;
		ss_get.custom_divisor = ss_get.baud_base/baud;
		//printf("ss_get.custom_divisor = %d!\n", ss_get.custom_divisor);
		if (ioctl(fd, TIOCSSERIAL, &ss_get) < 0) {
			printf("BAUT: error to set the serial_struct info:%s!\n",strerror(errno));
			return ret;
		}

		ioctl(fd, TIOCGSERIAL, &ss_set);	
	}

	//printf("BAUT: success set the serial_struct info:[%d][%d]!\n", ss_set.custom_divisor, ss_set.baud_base);
	return ret;
}


int set_opt(int fd,int nBits, char parity, int nStop)
{
    struct termios newtio,oldtio;
    if  ( tcgetattr( fd,&oldtio)  !=  0)
    {
        perror("SetupSerial 1");
        return -1;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag  |=  CLOCAL | CREAD;
    
    newtio.c_cflag &= ~CSIZE;
    switch( nBits )
    {
    case 5:
        newtio.c_cflag |= CS5;
        break;
    case 6:
        newtio.c_cflag |= CS6;
        break;
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    }
	
    switch( parity )
    {
    case 'o':  
    case 'O':                     //奇校验
        newtio.c_cflag |= PARENB;   //parity enable
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= INPCK ;
        break;
    case 'e':
    case 'E':                     //偶校验
        newtio.c_iflag |= INPCK;
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'n': 
    case 'N':                    //无校验
        newtio.c_cflag &= ~PARENB;
        newtio.c_iflag &= ~INPCK;
        break;
    default:                   //无校验          
    	  newtio.c_cflag &= ~PARENB;
        newtio.c_iflag &= ~INPCK;
        break;
    }

    if( nStop == 1 )
    {
        newtio.c_cflag &=  ~CSTOPB;
    }
    else if ( nStop == 2 )
    {
        newtio.c_cflag |=  CSTOPB;
    }
    newtio.c_cc[VTIME]  = 0; 
    newtio.c_cc[VMIN] = 0;
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        return -1;
    }
   
    return 0;
}



int set_optEx(int fd,int nSpeed, int nBits, char parity, int nStop)
{
    struct termios newtio,oldtio;
    if  ( tcgetattr( fd,&oldtio)  !=  0)
    {
        perror("SetupSerial 1");
        return -1;
    }
    bzero( &newtio, sizeof( newtio ) );
    newtio.c_cflag  |=  CLOCAL | CREAD;
    
    newtio.c_cflag &= ~CSIZE;
    switch( nBits )
    {
    case 5:
        newtio.c_cflag |= CS5;
        break;
    case 6:
        newtio.c_cflag |= CS6;
        break;
    case 7:
        newtio.c_cflag |= CS7;
        break;
    case 8:
        newtio.c_cflag |= CS8;
        break;
    }
	
		
    switch( parity )
    {
    case 'o':  
    case 'O':                     //奇校验
        newtio.c_cflag |= PARENB;   //parity enable
        newtio.c_cflag |= PARODD;
        newtio.c_iflag |= INPCK ;
        break;
    case 'e':
    case 'E':                     //偶校验
        newtio.c_iflag |= INPCK;
        newtio.c_cflag |= PARENB;
        newtio.c_cflag &= ~PARODD;
        break;
    case 'n': 
    case 'N':                    //无校验
        newtio.c_cflag &= ~PARENB;
        newtio.c_iflag &= ~INPCK;
        break;
    default:                   //无校验          
    	  newtio.c_cflag &= ~PARENB;
        newtio.c_iflag &= ~INPCK;
        break;
    }

   switch( nSpeed )
    {
    case 300:
        cfsetispeed(&newtio, B300);
        cfsetospeed(&newtio, B300);
        break;
    case 600:
        cfsetispeed(&newtio, B600);
        cfsetospeed(&newtio, B600);
        break;
    case 1200:
        cfsetispeed(&newtio, B1200);
        cfsetospeed(&newtio, B1200);
        break;
    case 2400:
        cfsetispeed(&newtio, B2400);
        cfsetospeed(&newtio, B2400);
        break;
    case 4800:
        cfsetispeed(&newtio, B4800);
        cfsetospeed(&newtio, B4800);
        break;
    case 9600:
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
     case 19200:
        cfsetispeed(&newtio, B19200);
        cfsetospeed(&newtio, B19200);
        break;
     case 38400:
        cfsetispeed(&newtio, B38400);
        cfsetospeed(&newtio, B38400);
        break;
     case 57600:
        cfsetispeed(&newtio, B57600);
        cfsetospeed(&newtio, B57600);
        break;
    case 115200:
        cfsetispeed(&newtio, B115200);
        cfsetospeed(&newtio, B115200);
        break;
    default:
        //printf("sorry! [%d bps] is not support ,Set default 9600bps now!\n",nSpeed);
        cfsetispeed(&newtio, B9600);
        cfsetospeed(&newtio, B9600);
        break;
    }
    
    if( nStop == 1 )
    {
        newtio.c_cflag &=  ~CSTOPB;
    }
    else if ( nStop == 2 )
    {
        newtio.c_cflag |=  CSTOPB;
    }
    newtio.c_cc[VTIME]  = 0;  //150
    newtio.c_cc[VMIN] = 0;
    tcflush(fd,TCIFLUSH);
    if((tcsetattr(fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    //printf("set done!\n");
    return 0;
}


int send_data (int fd, unsigned char buf[],int buf_size)
{
	return write(fd, buf, buf_size);
}

int recv_date(int fd,unsigned char *recv_buf,int buf_size)
{
	return read(fd, recv_buf, buf_size);	
}


int Cmd_Reset(int fd)
{
	int ret =-1;
	unsigned char ucData[4]={0};
	ucData[0] = 0x00;
	ucData[1] = 0x02;
	ucData[2] = 0x00;
	ucData[3] = 0x00;
	ret =send_data (fd,ucData,4);
	return ret;
}

int Cmd_Query(int fd,unsigned char Ch,unsigned int *nLen)
{
	int len=0;
	int ret =-1;
	unsigned char ucData[6]={0};
	ucData[0] = 0x00;
	ucData[1] = 0x02;
	ucData[2] = 0x02;
	ucData[3] = Ch;
	send_data (fd,ucData,4);

	*nLen = 0;
	while(len<6)
	{
	     if(-1 == ioctl(fd, FIONREAD, &len))
		 return -1;
	}
	
	ret =recv_date(fd,ucData,6);
	//printf("len[%d][%x][%x]\n",ret,ucData[4],ucData[5]);
	if(ret == 6)
	{
	    *nLen = (ucData[4]<<8) | ucData[5];
	}	
	return ret;
}

int Cmd_Read(int fd,unsigned char Ch,unsigned char *rbuf)
{
	int len=0;
	int ret =-1;
	unsigned char ucData[6]={0};
	ucData[0] = 0x00;
	ucData[1] = 0x02;
	ucData[2] = 0x03;
	ucData[3] = Ch;
	send_data (fd,ucData,4);
	
	//ret = ioctl(fd, FIONREAD, &len);
	//while(len<512)
	//{
	     if(-1 == ioctl(fd, FIONREAD, &len))
		 return -1;
	//}

	if(len<512)
	{
	    //printf("len[%d]\n",len);
	    return 0;      	
	}

	ret =recv_date(fd,rbuf,512);	
	return ret;
}

int seek_align(int fd,unsigned char reset)
{
	int ret = 0;
	int i = 0;
	unsigned char ucData[7]={0};
	memset(ucData,0,sizeof(ucData));
	ucData[4] = 0x02;
	ucData[5] = 0x02;
	
	while(i<4)
	{
	    send_data (fd,&ucData[3-i],i+4);
	    usleep(1000*250);
	    ret = recv_date(fd,ucData,6);
	    if(ret != 0)
		break;
	    i++;
	}
	
	if(i == 4)
	   return -1;
	
	if(reset != 0)
	    Cmd_Reset(fd);

	return 0;
}


	
	














