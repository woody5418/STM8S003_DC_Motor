/********************************************************************
 *@file        key.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       KEY初始化以及扫描函数
 *******************************************************************/
#include "flash_eeprom.h"
#include "delay.h"
#include "key.h"
#include "led.h"

u8 flag=0;
/*******************************************************************************
 * 函数名：key_init
 * 描述  ：配置key的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void key_init(void)
{
  //定义KEY的管脚为输入模式
    GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT);
}
/*******************************************************************************
 * 函数名：GPIO_INIT
 * 描述  ：配置GPIO的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void GPIO_INIT(void)
{
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST );  
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST );  
}


/*******************************************************************************
 * 函数名：key_scan
 * 描述  ：配置key扫描函数,写EEPROM
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void key_scan(void)
{
  if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_1) == 0) 
  {
    direction = 2;
    if(flag==0)
    {
      flag=1;
      WriteEEPROM(0x01);
    }
  }
  else
  { 
    if(flag == 1)
    {
      direction=1;
    }
    else{
      if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_4) != 0) return;
      while(1)
      {
        if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_4) == 0)
        {
            delay_ms(1);
            if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_4) == 0)
            {
                direction++;
                if(direction >= 3) 
                direction = 1;
                WriteEEPROM(direction);
                delay_ms(1);
                break;
            }
        }
      }
    }
  }
}

