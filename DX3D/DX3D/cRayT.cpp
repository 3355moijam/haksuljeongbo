﻿#include "stdafx.h"
#include "cRayT.h"

cRayT::cRayT(): m_eRaySpace(), m_vDir(0,0,0), m_vOrg(0,0,0)
{
}

cRayT::~cRayT()
{
}

cRayT cRayT::RayAtViewSpace(int nScreenX, int nScreenY)
{
	D3DVIEWPORT9	vp;
	g_pD3DDevice->GetViewport(&vp);

	D3DXMATRIXA16	matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);

	cRayT r;
	r.m_vDir.x = ((2.0f * nScreenX) / vp.Width - 1.0f) / matProj._11;
	r.m_vDir.y = ((-2.0f * nScreenY) / vp.Height + 1.0f) / matProj._22;
	r.m_vDir.z = 1.0f;

	r.m_eRaySpace = E_VIEW;

	return r;
}

cRayT cRayT::RayAtWorldSpace(int nScreenX, int nScreenY)
{
	cRayT r = cRayT::RayAtViewSpace(nScreenX, nScreenY);

	D3DXMATRIXA16 matView, matInvView;
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	D3DXMatrixInverse(&matInvView, NULL, &matView);

	D3DXVec3TransformCoord(&r.m_vOrg, &r.m_vOrg, &matInvView);
	D3DXVec3TransformNormal(&r.m_vDir, &r.m_vDir, &matInvView);

	D3DXVec3Normalize(&r.m_vDir, &r.m_vDir);
	r.m_eRaySpace = E_WORLD;

	return r;
}

bool cRayT::IntersectTri(D3DXVECTOR3& v0, D3DXVECTOR3& v1, D3DXVECTOR3& v2, D3DXVECTOR3& vPickedPosition)
{
	float u, v, f;
	bool b = D3DXIntersectTri(&v0, &v1, &v2, &m_vOrg, &m_vDir, &u, &v, &f);
	vPickedPosition = m_vOrg + f * m_vDir;
	return b;
}

bool cRayT::isPicked(ST_SPHERE* pSphere)
{
	cRayT r = (*this);
	D3DXMATRIXA16 matInvWorld;
	D3DXMatrixIdentity(&matInvWorld);
	matInvWorld._41 = -pSphere->vCenter.x;
	matInvWorld._42 = -pSphere->vCenter.y;
	matInvWorld._43 = -pSphere->vCenter.z;


	D3DXVec3TransformCoord(&r.m_vOrg, &r.m_vOrg, &matInvWorld);
	D3DXVec3TransformNormal(&r.m_vDir, &r.m_vDir, &matInvWorld);

	float vv = D3DXVec3Dot(&r.m_vDir, &r.m_vDir);
	float qv = D3DXVec3Dot(&r.m_vOrg, &r.m_vDir);
	float qq = D3DXVec3Dot(&r.m_vOrg, &r.m_vOrg);
	float rr = pSphere->fRaidus * pSphere->fRaidus;

	return qv * qv - vv * (qq - rr) > 0;
}
