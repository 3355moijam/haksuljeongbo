#include "stdafx.h"
#include "CFrustum.h"

#include "cSphere.h"

CFrustum::CFrustum()
{
}

CFrustum::~CFrustum()
{
}

void CFrustum::Setup()
{
	//near
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3(-1,  1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3( 1,  1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3( 1, -1, 0));

	//far
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3(-1,  1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3( 1,  1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3( 1, -1, 1));

	m_vecPlane.resize(6);
	m_vecWorldVertex.resize(8);
}

void CFrustum::Update()
{
	D3DXMATRIXA16 matView, matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);

	for (int i = 0; i < m_vecProjVertex.size(); ++i)
	{
		D3DXVec3Unproject(
			&m_vecWorldVertex[i],
			&m_vecProjVertex[i],
			NULL,
			&matProj,
			&matView,
			nullptr);
	}

	D3DXPlaneFromPoints(&m_vecPlane[0], &m_vecWorldVertex[0], &m_vecWorldVertex[1], &m_vecWorldVertex[2]);
	D3DXPlaneFromPoints(&m_vecPlane[1], &m_vecWorldVertex[6], &m_vecWorldVertex[5], &m_vecWorldVertex[4]);
	D3DXPlaneFromPoints(&m_vecPlane[2], &m_vecWorldVertex[1], &m_vecWorldVertex[5], &m_vecWorldVertex[6]);
	D3DXPlaneFromPoints(&m_vecPlane[3], &m_vecWorldVertex[0], &m_vecWorldVertex[3], &m_vecWorldVertex[7]);
	D3DXPlaneFromPoints(&m_vecPlane[4], &m_vecWorldVertex[1], &m_vecWorldVertex[0], &m_vecWorldVertex[4]);
	D3DXPlaneFromPoints(&m_vecPlane[5], &m_vecWorldVertex[2], &m_vecWorldVertex[6], &m_vecWorldVertex[7]);

	
}

bool CFrustum::IsIn(cSphere* pSphere)
{
	
	for (auto & plane : m_vecPlane)
	{
		if (D3DXPlaneDotCoord(&plane, &pSphere->getPosition()) > pSphere->getRadius())
			return false;
	}
	return true;
}
