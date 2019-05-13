/********************************************************************
 *@file        tim1.h
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       tim1  初始化以及通道切换
 *******************************************************************/
#ifndef __TIM1_H
#define __TIM1_H

#include "stm8s.h"

extern u16 PWM_set;

void TIM1_Init(void);
void PWM_SET(void);

#endif