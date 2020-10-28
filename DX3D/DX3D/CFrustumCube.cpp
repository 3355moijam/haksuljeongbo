#include "stdafx.h"
#include "CFrustumCube.h"
#include "cSphere.h"

CFrustumCube::CFrustumCube()
{
	//vector<D3DXVECTOR3> m_vecVertex;
	//D3DXVECTOR3 vScale(1000, 1000, 1000);
	//D3DXVECTOR3 vPos(0, 500, 0);

	D3DXMATRIXA16 matS, matT, matWorld;

	D3DXMatrixScaling(&matS, 30, 30, 30);
	D3DXMatrixTranslation(&matT, 0, 15, 0);

	matWorld = matS * matT;

	{
		m_vecVertex.resize(8);

		m_vecVertex[0].x = -0.5f; m_vecVertex[0].y = -0.5f; m_vecVertex[0].z = -0.5f;
		m_vecVertex[1].x = -0.5f; m_vecVertex[1].y =  0.5f; m_vecVertex[1].z = -0.5f;
		m_vecVertex[2].x =  0.5f; m_vecVertex[2].y =  0.5f; m_vecVertex[2].z = -0.5f;
		m_vecVertex[3].x =  0.5f; m_vecVertex[3].y = -0.5f; m_vecVertex[3].z = -0.5f;

		m_vecVertex[4].x = -0.5f; m_vecVertex[4].y = -0.5f; m_vecVertex[4].z =  0.5f;
		m_vecVertex[5].x = -0.5f; m_vecVertex[5].y =  0.5f; m_vecVertex[5].z =  0.5f;
		m_vecVertex[6].x =  0.5f; m_vecVertex[6].y =  0.5f; m_vecVertex[6].z =  0.5f;
		m_vecVertex[7].x =  0.5f; m_vecVertex[7].y = -0.5f; m_vecVertex[7].z =  0.5f;
	}

	for (auto & vertex : m_vecVertex)
	{
		D3DXVec3TransformCoord(&vertex, &vertex, &matWorld);
	}


	//3중 반복으로 큐브 만들기
	for (int i = m_vecVertex[0].x; i <= m_vecVertex[6].x; i += 2)
	{
		for (int j = m_vecVertex[0].y; j <= m_vecVertex[6].y; j += 2)
		{
			for (int k = m_vecVertex[0].z; k <= m_vecVertex[6].z; k += 2)
			{
				m_vecSphere.emplace_back(new cSphere(i, j, k));
			}
		}
	}
	m_vecIsCull.resize(m_vecSphere.size());
	
}

CFrustumCube::~CFrustumCube()
{
	for (auto * sphere : m_vecSphere)
	{
		SafeDelete(sphere);
	}
}

void CFrustumCube::culling()
{
	D3DVIEWPORT9 vp;
	D3DXMATRIXA16 matProj, matView, matViewInv;
	D3DXPLANE stLeft, stRight, stTop, stBottom, stNear, stFar;

	
	g_pD3DDevice->GetViewport(&vp);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);

	vector<D3DXVECTOR3> vecFrustumVertex;
	vecFrustumVertex.emplace_back(0, vp.Height, 0);
	vecFrustumVertex.emplace_back(0, 0, 0);
	vecFrustumVertex.emplace_back(vp.Width, 0, 0);
	vecFrustumVertex.emplace_back(vp.Width, vp.Height, 0);

	vecFrustumVertex.emplace_back(0, vp.Height,			.95f);
	vecFrustumVertex.emplace_back(0, 0,					.95f);
	vecFrustumVertex.emplace_back(vp.Width, 0,			.95f);
	vecFrustumVertex.emplace_back(vp.Width, vp.Height,	.95f);

	for (auto && value : vecFrustumVertex)
	{
		//D3DXVec3Unproject(&value, &value, &vp, &matProj, nullptr, nullptr);
		D3DXVec3Unproject(&value, &value, &vp, &matProj, &matView, nullptr);
	}
	D3DXPlaneFromPoints(&stLeft		, &vecFrustumVertex[4], &vecFrustumVertex[5], &vecFrustumVertex[1]);
	D3DXPlaneFromPoints(&stRight	, &vecFrustumVertex[3], &vecFrustumVertex[2], &vecFrustumVertex[6]);
	D3DXPlaneFromPoints(&stTop		, &vecFrustumVertex[1], &vecFrustumVertex[5], &vecFrustumVertex[6]);
	D3DXPlaneFromPoints(&stBottom	, &vecFrustumVertex[3], &vecFrustumVertex[7], &vecFrustumVertex[4]);
	D3DXPlaneFromPoints(&stNear		, &vecFrustumVertex[0], &vecFrustumVertex[1], &vecFrustumVertex[2]);
	D3DXPlaneFromPoints(&stFar		, &vecFrustumVertex[7], &vecFrustumVertex[6], &vecFrustumVertex[5]);
	
	//
	//{
	//	D3DXVECTOR3 center(0, 0, 0);
	//	D3DXVECTOR3 lt(0, 0, 0);
	//	D3DXVECTOR3 rt(vp.Width, 0, 0);
	//	D3DXVECTOR3 lb(0, vp.Height, 0);
	//	D3DXVECTOR3 rb(vp.Width, vp.Height, 0);
	//	D3DXVec3Unproject(&lt, &lt, &vp, &matProj, &matView, nullptr);
	//	D3DXVec3Unproject(&rt, &rt, &vp, &matProj, &matView, nullptr);
	//	D3DXVec3Unproject(&lb, &lb, &vp, &matProj, &matView, nullptr);
	//	D3DXVec3Unproject(&rb, &rb, &vp, &matProj, &matView, nullptr);
	//	D3DXVec3Unproject(&center, &center, nullptr, nullptr, &matView, nullptr);



	//	
	//	D3DXPlaneFromPoints(&stLeft  , &(lt), &(center * 01), &(lb));
	//	D3DXPlaneFromPoints(&stRight , &(center * 01), &(rt), &(rb));
	//	D3DXPlaneFromPoints(&stTop   , &(center * 01), &(lt), &(rt));
	//	D3DXPlaneFromPoints(&stBottom, &(center * 01), &(rb), &(lb));


	//	D3DXVECTOR3 vDirlb = lb - center;
	//	D3DXVec3Normalize(&vDirlb, &vDirlb);

	//	D3DXVECTOR3 vDirlt = lt - center;
	//	D3DXVec3Normalize(&vDirlt, &vDirlt);

	//	D3DXVECTOR3 vDirrt = rt - center;
	//	D3DXVec3Normalize(&vDirrt, &vDirrt);
	//
	//	D3DXVECTOR3 a, b, c;
	//	a = (center + vDirlb * 1);
	//	b = (center + vDirlt * 1);
	//	c = (center + vDirrt * 1);
	//	D3DXPlaneFromPoints(&stNear  , &a, &b, &c);

	//	a = (center + vDirlb * 20);
	//	b = (center + vDirlt * 20);
	//	c = (center + vDirrt * 20);
	//	D3DXPlaneFromPoints(&stFar, &a, &c, &b);
	//}


	for (int i = 0; i < m_vecSphere.size(); ++i)
	{
		D3DXVECTOR3 vPos = m_vecSphere[i]->getPosition();
		if (
			D3DXPlaneDotCoord(&stLeft, &vPos) < 0 &&
			D3DXPlaneDotCoord(&stRight, &vPos) < 0 &&
			D3DXPlaneDotCoord(&stTop, &vPos) < 0 &&
			D3DXPlaneDotCoord(&stBottom, &vPos) < 0 &&
			D3DXPlaneDotCoord(&stNear, &vPos) < 0 &&
			D3DXPlaneDotCoord(&stFar, &vPos) < 0
			)
			m_vecIsCull[i] = false;
		else
			m_vecIsCull[i] = true;
	}
}

void CFrustumCube::render()
{
	if(!m_vecSphere.empty())
	{
		for (int i = 0; i < m_vecSphere.size(); ++i)
		{
			if (m_vecIsCull[i])
				continue;
			m_vecSphere[i]->render();
		}
	}
}
