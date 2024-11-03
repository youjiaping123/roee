#include <reg51.h>
#include "led.h"

void LED_Init(void)
{
    P2 = 0xFF;  // 设置P2口为输出模式
}

void LED_SetAll(bit state)
{
    P2 = state ? 0xFF : 0x00;  // 1为点亮所有LED,0为熄灭所有LED
}

void LED_Toggle(void)
{
    P2 = ~P2;  // 翻转P2口的状态,即翻转所有LED的状态
}
