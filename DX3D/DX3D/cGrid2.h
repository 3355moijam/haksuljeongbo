#pragma once
#include "cPyramid.h"

class cGrid2
{
public:
	cGrid2();
	~cGrid2();
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	vector<cPyramid*>		m_vecPyramid;

public:
	void setup(int nNumHalfTile = 15, float fInterval = 1);
	void render();
};
