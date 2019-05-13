/********************************************************************
 *@file        adc.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       ADC 初始化以及通道切换
 *******************************************************************/
#include "adc.h"
#include "delay.h"
/*******************************************************************************
 * 函数名：ADC_Init
 * 描述  ：配置ADC1的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void ADC_Init(void)
{
    ADC1_DeInit();
    ADC1_Cmd(ENABLE);
    ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, \
    ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_LEFT, ADC1_SCHMITTTRIG_CHANNEL3, DISABLE);

    ADC1_Cmd(ENABLE);
    ADC1_StartConversion(); 
}

