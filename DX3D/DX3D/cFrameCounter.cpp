#include "stdafx.h"
#include "cFrameCounter.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


cFrameCounter::cFrameCounter(): m_nFPS(0), m_nCount(0), m_nJunk(0)
{
	m_nStartTime = timeGetTime();
}

void cFrameCounter::update()
{
	m_nCount++;
	time_t nCurrentTime = timeGetTime();
	if ( nCurrentTime >= (m_nStartTime + 1000 /*- m_nJunk*/))
	{
		m_nFPS = m_nCount;
		m_nCount = 0;
		m_nJunk = nCurrentTime - m_nStartTime - 1000;
		m_nStartTime = nCurrentTime;
	}
}
