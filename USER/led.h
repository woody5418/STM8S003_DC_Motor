/********************************************************************
 *@file        led.h
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       led 初始化以及LED_Show函数
 *******************************************************************/
#ifndef __LED_H
#define __LED_H



#include "stm8s.h"

#define LED_PORT            GPIOC	 //LED  PA1
#define LED_1               GPIO_PIN_7

#define ON       0		/* 定义LED灯灭 -- 低电平*/
#define OFF      1		/* 定义LED灯亮 -- 高电平*/

void LED_Init(void);
void LED_Show(void);
void LED_Config(GPIO_Pin_TypeDef led, u8 state);

#endif