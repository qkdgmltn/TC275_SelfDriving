#ifndef TOF_H_
#define TOF_H_

#include "Ifx_Types.h"
#include "IfxAsclin_Asc.h"
#include "IfxStdIf_DPipe.h"
#include "IfxCpu_Irq.h"
#include "Ifx_Console.h"
#include <stdio.h>

#define ASC_TX_BUFFER_SIZE          256                                     /* Define the TX buffer size in byte    */
#define ASC_RX_BUFFER_SIZE          256

#define ISR_PRIORITY_ASCLIN_TOF_TX  49                                       /* Priority for interrupt ISR Receive   */
#define ISR_PRIORITY_ASCLIN_TOF_RX  50                                     /* Priority for interrupt ISR Receive   */
#define ISR_PRIORITY_ASCLIN_TOF_ER  51

#define TOF_BAUDRATE                921600

static int verifyCheckSum(unsigned char data[]);
static int checkTofStrength(unsigned char data[]);
extern int distance;

extern void Init_ToF(void);
void _init_uart1(void);                 /* Initialization function   */
unsigned char _in_uart1(void);          /* Receive (and wait for) a character from the serial line */
int _poll_uart1(unsigned char *chr);
void _out_uart1(const unsigned char chr);
uint32 LPF(int prev_dist, int dist, double Ts, int cf);

extern int getTofDistance(void);

#endif /* TOF_H_ */
