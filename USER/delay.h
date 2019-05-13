/********************************************************************
 *@file        delay.h
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       delay 初始化以及延时函数
 *******************************************************************/
#ifndef  __DELAY_H
#define  __DELAY_H
#include "stm8s.h"

#define BIT(x) (1 << (x))

#define INTEN   asm("rim");    //open interrupt
#define INTOFF  asm("sim");    //closs interrupt
#define MCUSLEEP asm("halt");  //sleep

//******************************************************************************
//支持不同时钟频率
//提供delay_us,delay_ms两个延时函数. 
//******************************************************************************
void delay_init(u8 clk); //延时函数初始化
void delay_us(u16 nus);  //us级延时函数,最大65536us.
void delay_ms(u32 nms);  //ms级延时函数
void delay_10us(u32 nus); //10us级延时函数



#endif