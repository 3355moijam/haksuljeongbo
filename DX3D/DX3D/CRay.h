#pragma once

class cGrid2;
class cSphere;

class CRay
{
public:
	CRay();
	~CRay();
	void setup(vector<cSphere*>* left, cGrid2* right);
	
private:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vDir;

	vector<cSphere*>*	m_vecLeftTarget;
	cGrid2*				m_RightTarget;

	void SetPosDir(float _x, float _y);
	bool SphereIntersect(cSphere* sphere);
public:
	cSphere* getLeftClickCheck(int _x, int _y);
	bool getRightClickCheck(int _x, int _y, D3DXVECTOR3& vRet);

	void render();

};
