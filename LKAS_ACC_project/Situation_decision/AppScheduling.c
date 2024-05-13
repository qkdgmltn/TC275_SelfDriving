/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "AppScheduling.h"
#include "Driver_Stm.h"
#include <Control_section/Motor_control.h>

/***********************************************************************/
/*Define*/
/***********************************************************************/

/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    uint32 u32nuCnt1ms;
    uint32 u32nuCnt10ms;
    uint32 u32nuCnt100ms;
}TestCnt;
/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void AppTask1ms(void);
static void AppTask10ms(void);
static void AppTask100ms(void);
static void AppTask1000ms(void);
/***********************************************************************/
/*Variable*/
/***********************************************************************/
TestCnt stTestCnt;
int t = 0;
/***********************************************************************/
/*Function*/
/***********************************************************************/

static void AppTask1ms(void)
{
    stTestCnt.u32nuCnt1ms++;
}

static void AppTask10ms(void)
{
    stTestCnt.u32nuCnt10ms++;
    calculate_speed(cur_velo_wheel.v_left,cur_velo_wheel.v_right);
}


static void AppTask100ms(void)
{
    stTestCnt.u32nuCnt100ms++;
}

static void AppTask1000ms(void)
{
    stTestCnt.u32nuCnt100ms++;
    t++;
}

void AppScheduling(void)
{
    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
        AppTask1ms();

        if(stSchedulingInfo.u8nuScheduling10msFlag == 1u)
        {
            stSchedulingInfo.u8nuScheduling10msFlag = 0u;
            AppTask10ms();
        }
        if(stSchedulingInfo.u8nuScheduling100msFlag == 1u)
        {
            stSchedulingInfo.u8nuScheduling100msFlag = 0u;
            AppTask100ms();
        }
        if(stSchedulingInfo.u8nuScheduling1000msFlag == 1u)
        {
            stSchedulingInfo.u8nuScheduling1000msFlag = 0u;
            AppTask1000ms();
        }
    }
}
