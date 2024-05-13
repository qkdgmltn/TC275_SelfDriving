/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "AppScheduling.h"
#include "Driver_Stm.h"
#include <Control_section/Motor_control.h>
#include <Actuation_output/Motor_driver.h>
#include <Sensor_input/Encoder.h>

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
static void AppNoTask(void);
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

static void AppNoTask(void){

    Encoder_cnt_left();
    Encoder_cnt_right();
}


static void AppTask1ms(void)
{
    stTestCnt.u32nuCnt1ms++;

//    setDutyCycleA(0.5);
//    setDutyCycleB(0.5);

    velocity_cal_left();
    velocity_cal_right();

    pid_control_left();
    pid_control_right();
}

static void AppTask10ms(void)
{
    stTestCnt.u32nuCnt10ms++;

}


static void AppTask100ms(void)
{
    stTestCnt.u32nuCnt100ms++;
    calculate_speed(Left_velocity, Right_velocity);
}

static void AppTask1000ms(void)
{
    stTestCnt.u32nuCnt100ms++;
    t++;
}

void AppScheduling(void)
{
    AppNoTask();
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
