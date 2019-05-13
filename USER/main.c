/*************** (C) COPYRIGHT  四维拓智 ***************************************
 * 文件名  ：main.c
 * 描述    ：工程模板    
 * 库版本  ：V1.1.0
 * 开发人员：Woody QQ：2490006131
 * 修改时间：2016-10-14
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "sysclock.h"
#include "delay.h"
#include "flash_eeprom.h"
#include "tim1.h"
#include "led.h"
#include "key.h"
#include "adc.h"

u8 direction=1;
u8 flag_eeprom=0;
u16 ADC_Value=0;

/*  Defines -----------------------------------------------------------*/
/*  Variate ---------------------------------------------------------*/
//按键作为拨码开关使用
int main(void)
{    
  /* 系统时钟初始化 */
  SystemClock_Init(); 
  delay_init(16);
  key_init();
  GPIO_INIT();
  TIM1_Init();
  ADC_Init();
  Init_EEPROM();
  enableInterrupts(); 	/* 开启总中断 */
  
  while (1)
  {
     if(flag_eeprom == 0)
     {
        flag_eeprom=1;
        direction=ReadEEPROM();  
        delay_ms(10);
        if(direction == 0) direction=1;
     }
    key_scan(); //方向控制   
    //49344 
    ADC_Value = ADC1_GetConversionValue()/64;
    if(ADC_Value <= 180) 
        PWM_set = 0; 
    else  
        PWM_set = ADC_Value; 
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif






