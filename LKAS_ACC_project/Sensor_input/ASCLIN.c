#include "ASCLIN.h"

static IfxAsclin_Asc g_ascHandle3;
static IfxStdIf_DPipe g_ascStandardInterface;


uint8 g_uartTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartTxBuffer_0[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuffer_0[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartTxBuffer_1[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuffer_1[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];



IFX_INTERRUPT(asclin3TxISR, 0, ISR_PRIORITY_ASCLIN_TX);
void asclin3TxISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_ascHandle3);
}
IFX_INTERRUPT(asclin3RxISR, 0, ISR_PRIORITY_ASCLIN_RX);
void asclin3RxISR(void)
{
    IfxAsclin_Asc_isrReceive(&g_ascHandle3);
}
IFX_INTERRUPT(asclin3ErrISR, 0, ISR_PRIORITY_ASCLIN_ER);
void asclin3ErrISR(void)
{
    while(1);
}

void _init_uart3(void)
{
    IfxAsclin_Asc_Config ascConf;

    /* Set default configurations */
    IfxAsclin_Asc_initModuleConfig(&ascConf, &MODULE_ASCLIN3); /* Initialize the structure with default values      */

    /* Set the desired baud rate */
    ascConf.baudrate.baudrate = ASC_BAUDRATE;                                   /* Set the baud rate in bit/s       */
    ascConf.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;            /* Set the oversampling factor      */

    /* Configure the sampling mode */
    ascConf.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;             /* Set the number of samples per bit*/
    ascConf.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;    /* Set the first sample position    */

    /* ISR priorities and interrupt target */
    ascConf.interrupt.txPriority = ISR_PRIORITY_ASCLIN_TX;  /* Set the interrupt priority for TX events             */
    ascConf.interrupt.rxPriority = ISR_PRIORITY_ASCLIN_RX;  /* Set the interrupt priority for RX events             */
    ascConf.interrupt.erPriority = ISR_PRIORITY_ASCLIN_ER;  /* Set the interrupt priority for Error events          */
    ascConf.interrupt.typeOfService = IfxSrc_Tos_cpu0;

    /* Pin configuration */
    const IfxAsclin_Asc_Pins pins = {
            .cts        = NULL_PTR,                         /* CTS pin not used                                     */
            .ctsMode    = IfxPort_InputMode_pullUp,
            .rx         = &IfxAsclin3_RXD_P32_2_IN ,        /* Select the pin for RX connected to the USB port      */
//            .rx         = &IfxAsclin3_RXC_P20_3_IN ,        /* Select the pin for RX connected to the USB port      */
            .rxMode     = IfxPort_InputMode_pullUp,         /* RX pin                                               */
            .rts        = NULL_PTR,                         /* RTS pin not used                                     */
            .rtsMode    = IfxPort_OutputMode_pushPull,
            .tx         = &IfxAsclin3_TX_P15_7_OUT,         /* Select the pin for TX connected to the USB port      */
//            .tx         = &IfxAsclin3_TX_P20_0_OUT,         /* Select the pin for TX connected to the USB port      */
            .txMode     = IfxPort_OutputMode_pushPull,      /* TX pin                                               */
            .pinDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    ascConf.pins = &pins;

    /* FIFO buffers configuration */
    ascConf.txBuffer = g_uartTxBuffer;                      /* Set the transmission buffer                          */
    ascConf.txBufferSize = ASC_TX_BUFFER_SIZE;              /* Set the transmission buffer size                     */
    ascConf.rxBuffer = g_uartRxBuffer;                      /* Set the receiving buffer                             */
    ascConf.rxBufferSize = ASC_RX_BUFFER_SIZE;              /* Set the receiving buffer size                        */

    /* Init ASCLIN module */
    IfxAsclin_Asc_initModule(&g_ascHandle3, &ascConf);          /* Initialize the module with the given configuration   */

    IfxAsclin_Asc_stdIfDPipeInit(&g_ascStandardInterface, &g_ascHandle3);

    Ifx_Console_init(&g_ascStandardInterface);
}

void _out_uart3(const uint32_t chr)
{
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, chr);
}

void _out_uart3_2(const uint32_t value1, const uint32_t value2)
{
    // 두 개의 4바이트 값을 하나의 4바이트 변수에 각각 담음
    uint32_t data = (value1 << 16) | (value2 & 0xFFFF);

    // 상위 4바이트를 먼저 전송
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, data >> 24);
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, (data >> 16) & 0xFF);

    // 다음 하위 4바이트를 전송
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, (data >> 8) & 0xFF);
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, data & 0xFF);
}

uint32_t _in_uart3(void)
{
    return IfxAsclin_Asc_blockingRead(&g_ascHandle3);
}