#pragma once
#include "cPyramid.h"

class cGrid2 : public iMap
{
public:
	cGrid2();
	~cGrid2();
private:
	vector<ST_PNC_VERTEX>	m_vecVertex;
	vector<ST_PNC_VERTEX>	m_vecIndex;
	vector<cPyramid*>		m_vecPyramid;
	D3DMATERIAL9			m_stMtl;
	LPD3DXMESH				m_pMesh;
public:
	void setup(int nNumHalfTile = 15, float fInterval = 1);
	void render();
	bool GetHeight(float x, float& y, float z) override;
	LPD3DXMESH& GetMesh() { return m_pMesh; }
};
