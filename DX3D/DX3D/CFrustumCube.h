#pragma once

class cSphere;

class CFrustumCube
{
private:
	vector<cSphere*>		m_vecSphere;
	vector<D3DXVECTOR3>		m_vecVertex;
	vector<bool>			m_vecIsCull;
public:
	CFrustumCube();
	~CFrustumCube();

	void culling();
	void render();
	
};
