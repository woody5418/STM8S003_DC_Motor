/********************************************************************
 *@file        led.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       LED 初始化以及LED_Show函数
 *******************************************************************/
#include "led.h"
#include "delay.h"
/*******************************************************************************
 * 函数名：LED_Init
 * 描述  ：配置LED_Init的初始化函数
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void LED_Init(void)
{       
    //定义LED的管脚为输出模式
    GPIO_Init(LED_PORT, LED_1, GPIO_MODE_OUT_PP_HIGH_FAST );
}
/*******************************************************************************
 * 函数名：LED_Config
 * 描述  ：配置LED初始化函数
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void LED_Config(GPIO_Pin_TypeDef led, u8 state)
{
    if(ON == state) 
    {
        GPIO_WriteLow(LED_PORT, led);
    }
    else
    {
        GPIO_WriteHigh(LED_PORT, led);
    }
}
/*******************************************************************************
 * 函数名：LED_Show
 * 描述  ：配置LED_Show初始化函数
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void LED_Show(void)
{
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
}


