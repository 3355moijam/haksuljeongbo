#pragma once

#define g_pTimeManager CTimeManager::getInstance()

class CTimeManager
{
private:
	Singletone(CTimeManager);

private:
	DWORD	m_dwLastUpdateTime;
	float	m_fElapsedTime;

public:
	void update();
	float GetElapsedTime();
	float GetLastUpdateTime();
	
};
