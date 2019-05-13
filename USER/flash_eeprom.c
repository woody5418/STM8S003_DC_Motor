/********************************************************************
 *@file        flash_eeprom.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       eeprom初始化
 *******************************************************************/
#include "flash_eeprom.h"
#include "key.h"
#include "uart.h"
#include "tim1.h"

/*******************************************************************************
 * 函数名：Init_EEPROM
 * 描述  ：配置EEPROM的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 * 说明  : 每种型号的EEPROM的大小不一样，调用此函数的时候要注意将要写进的字节数组
         的大小是否超过该型号的EEPROM的地址。
         大容量的EEPROM的型号是STM8S208, STM8S207, STM8S007, STM8AF52Ax, STM8AF62Ax 
         EEPROM的地址是从0x004000到0x0047ff，共2048Byte,每个Block是128Byte,一共16个Block.
         BlockNum @ 1~16
         中容量的EEPROM的型号是STM8S105, STM8S005, STM8AF626x
         EEPROM的地址是从0x004000到0x0043ff，共1024Byte,每个Block是128Byte,一共8个Block.
         BlockNum @ 1~8
         小容量的EEPROM的型号是STM8S103, STM8S003, STM8S903 
         EEPROM的地址是从0x004000到0x00427f，共1024Byte,每个Block是64Byte,一共10个Block.
         BlockNum @ 1~10
 ******************************************************************************/
void Init_EEPROM(void)
{
    FLASH_DeInit();
    //Define flash programming time.
    //编程时间为标准编程时间的一半(1/2 tprog)
}
/*******************************************************************************
 * 函数名：FLASH_Read_Word
 * 描述  ：从FLASH 读取一个U8类型的数据
 * 输入  ：无
 * 输出  ：u8类型输出
 * 调用  ：外部调用
 ******************************************************************************/
u8 ReadEEPROM(void)
{ 
   u8 data;
   
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  data = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS);
  FLASH_Lock(FLASH_MEMTYPE_DATA);
  return data;
}
/*******************************************************************************
 * 函数名：WriteEEPROM
 * 描述  ：WriteEEPROM写一个U32类型的数据到EEPROM
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void WriteEEPROM(u8 data)
{ 
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // 解锁EEPROM
  FLASH_ProgramByte(FLASH_DATA_START_PHYSICAL_ADDRESS,data);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
} 

















