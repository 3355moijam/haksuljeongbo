#pragma once
#include "Subject.h"


class ClockTimer : public Subject<ClockTimer>
{
private:
	Stopwatch  m_sw;
	int m_nHour, m_nMinute, m_nSecond;
public:
	ClockTimer();

	virtual int GetHour();
	virtual int GetMinute();
	virtual int GetSecond();

	void Tick();
};

inline ClockTimer::ClockTimer() : m_sw(), m_nHour(0), m_nMinute(0), m_nSecond(0)
{
	m_sw.start();
}

inline int ClockTimer::GetHour()
{
	//m_sw.stop();
	int n = m_sw.getElapsedTime() / CLOCKS_PER_SEC;
	m_nHour = n / 360;
	return m_nHour;
}

inline int ClockTimer::GetMinute()
{
	//m_sw.stop();
	int n = m_sw.getElapsedTime() / CLOCKS_PER_SEC;
	m_nMinute = n / 60 % 60;
	return m_nMinute;
}

inline int ClockTimer::GetSecond()
{
	//m_sw.stop();
	int n = m_sw.getElapsedTime() / CLOCKS_PER_SEC;
	m_nSecond = n % 60;
	return m_nSecond;
}

inline void ClockTimer::Tick()
{
	m_sw.stop();
	GetHour();
	GetMinute();
	GetSecond();
	
	Notify();
}
