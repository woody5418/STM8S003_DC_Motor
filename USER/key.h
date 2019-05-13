/********************************************************************
 *@file        key.h
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       KEY ��ʼ���Լ�ɨ�躯����ǰһ����⺯��
 *******************************************************************/
#ifndef __KEY_H
#define __KEY_H

#include "stm8s.h"

extern u8 direction;


void GPIO_INIT(void);
void key_init(void);
void key_scan(void);
#endif