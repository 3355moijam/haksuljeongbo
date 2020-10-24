#pragma once

class cMtlTex;

class CObj_X
{
public:
	CObj_X();
	~CObj_X();
private:
	LPD3DXMESH				m_pMesh;
	vector<cMtlTex>			m_vecMtlTex;

public:
	bool open(string sFileName, string sFolder);
	void render();
	
};
