#ifndef BSW_ETC_MY_STDIO_H_
#define BSW_ETC_MY_STDIO_H_

#include "Ifx_Console.h"
#include "IfxStdIf_DPipe.h"
#include "IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"
#include <stdio.h>


#define ASC_TX_BUFFER_SIZE          256                                     /* Define the TX buffer size in byte    */
#define ASC_RX_BUFFER_SIZE          256                                     /* Define the RX buffer size in byte    */
#define ASC_BAUDRATE                115200                                  /* Define the UART baud rate            */

extern void Init_Mystdio(void);
extern void my_puts(const char *str);
extern int my_printf(const char *format, ...);


extern void _init_uart3(void);                 /* Initialization function   */
extern unsigned char _in_uart3(void);          /* Receive (and wait for) a character from the serial line */
extern int _poll_uart3(unsigned char *chr);
extern void _out_uart3(const unsigned char chr);

#endif /* BSW_ETC_MY_STDIO_H_ */
