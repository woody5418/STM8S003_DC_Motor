/********************************************************************
 *@file        delay.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       微秒延迟/毫秒延迟/10微秒延迟 
 *******************************************************************/
#include "delay.h"

volatile u8 fac_us=0;  /* us延时倍乘数 */


/*******************************************************************************
 * 函数名：delay_init
 * 描述  ：延时函数初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 * 说明  ：为确保准确度,请保证时钟频率最好为4的倍数,最低8Mhz
           clk:时钟频率(24/16/12/8等)
 ******************************************************************************/
void delay_init(u8 clk)
{
  if(clk>16)fac_us=(16-4)/4;       /* 24Mhz时,stm8大概19个周期为1us */
  else if(clk>4)fac_us=(clk-4)/4; 
  else fac_us=1;
}

/*******************************************************************************
 * 函数名：delay_us
 * 描述  ：延时nus
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 * 说明  ：T为CPU运行频率(Mhz)的倒数,单位为us.（延时时间=(fac_us*4+4)*nus*(T)）
 * 准确度： 92%  @24Mhz
            98%  @16Mhz
            98%  @12Mhz
            86%  @8Mhz
 ******************************************************************************/
void delay_us(u16 nus)
{  
  __asm(
  "PUSH A          \n"  //1T,压栈
  "DELAY_XUS:      \n"   
  "LD A,fac_us     \n"   //1T,fac_us加载到累加器A
  "DELAY_US_1:     \n"  
  "NOP             \n"  //1T,nop延时
  "DEC A           \n"  //1T,A--
  "JRNE DELAY_US_1 \n"   //不等于0,则跳转(2T)到DELAY_US_1继续执行,若等于0,则不跳转(1T).
  "NOP             \n"  //1T,nop延时
  "DECW X          \n"  //1T,x--
  "JRNE DELAY_XUS  \n"    //不等于0,则跳转(2T)到DELAY_XUS继续执行,若等于0,则不跳转(1T).
  "POP A           \n"  //1T,出栈
  ); 
} 

/*******************************************************************************
 * 函数名：delay_ms
 * 描述  ：延时nms
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 * 说明  ：为保证准确度,nms不要大于16640.
 ******************************************************************************/
void delay_ms(u32 nms)
{
  u8 t;
  if(nms>65)
  {
    t=nms/65;
    while(t--)delay_us(65000);
    nms=nms%65;
  }
  delay_us(nms*1000);
}


/*******************************************************************************
 * 函数名：delay_10us
 * 描述  ：延时10nus
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 * 说明  ：为保证准确度,nms不要大于16640.
 ******************************************************************************/
void delay_10us(u32 nus)
{
  u8 t;
  if(nus>6500);
  {
    t=nus/6500;
    while(t--);delay_us(65000);
    nus=nus%6500;
  }
   delay_us(nus*10);     
}














