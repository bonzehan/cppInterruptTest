#include "tick.h"



__IO u32 TickTimer::_counter;

void TickTimer::Init(void)
{
	SysTick_Config(SystemCoreClock/1000);
	TickTimer::_counter=0;
}

u32 TickTimer::GetTimeMs(void)
{
	return TickTimer::_counter;
}

void TickTimer::DelayMs(u32 milliseconds)
{
	u32 target;
	target = TickTimer::GetTimeMs() +  milliseconds;
	while( TickTimer::GetTimeMs() < target )
	{
		__NOP();
	}
}

extern "C" void SysTick_Handler(void)
{
	TickTimer::_counter++;
}
