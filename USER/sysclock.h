/********************************************************************
 *@file        sysclock.h
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ϵͳʱ��ѡ��
 *******************************************************************/
#ifndef __SYSCLOCK_H
#define __SYSCLOCK_H


#include "stm8s.h"


#define CFQ_FRNT_PORT       GPIOC	 //������  PC3

#define CFQ_1               GPIO_PIN_3    //ǰһ��



/* �������ⲿʹ�õĺ��� */
void SystemClock_Init(void);

#endif

