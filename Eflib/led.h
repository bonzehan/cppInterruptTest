#pragma once

#include "stm32f4xx.h"
#include "tick.h"

typedef enum
{
	led_red = GPIO_Pin_2,
	led_green = GPIO_Pin_1,
	led_blue = GPIO_Pin_0,
	led_all = (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2)
}LedColor;

class LED{
public:
	void Init(void);
	void On(LedColor color);
	void Off(LedColor color);
	void Toggle(LedColor color);
	void Flash(LedColor color,u8 times);
private:
	void ClockInit(void);
	void GpioInit(void);
};
