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
	D3DXMATRIXA16			m_matWorldTM;
	static int m_num;
public:
	bool open(string sFileName, string sFolder, float scale);
	void render();
	
};
