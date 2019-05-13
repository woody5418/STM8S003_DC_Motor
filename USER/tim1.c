/********************************************************************
 *@file        tim1.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       tim1 ��ʼ����PWM����
 *******************************************************************/
#include "tim1.h"
#include "led.h"
#include "key.h"
#include "delay.h"


u16  pwm_cnt=0;
u16  PWM_set=0;
/*******************************************************************************
 * ��������TIM1_Init
 * ����  ������TIM1_Init�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void TIM1_Init(void)
{
  TIM1->PSCRH = 0x00; // ϵͳʱ�Ӿ�Ԥ��Ƶf=fck/(PSCR+1)
  TIM1->PSCRL = 0x0F; // PSCR=16 �� f=16M/16=1MHz,ÿ����������1us
  TIM1->ARRH = 0x00; // �Զ����ؼĴ���ARR=10us 
  TIM1->ARRL = 0x09; // ÿ����10�β���һ���жϣ���10us
  TIM1->IER |= 0x01; // ��������ж�
  TIM1->CR1 |= 0x01; // ������ʹ�ܣ���ʼ����
}


/*******************************************************************************
 * ��������TIM1_UPD_OVF_TRG_BRK_IRQHandler
 * ����  ��TIM1�жϣ���������PWM��
 * ����  ����
 * ���  ����
 * ����  ����
 ******************************************************************************/
#pragma vector=0xD     //11+2
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)//����жϣ����Ŀ���ָ��75ҳ
{
  TIM1->SR1 = 0; //����жϱ��
  if(pwm_cnt == 800)  
  pwm_cnt=0; 
  PWM_SET();
  pwm_cnt++;
  
}
 /*******************************************************************************
 * ��������PWM_SET
 * ����  ��PWM���ã����ڿ���L9110
 * ����  ����
 * ���  ����
 * ����  ����
 ******************************************************************************/ 
void PWM_SET(void)
{
  if(direction == 1)
  {
    GPIO_WriteLow(GPIOD, GPIO_PIN_4);     // 4��  3�� 
    if(PWM_set >= 10)
    {
        if(pwm_cnt <= PWM_set)
        {
            GPIO_WriteHigh(GPIOD, GPIO_PIN_3);  // ��
        }else 
           if(pwm_cnt > PWM_set)     
             GPIO_WriteLow(GPIOD, GPIO_PIN_3);   // ��
    }else GPIO_WriteLow(GPIOD, GPIO_PIN_3);       // ��
  }else
    if(direction == 2)
    {
        GPIO_WriteLow(GPIOD, GPIO_PIN_3);     // 3�� 4��
        if(PWM_set >= 10)
        {
            if(pwm_cnt <= PWM_set)
            {
                GPIO_WriteHigh(GPIOD, GPIO_PIN_4);  // ��
            }else
                if(pwm_cnt > PWM_set)   
                  GPIO_WriteLow(GPIOD, GPIO_PIN_4);   // ��
        }else  GPIO_WriteLow(GPIOD, GPIO_PIN_4);   // ��
    }
}












