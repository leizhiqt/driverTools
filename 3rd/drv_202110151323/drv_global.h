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
//
#define RS232_RX_11 (0x00A0)
#define RS232_RX_12 (0x00B0)
#define RS232_RX_13 (0x00C0)
#define RS232_RX_14 (0x00D0)



#define RS232_TX_01 (0x00E0)
#define RS232_TX_02 (0x00F0)
#define RS232_TX_03 (0x0100)
#define RS232_TX_04 (0x0110)
#define RS232_TX_05 (0x0120)
#define RS232_TX_06 (0x0130)
#define RS232_TX_07 (0x0140)
#define RS232_TX_08 (0x0150)
#define RS232_TX_09 (0x0160)
#define RS232_TX_10 (0x0170)
//
#define RS232_TX_11 (0x0180)
#define RS232_TX_12 (0x0190)
#define RS232_TX_13 (0x01A0)
#define RS232_TX_14 (0x01B0)

#define RS422_RX_01 (0x01C0)
#define RS422_RX_02 (0x01D0)
#define RS422_RX_03 (0x01E0)
#define RS422_RX_04 (0x01F0)
#define RS422_RX_05 (0x0200)
#define RS422_RX_06 (0x0210)
#define RS422_RX_07 (0x0220)
#define RS422_RX_08 (0x0230)
#define RS422_RX_09 (0x0240)
#define RS422_RX_10 (0x0250)
#define RS422_RX_11 (0x0260)
#define RS422_RX_12 (0x0270)
//
#define RS422_RX_13 (0x0280)
#define RS422_RX_14 (0x0290)
#define RS422_RX_15 (0x02A0)
#define RS422_RX_16 (0x02B0)
#define RS422_RX_17 (0x02C0)
#define RS422_RX_18 (0x02D0)


#define RS422_TX_01 (0x02E0)
#define RS422_TX_02 (0x02F0)
#define RS422_TX_03 (0x0300)
#define RS422_TX_04 (0x0310)
#define RS422_TX_05 (0x0320)
#define RS422_TX_06 (0x0330)
#define RS422_TX_07 (0x0340)
#define RS422_TX_08 (0x0350)
#define RS422_TX_09 (0x0360)
#define RS422_TX_10 (0x0370)
#define RS422_TX_11 (0x0380)
#define RS422_TX_12 (0x0390)
//
#define RS422_TX_13 (0x03A0)
#define RS422_TX_14 (0x03B0)
#define RS422_TX_15 (0x03C0)
#define RS422_TX_16 (0x03D0)
#define RS422_TX_17 (0x03E0)
#define RS422_TX_18 (0x03F0)


#define ARINC429_RX_01 (0x0400)
#define ARINC429_RX_02 (0x0410)
#define ARINC429_RX_03 (0x0420)
#define ARINC429_RX_04 (0x0430)
#define ARINC429_RX_05 (0x0440)
#define ARINC429_RX_06 (0x0450)

//
#define ARINC429_RX_07 (0x0460)
#define ARINC429_RX_08 (0x0470)


#define ARINC429_TX_01 (0x0480)
#define ARINC429_TX_02 (0x0490)
#define ARINC429_TX_03 (0x04A0)
#define ARINC429_TX_04 (0x04B0)
#define ARINC429_TX_05 (0x04C0)
//
#define ARINC429_TX_06 (0x04D0)
#define ARINC429_TX_07 (0x04E0)
#define ARINC429_TX_08 (0x04F0)

#define ARINC429_1OOK 100000
#define ARINC429_PARITY_NONE 0X00
#define ARINC429_PARITY_EVEN 0X04
#define ARINC429_PARITY_ODD 0X05
#define ARINC429_PARITY_ZERO 0X06
#define ARINC429_PARITY_ONE 0X07
#define ARINC429_ENC_25BIT 0X00
#define ARINC429_ENC_32BIT 0X01

#define ENABLE_RS422 1
#define ENABLE_RS232 1
#define ENABLE_ARINC429 1

#define IO_01 (0X0001 << 0)
#define IO_02 (0X0001 << 1)
#define IO_03 (0X0001 << 2)
#define IO_04 (0X0001 << 3)
#define IO_05 (0X0001 << 4)
#define IO_06 (0X0001 << 5)
#define IO_07 (0X0001 << 6)
#define IO_08 (0X0001 << 7)
#define IO_09 (0X0001 << 8)
#define IO_10 (0X0001 << 9)
#define IO_11 (0X0001 << 10)
#define IO_12 (0X0001 << 11)
#define IO_13 (0X0001 << 12)
#define IO_14 (0X0001 << 13)
#define IO_15 (0X0001 << 14)
#define IO_16 (0X0001 << 15)
#define IO_17 (0X0001 << 16)
#define IO_18 (0X0001 << 17)
#define IO_19 (0X0001 << 18)
#define IO_20 (0X0001 << 19)
#define IO_21 (0X0001 << 20)
#define IO_22 (0X0001 << 21)
#define IO_23 (0X0001 << 22)
#define IO_24 (0X0001 << 23)
#define IO_25 (0X0001 << 24)



typedef struct _rx_data_ST {
  void (*rxfuncbk)(uint8_t *data, uint16_t length);
  uint8_t *data;
  uint16_t length;
} rx_data_ST;

extern int32_t rs232_open(uint32_t fd);
extern int32_t rs232_config(uint32_t fd, uint32_t baudrate, uint32_t bits,
                            uint32_t parity, uint32_t stop);
extern int32_t rs232_write(uint32_t fd, const char *data, int size);
extern int32_t rs232_set_rx_cbk(uint32_t fd, rx_data_ST cbk);
extern int32_t rs232_close(uint32_t fd);

extern int32_t rs422_open(uint32_t fd);
extern int32_t rs422_config(uint32_t fd, uint32_t baudrate, uint32_t bits,
                            uint32_t parity, uint32_t stop);
extern int32_t rs422_write(uint32_t fd, const char *data, uint16_t size);
extern int32_t rs422_set_rx_cbk(uint32_t fd, rx_data_ST cbk);
extern int32_t rs422_close(uint32_t fd);

extern int32_t arinc429_open(uint32_t fd);
extern int32_t arinc429_config(uint32_t fd, uint32_t baudrate, uint32_t parity,
                               uint32_t encmode);
extern int32_t arinc429_write(uint32_t fd, const uint32_t *data, uint16_t size);
extern int32_t arinc429_set_rx_cbk(uint32_t fd, rx_data_ST cbk);
extern int32_t arinc429_close(uint32_t fd);

extern uint32_t io_out_high(uint32_t pin);
extern uint32_t io_out_low(uint32_t pin);
extern uint32_t io_out(uint32_t pin);
extern uint32_t io_set_outputmode(uint32_t pin);
extern uint32_t io_set_inputmode(uint32_t pin);
extern uint32_t io_read();

#endif // DRV_GLOBAL_H
