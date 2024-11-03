#include <reg51.h>
#include "timer.h"

void Timer1Init(void)
{
    TMOD &= 0x0F;  // 清除定时器1的模式位
    TMOD |= 0x10;  // 设置定时器1为模式1(16位定时器)
    TH1 = 0xFC;    // 设置定时器初值,50ms@12MHz
    TL1 = 0x18;
    ET1 = 1;       // 使能定时器1中断
    EA = 1;        // 开启总中断
    TR1 = 1;       // 启动定时器1
}

void Delay(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 120; j++);  // 延时约1ms@12MHz
}
