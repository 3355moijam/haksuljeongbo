#pragma once

class cFrameCounter
{
public:
	cFrameCounter();
private:
	int m_nFPS;
	int m_nCount;
	time_t m_nStartTime;
	int m_nJunk;
public:
	void update();
	int GetFPS() { return m_nFPS; }
};
