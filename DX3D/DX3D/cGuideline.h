#pragma once

class cPyramid;

class cGuideline
{
	
public:
	cGuideline();
	~cGuideline();

	void setup(D3DCOLOR c);
	void render();
	void Interpolation(float div);

private:
	vector<ST_PC_VERTEX>	m_RouteNode;
	vector<ST_PC_VERTEX>	m_ShortCut;
	vector<cPyramid*>		m_Gizmo;

public:
	vector<ST_PC_VERTEX>& getRouteNode() { return m_RouteNode; }
	vector<ST_PC_VERTEX>& getShortCut() { return m_ShortCut; }
};
