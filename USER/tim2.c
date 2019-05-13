#include "tim2.h"
#include "led.h"
#include "delay.h"


void TIM2_Init(void)
{
  TIM2->PSCR = 0x0A; //系统时钟经预分频f=16M/1024=15.625k,0A=10,2^10=1024;
  TIM2->ARRH = 0x1E; // 1/15.625k * 7813 = 500ms
  TIM2->ARRL = 0x85; //1E84=7813
  TIM2->IER |= 0x01; //运行更新中断
  TIM2->CR1 |= 0x01; //使能计数器
}


#pragma vector=0xF       //13+2
__interrupt void TIM2_UPD_OVF_BRK_IRQHandler(void)//溢出中断，中文开发指南75页
{
  TIM2->SR1 = 0; //清除中断标记
  //led_not;
  GPIO_WriteReverse(GPIOD, GPIO_PIN_3);
  GPIO_WriteReverse(GPIOD, GPIO_PIN_4);
}



