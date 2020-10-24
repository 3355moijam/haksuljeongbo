#include "stdafx.h"
#include "cGrid2.h"

#include "cPyramid.h"

cGrid2::cGrid2(): m_stMtl({}), m_pMesh(nullptr)
{
}

cGrid2::~cGrid2()
{
	for (auto & p : m_vecPyramid)
	{
		SafeDelete(p)
	}
	m_vecPyramid.clear();
	SafeRelease(m_pMesh);
}

void cGrid2::setup(int nNumHalfTile, float fInterval)
{
	m_stMtl.Ambient	 = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse	 = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	
	float fMax = nNumHalfTile * fInterval;
	float fMin = -fMax;
	ST_PNC_VERTEX v;
	v.n = D3DXVECTOR3(0, 1, 0);
	for (unsigned int i = 1; i <= nNumHalfTile; ++i)
	{
		//if (i % 5 == 0)
		//{
		//	v.c = D3DCOLOR_XRGB(255, 255, 255);
		//}
		//else
		//{
		//	v.c = D3DCOLOR_XRGB(128, 128, 128);
		//}
		v.p = D3DXVECTOR3(fMin, 0, i*fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, i*fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMin, 0, -i*fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i*fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i*fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i*fInterval, 0, fMax);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i*fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i*fInterval, 0, fMax);
		m_vecVertex.push_back(v);

	}
	v.c = D3DCOLOR_XRGB(60, 60, 60);
	for (unsigned int j = 0; j < nNumHalfTile * 2; ++j)
	{
		for (unsigned int i = 0; i < nNumHalfTile * 2; ++i)
		{
			v.p = D3DXVECTOR3(fMin + i * fInterval, 0, fMax - j * fInterval); m_vecIndex.push_back(v);
			v.p = D3DXVECTOR3(fMin + (i + 1) * fInterval, 0, fMax - j * fInterval); m_vecIndex.push_back(v);
			v.p = D3DXVECTOR3(fMin + i * fInterval, 0, fMax - (j + 1) * fInterval); m_vecIndex.push_back(v);

			v.p = D3DXVECTOR3(fMin + i * fInterval, 0, fMax - (j + 1) * fInterval); m_vecIndex.push_back(v);
			v.p = D3DXVECTOR3(fMin + (i + 1) * fInterval, 0, fMax - j * fInterval); m_vecIndex.push_back(v);
			v.p = D3DXVECTOR3(fMin + (i + 1)* fInterval, 0, fMax - (j + 1)* fInterval); m_vecIndex.push_back(v);
		}
	}
	
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax); m_vecVertex.push_back(v);

	cPyramid* pPyramid = NULL;
	D3DXMATRIXA16 matR;

	pPyramid = new cPyramid;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2);
	pPyramid->setup(D3DCOLOR_XRGB(255, 0, 0), matR);
	m_vecPyramid.push_back(pPyramid);

	pPyramid = new cPyramid;
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	pPyramid->setup(D3DCOLOR_XRGB(0, 255, 0), matR);
	m_vecPyramid.push_back(pPyramid);

	pPyramid = new cPyramid;
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2);
	pPyramid->setup(D3DCOLOR_XRGB(0, 0, 255), matR);
	m_vecPyramid.push_back(pPyramid);


	D3DXCreateMeshFVF(m_vecIndex.size() / 3, m_vecIndex.size(), D3DXMESH_MANAGED, ST_PNC_VERTEX::FVF, g_pD3DDevice, &m_pMesh);
	ST_PNC_VERTEX * pVertex = NULL;
	m_pMesh->LockVertexBuffer(0, (LPVOID*)&pVertex);
	memcpy(pVertex, &m_vecIndex[0], m_vecIndex.size() * sizeof ST_PNC_VERTEX);
	m_pMesh->UnlockVertexBuffer();

	WORD* pIndex = NULL;
	m_pMesh->LockIndexBuffer(0, (LPVOID*)&pIndex);
	for (int i = 0; i < m_vecIndex.size(); ++i)
	{
		pIndex[i] = i;
	}
	m_pMesh->UnlockIndexBuffer();
}

void cGrid2::render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetMaterial(&m_stMtl);
	g_pD3DDevice->SetTexture(0, 0);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);

	g_pD3DDevice->SetFVF(ST_PNC_VERTEX::FVF);
	//g_pD3DDevice->DrawPrimitiveUP
	//(
	//	D3DPT_LINELIST,
	//	m_vecVertex.size() / 2,
	//	&m_vecVertex[0],
	//	sizeof ST_PNC_VERTEX
	//);

	//g_pD3DDevice->DrawPrimitiveUP
	//(
	//	D3DPT_TRIANGLELIST,
	//	m_vecIndex.size() / 3,
	//	&m_vecIndex[0],
	//	sizeof ST_PNC_VERTEX
	//);

	m_pMesh->DrawSubset(0);
	
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	for (auto & p : m_vecPyramid)
	{
		p->render();
	}
	
}

bool cGrid2::GetHeight(float x, float& y, float z)
{
	D3DXVECTOR3 vRayPos(x, y + 1, z);
	D3DXVECTOR3 vRayDir(0, -1, 0);

	for (int i = 0; i < m_vecIndex.size(); i += 3)
	{
		float u, v, f;
		if (D3DXIntersectTri
		(
			&m_vecIndex[i + 0].p,
			&m_vecIndex[i + 1].p,
			&m_vecIndex[i + 2].p,
			&vRayPos,
			&vRayDir,
			&u, &v,
			&f
		))
		{
			if (f > 3.0f + 0.9f)
				return false;
			y += 1 - f + 0.9f;
			return true;
		}
	}
	return false;
}
