#include "led.h"

#define LED_RCC 	RCC_AHB1Periph_GPIOC
#define LED_PORT 	GPIOC

void LED::Init(void)
{
	LED::ClockInit();
	LED::GpioInit();
}

void LED::On(LedColor color)
{
	GPIO_SetBits(LED_PORT,color);
}

void LED::Off(LedColor color)
{
	GPIO_ResetBits(LED_PORT,color);
}

void LED::Toggle(LedColor color)
{
	LED_PORT->ODR ^= color;
}

void LED::Flash(LedColor color,u8 times)
{
	u8 i;
	LED::Off(color);
	for(i=0;i<times;i++)
	{
		LED::On(color);
		TickTimer::DelayMs(100);
		LED::Off(color);
		TickTimer::DelayMs(100);
	}
}

void LED::ClockInit(void)
{
	RCC_AHB1PeriphClockCmd(LED_RCC,ENABLE);
}

void LED::GpioInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = 	GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = 	led_all;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(LED_PORT,&GPIO_InitStructure);
}

