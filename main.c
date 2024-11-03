#include <reg51.h>
#include "led.h"
#include "timer.h"

sbit K1 = P3^2;  // K1按键连接到P3.2

bit flashing = 0;  // LED闪烁标志

// 定时器1中断服务程序
void Timer1_ISR(void) __interrupt(3)
{
    static unsigned char count = 0;
    
    if(flashing)
    {
        count++;
        if(count >= 10)  // 0.5秒
        {
            count = 0;
            LED_Toggle();  // 翻转LED状态
        }
    }
}

void main(void)
{
    LED_Init();  // 初始化LED
    Timer1Init();  // 初始化定时器1
    
    LED_SetAll(1);  // 点亮所有LED
    
    while(1)
    {
        if(K1 == 0)  // 检测K1是否按下
        {
            Delay(20);  // 消抖
            if(K1 == 0)
            {
                flashing = 1;  // 设置闪烁标志
                while(!K1);  // 等待按键释放
            }
        }
    }
}
