#include "main.h"

LED led;

int main(void)
{
	SystemInit();
	TickTimer::Init();
	led.Init();
    while(1)
    {
    	led.On(led_all);
    	TickTimer::DelayMs(100);
    	led.Off(led_all);
    	TickTimer::DelayMs(200);
    }
}
