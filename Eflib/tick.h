#pragma once

#include "stm32f4xx.h"

class TickTimer{
public:
	static void Init(void);
	__IO static u32 _counter;
	static void DelayMs(u32 milliseconds);
	static u32 GetTimeMs(void);
};
