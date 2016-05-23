#include "timer.h"

class Interrupt{
public:
	Interrupt(void);
	static void Register(int interrupt_number, Interrupt* intThisPtr);
	static void Interrupt_0(void);
	static void Interrupt_1(void);
	static void Interrupt_2(void);
	virtual void ISR(void)=0;
private:
	static Interrupt* ISRVectorTable[MAX_INTERRUPTS];

};

void Interrupt::Interrupt_0(void)
{
	ISRVectorTable[0]->ISR();
}

void Interrupt::Interrupt_1(void)
{
	ISRVectorTable[1]->ISR();
}

void Interrupt::Interrupt_2(void)
{
	ISRVectorTable[2]->ISR();
}

void Interrupt::Register(int interrupt_number, Interrupt* intThisPtr)
{
	ISRVectorTable[interrupt_number] = intThisPtr;
}

class TimerInterrupt:public Interrupt{
public:
	TimerInterrupt(Timer* ownerptr);
	virtual void ISR(void);
private:
	Timer* InterruptOwnerPtr;
};

class Timer{
friend class TimerInterrupt;

public:
	Timer(void);
	int GetCount(void){ return Count;}
private:
	TimerInterrupt* InterruptPtr;
	int Count;
};


Timer::Timer(void)
{
	InterruptPtr = new TimerInterrupt(this);
}

#define TIMER_INTERRUPT_NUMBER 0
TimerInterrupt::TimerInterrupt(Timer* owner)
{
	InterruptOwnerPtr = owner;
	Interrupt::Register(TIMER_INTERRUPT_NUMBER,this);
}
