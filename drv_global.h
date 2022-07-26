#ifndef DRV_GLOBAL_H
#define DRV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DRV_LIBRARY)
#define DRV_EXPORT Q_DECL_EXPORT
#else
#define DRV_EXPORT Q_DECL_IMPORT
#endif

#define RS232_RX_01 (0x0000)
#define RS232_RX_02 (0x0010)
#define RS232_RX_03 (0x0020)
#define RS232_RX_04 (0x0030)
#define RS232_RX_05 (0x0040)
#define RS232_RX_06 (0x0050)
#define RS232_RX_07 (0x0060)
#define RS232_RX_08 (0x0070)
#define RS232_RX_09 (0x0080)
#define RS232_RX_10 (0x0090)

#define RS232_TX_01 (0x00A0)
#define RS232_TX_02 (0x00B0)
#define RS232_TX_03 (0x00C0)
#define RS232_TX_04 (0x00D0)
#define RS232_TX_05 (0x00E0)
#define RS232_TX_06 (0x00F0)
#define RS232_TX_07 (0x0100)
#define RS232_TX_08 (0x0110)
#define RS232_TX_09 (0x0120)
#define RS232_TX_10 (0x0130)

#define RS422_RX_01 (0x0140)
#define RS422_RX_02 (0x0150)
#define RS422_RX_03 (0x0160)
#define RS422_RX_04 (0x0170)
#define RS422_RX_05 (0x0180)
#define RS422_RX_06 (0x0190)
#define RS422_RX_07 (0x01A0)
#define RS422_RX_08 (0x01B0)
#define RS422_RX_09 (0x01C0)
#define RS422_RX_10 (0x01D0)
#define RS422_RX_11 (0x01E0)
#define RS422_RX_12 (0x01F0)
#define RS422_RX_13 (0x0200)
#define RS422_RX_14 (0x0210)
#define RS422_RX_15 (0x0220)
#define RS422_RX_16 (0x0230)
#define RS422_RX_17 (0x0240)
#define RS422_RX_18 (0x0250)






#define RS422_TX_01 (0x0200)
#define RS422_TX_02 (0x0210)
#define RS422_TX_03 (0x0220)
#define RS422_TX_04 (0x0230)
#define RS422_TX_05 (0x0240)
#define RS422_TX_06 (0x0250)
#define RS422_TX_07 (0x0260)
#define RS422_TX_08 (0x0270)
#define RS422_TX_09 (0x0280)
#define RS422_TX_10 (0x0290)
#define RS422_TX_11 (0x02A0)
#define RS422_TX_12 (0x02B0)
#define RS422_TX_13 (0x02C0)
#define RS422_TX_14 (0x02D0)
#define RS422_TX_15 (0x02E0)
#define RS422_TX_16 (0x02F0)
#define RS422_TX_17 (0x0300)
#define RS422_TX_18 (0x0310)








#define ARINC429_RX_01 (0x02C0)
#define ARINC429_RX_02 (0x02D0)
#define ARINC429_RX_03 (0x02E0)
#define ARINC429_RX_04 (0x02F0)
#define ARINC429_RX_05 (0x0300)
#define ARINC429_RX_06 (0x0310)

#define ARINC429_TX_01 (0x0320)
#define ARINC429_TX_02 (0x0330)
#define ARINC429_TX_03 (0x0340)
#define ARINC429_TX_04 (0x0350)
#define ARINC429_TX_05 (0x0360)
#define ARINC429_TX_06 (0x0370)

#define  ARINC429_1OOK 100000
#define  ARINC429_PARITY_NONE 0X00
#define  ARINC429_PARITY_EVEN 0X04
#define  ARINC429_PARITY_ODD  0X05
#define  ARINC429_PARITY_ZERO 0X06
#define  ARINC429_PARITY_ONE  0X07
#define  ARINC429_ENC_25BIT   0X00
#define  ARINC429_ENC_32BIT   0X01

#define RS232_PARITY_NONE 0X00
#define RS232_PARITY_EVEN 0X04
#define RS232_PARITY_ODD 0X05
#define RS232_PARITY_ZERO 0X06
#define RS232_PARITY_ONE 0X07

#define RS232_DATA_BITS_5BIT 0x00
#define RS232_DATA_BITS_6BIT 0x01
#define RS232_DATA_BITS_7BIT 0x02
#define RS232_DATA_BITS_8BIT 0x03

#define RS232_STOP_BITS_1BIT 0x00
#define RS232_STOP_BITS_2BIT 0x01

#define RS422_PARITY_NONE 0X00
#define RS422_PARITY_EVEN 0X04
#define RS422_PARITY_ODD 0X05
#define RS422_PARITY_ZERO 0X06
#define RS422_PARITY_ONE 0X07

#define RS422_DATA_BITS_5BIT 0x00
#define RS422_DATA_BITS_6BIT 0x01
#define RS422_DATA_BITS_7BIT 0x02
#define RS422_DATA_BITS_8BIT 0x03

#define RS422_STOP_BITS_1BIT 0x00
#define RS422_STOP_BITS_2BIT 0x01

#define ENABLE_RS422 1
#define ENABLE_RS232 1
#define ENABLE_ARINC429 1

#define IO_01 (0X0001<<0)
#define IO_02 (0X0001<<1)
#define IO_03 (0X0001<<2)
#define IO_04 (0X0001<<3)
#define IO_05 (0X0001<<4)
#define IO_06 (0X0001<<5)
#define IO_07 (0X0001<<6)
#define IO_08 (0X0001<<7)
#define IO_09 (0X0001<<8)
#define IO_10 (0X0001<<9)
#define IO_11 (0X0001<<10)
#define IO_12 (0X0001<<11)
#define IO_13 (0X0001<<12)
#define IO_14 (0X0001<<13)
#define IO_15 (0X0001<<14)
#define IO_16 (0X0001<<15)


/**
 * rs232_open - 打开RS232端口
 * @fd: 设备编号 取值范围为 RS232_RX_01-RS232_TX_10
 *
 * 执行成功返回0，其它值则执行错误。
 */

extern int32_t rs232_open(uint32_t fd);
/**
 * rs232_config - 配置RS232端口通讯参数
 * @fd: 设备编号 取值范围为 RS232_RX_01-RS232_TX_10
 * @baudrate: 波特率
 * @bits: 数据位长度
        RS232_DATA_BITS_5BIT 5bit
        RS232_DATA_BITS_6BIT 6bit
        RS232_DATA_BITS_7BIT 7bit
        RS232_DATA_BITS_8BIT 8bit
 * @parity: 校验位
        RS232_PARITY_NONE  无校验
        RS232_PARITY_EVEN  奇校验
        RS232_PARITY_ODD   偶校验
        RS232_PARITY_ZERO  固定0
        RS232_PARITY_ONE   固定1
 * @stop: 停止位
        RS232_STOP_BITS_1BIT 1bit
        RS232_STOP_BITS_2BIT 2bit
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs232_config(uint32_t fd, uint32_t baudrate, uint32_t bits,uint32_t parity, uint32_t stop);
/**
 * rs232_write - 向RS232端口写入数据
 * @fd: 设备编号 取值范围为 RS232_RX_01~RS232_TX_10
 * @data: 写入缓冲区指针
 * @size: 写入缓冲区长度
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs232_write(uint32_t fd, const char *data, int size);

/**
 * rs232_read_buffer_size - 读取接收缓冲区内的数据长度
 * @fd: 设备编号 取值范围为 RS232_RX_01~RS232_RX_10
 * 返回值：接收缓冲区内的数据长度
 */
extern int32_t rs232_read_buffer_size(uint32_t fd);


/**
 * rs232_read - 从端口缓冲区内读取size 字节数据到用户缓冲区
 * @fd: 设备编号 取值范围为 RS232_RX_01~RS232_RX_10
 * @data 接收缓冲区指针
 * 执行成功返回0，其它值则执行错误
 */
extern int32_t rs232_read(uint32_t fd,  uint8_t *data, int size);
/**
 * rs232_close - 关闭RS232端口
 * @fd: 设备编号 取值范围为 RS232_RX_01~RS232_TX_10
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs232_close(uint32_t fd);

/**
 * rs422_open - 打开RS422端口
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_TX_12
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs422_open(uint32_t fd);

/**
 * rs422_config - 配置RS422端口通讯参数
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_TX_12
 * @baudrate: 波特率
 * @bits: 数据位长度
        RS422_DATA_BITS_5BIT 5bit
        RS422_DATA_BITS_6BIT 6bit
        RS422_DATA_BITS_7BIT 7bit
        RS422_DATA_BITS_8BIT 8bit
 * @parity: 校验位
        RS422_PARITY_NONE  无校验
        RS422_PARITY_EVEN  奇校验
        RS422_PARITY_ODD   偶校验
        RS422_PARITY_ZERO  固定0
        RS422_PARITY_ONE   固定1
 * @stop: 停止位
        RS422_STOP_BITS_1BIT 1bit
        RS422_STOP_BITS_2BIT 2bit
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs422_config(uint32_t fd, uint32_t baudrate, uint32_t bits,uint32_t parity, uint32_t stop);

/**
 * rs422_write - 向RS422端口写入数据
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_TX_12
 * @data: 写入缓冲区指针
 * @size: 写入缓冲区长度
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs422_write(uint32_t fd, const char *data, uint16_t size);


/**
 * rs422_read_buffer_size - 读取接收缓冲区内的数据长度
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_RX_12
 * 返回值：接收缓冲区内的数据长度
 */
extern int32_t rs422_read_buffer_size(uint32_t fd);


/**
 * rs422_write - 从端口缓冲区内读取size 字节数据到用户缓冲区
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_RX_12
 * @data 接收缓冲区指针
 * 执行成功返回0，其它值则执行错误
 */
extern int32_t rs422_read(uint32_t fd,  uint8_t *data, int size);


/**
 * rs422_close - 关闭RS422端口
 * @fd: 设备编号 取值范围为 RS422_RX_01~RS422_TX_12
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t rs422_close(uint32_t fd);


/**
 * arinc429_open - 打开ARINC429端口
 * @fd: 设备编号 取值范围为 ARINC429_RX_01~ARINC429_TX_05
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t arinc429_open(uint32_t fd);
/**
 * arinc429_config - 配置ARINC429端口通讯参数
 * @fd: 设备编号 取值范围为 ARINC429_RX_01~ARINC429_TX_05
 * @baudrate: 波特率
 * @parity: 校验位
                ARINC429_PARITY_NONE 无校验
                ARINC429_PARITY_EVEN 偶校验
                ARINC429_PARITY_ODD  奇校验
                ARINC429_PARITY_ZERO 固定0
                ARINC429_PARITY_ONE  固定1
 * @encmode: 编码模式
                ARINC429_ENC_25BIT 25位编码模式
                ARINC429_ENC_32BIT 32位编码模式
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t arinc429_config(uint32_t fd, uint32_t baudrate, uint32_t parity,uint32_t encmode);
/**
 *arinc429_write - 向ARINC429端口写入数据
 * @fd: 设备编号 取值范围为 ARINC429_RX_01~ARINC429_TX_05
 * @data: 写入缓冲区指针
 * @size: 写入缓冲区长度
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t arinc429_write(uint32_t fd, const uint32_t *data, uint16_t size);

/**
 *arinc429_read_buffer_size - 读取接收缓冲区内的数据长度
 * @fd:  设备编号 取值范围为设备编号 取值范围为 ARINC429_RX_01~ARINC429_RX_06
 * 返回值：接收缓冲区内的数据长度
 */
extern int32_t arinc429_read_buffer_size(uint32_t fd);
/**
 * arinc429_read - 从端口缓冲区内读取size个DWORD数据到用户缓冲区
 * @fd: 设备编号 取值范围为设备编号 取值范围为 ARINC429_RX_01~ARINC429_RX_06
 * @data 接收缓冲区指针
 * 执行成功返回0，其它值则执行错误
 */
extern int32_t arinc429_read(uint32_t fd,  uint32_t *data, int size);


/**
 * arinc429_close - 关闭ARINC429端口
 * @fd: 设备编号 取值范围为 ARINC429_RX_01~ARINC429_TX_05
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern int32_t arinc429_close(uint32_t fd);

extern uint32_t io_read_output_status();
extern uint32_t io_out_high(uint32_t pin);
extern uint32_t io_out_low(uint32_t  pin);


/**
 * io_out - 设置端口的输出值(低16位有效)
 * @pin_level: 所有端口的输出值
 * 执行成功返回0，其它值则执行错误。
 */
extern uint32_t io_out(uint32_t pin);
/**
 * io_set_outputmode -设置端口方向为输出(需要取反即输出0X00001 对应函数为io_out(~0x0001))
 * @pin: 离散量端口编号 取值范围为 IO_01~IO_16
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern uint32_t io_set_outputmode(uint32_t  pin);
/**
 * io_set_inputmode - 设置端口方向为输入(自测试专用API)
 *  @pin: 离散量端口编号 取值范围为 IO_01~IO_16
 * @memaddr: memory address
 * @iword: word to write
 *
 * 执行成功返回0，其它值则执行错误。
 */
extern uint32_t io_set_inputmode(uint32_t  pin);
extern uint32_t io_read();


#endif // DRV_GLOBAL_H
