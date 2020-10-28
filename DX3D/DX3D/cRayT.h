﻿#pragma once

class cRayT
{
public:
	cRayT();
	~cRayT();

	enum eRaySpace { E_NONE, E_VIEW, E_WORLD, E_LOCAL };
protected:
	D3DXVECTOR3		m_vOrg;
	D3DXVECTOR3		m_vDir;
	eRaySpace		m_eRaySpace;
public:
	static cRayT RayAtViewSpace(int nScreenX, int nScreenY);
	static cRayT RayAtWorldSpace(int nScreenX, int nScreenY);

	bool IntersectTri(IN D3DXVECTOR3& v0, IN D3DXVECTOR3& v1, IN D3DXVECTOR3& v2, OUT D3DXVECTOR3& vPickedPosition);

	bool isPicked(ST_SPHERE* pSphere);
};