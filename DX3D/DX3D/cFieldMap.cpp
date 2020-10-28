#include "stdafx.h"
#include "cFieldMap.h"
#include <DxErr.h>
#pragma comment(lib, "DxErr.lib")
int (WINAPIV * __vsnprintf)(char *, size_t, const char*, va_list) = _vsnprintf;

cFieldMap::cFieldMap(): m_nWidthSpace(0), m_nDepthSpace(0), m_nNumVertexWidth(0), m_nNumVertexDepth(0), m_nWidth(0),
                        m_nDepth(0),
                        m_pVertexBuffer(nullptr),
                        m_pIndexBuffer(nullptr),
                        m_pMesh(nullptr),
                        m_pTexture(nullptr), m_stMtl({})
{
}

cFieldMap::~cFieldMap()
{
	SafeRelease(m_pVertexBuffer);
	SafeRelease(m_pIndexBuffer);
	SafeRelease(m_pMesh);
	SafeRelease(m_pTexture);
}
float Lerp(float a, float b, float t)
{
	return a - (a*t) + (b*t);
}
bool cFieldMap::GetHeight(float x, float& y, float z)
{
	//D3DXVECTOR3 vRayPos(x, y + 50, z);
	//D3DXVECTOR3 vRayDir(0, -1, 0);

	//BOOL isHit = false;
	//DWORD dwFaceIndex;
	//FLOAT fU, fV, fDist;
	//D3DXIntersect(m_pMesh, &vRayPos, &vRayDir, &isHit, &dwFaceIndex, &fU, &fV, &fDist, NULL, NULL);
	//if(isHit)
	//{
	//	y = vRayPos.y - fDist + 0.9f;
	//}
	//
	//return isHit;

	if(x <= 0.0f || z <= 0.0f || x >= m_nWidth || z >= m_nDepth)
	{
		y = 0.9f;
		return true;
	}
	int nX = x;
	int nZ = m_nNumVertexDepth - 1 - ceil(z);

	float fDeltaX = x - nX;
	float fDeltaZ = ceil(z) - z;
	
	int _0 = (nZ + 0) * m_nNumVertexWidth + nX + 0;
	int _1 = (nZ + 1) * m_nNumVertexWidth + nX + 0;
	int _2 = (nZ + 1) * m_nNumVertexWidth + nX + 1;
	int _3 = (nZ + 0) * m_nNumVertexWidth + nX + 1;

	if (fDeltaX + fDeltaZ < 1.0f)
	{
		D3DXVECTOR3 v01 = m_vecVertex[_1].p - m_vecVertex[_0].p;
		D3DXVECTOR3 v03 = m_vecVertex[_3].p - m_vecVertex[_0].p;
		y = m_vecVertex[_0].p.y + (v01 * fDeltaZ + v03 * fDeltaX).y;
		y += 0.9f;
		return true;
	}
	else
	{
		fDeltaX = 1.0f - fDeltaX;
		fDeltaZ = 1.0f - fDeltaZ;
		D3DXVECTOR3 v21 = m_vecVertex[_1].p - m_vecVertex[_2].p;
		D3DXVECTOR3 v23 = m_vecVertex[_3].p - m_vecVertex[_2].p;

		y = m_vecVertex[_2].p.y + (v21 * fDeltaZ + v23 * fDeltaX).y;
		y += 0.9f;
		return true;
	}
	
}

void cFieldMap::createMap(vector<int>& vecHeightMap, float fHeightMultiply, int nNumVertexWidth, int nNumVertexDepth, int nWidthSpace,
                          int nDepthSpace, LPDIRECT3DTEXTURE9 pTexture)
{
	m_nNumVertexDepth = nNumVertexDepth;
	m_nNumVertexWidth = nNumVertexWidth;
	m_nDepthSpace = nDepthSpace;
	m_nWidthSpace = nWidthSpace;
	m_nWidth = (m_nNumVertexWidth - 1) * m_nWidthSpace;
	m_nDepth = (m_nNumVertexDepth - 1) * m_nDepthSpace;
	m_pTexture = pTexture;
	//for (int i = 0; i < nW; ++i)
	//{
	//	m_vecHeightMap
	//}

	ST_PNT_VERTEX v;
	v.n = D3DXVECTOR3(0, 1, 0);
	float fU = 1.0f / (m_nNumVertexWidth - 1);
	float fV = 1.0f / (m_nNumVertexDepth - 1);
	
	for (int i = nNumVertexDepth - 1; i >= 0; --i) // Z
	{
		for (int j = 0; j < nNumVertexWidth; ++j) // X
		{
			v.p.x = j * m_nWidthSpace;
			v.p.y = vecHeightMap[i * m_nNumVertexWidth + j] * fHeightMultiply;
			v.p.z = i * m_nDepthSpace;

			v.t.x = j * fU;
			v.t.y = 1.0f - i * fV;

			m_vecVertex.push_back(v);
		}
	}

	for (int i = 0; i < m_nNumVertexDepth - 1; ++i)
	{
		for (int j = 0; j < m_nNumVertexWidth - 1; ++j)
		{
			//m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 0));
			//m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 1));
			//m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 0));

			//m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 0));
			//m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 1));
			//m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 1));

			{
				m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 0));
				m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 1));
				m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 0));

				m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 1));
				m_vecIndex.push_back((i + 1) * m_nNumVertexWidth + (j + 0));
				m_vecIndex.push_back((i + 0) * m_nNumVertexWidth + (j + 1));
			}
		}
	}

	// 노멀 추가 필요

	for (int z = 1; z < m_nNumVertexDepth - 1; ++z)
	{
		for (int x = 1; x < m_nNumVertexWidth - 1; ++x)
		{
			int left  = (z + 0) * m_nNumVertexWidth + x - 1;
			int right = (z + 0) * m_nNumVertexWidth + x + 1;

			int up	  = (z + 1) * m_nNumVertexWidth + x;
			int down  = (z - 1) * m_nNumVertexWidth + x;

			D3DXVECTOR3 leftToRight = m_vecVertex[right].p - m_vecVertex[left].p;
			D3DXVECTOR3 downToUp = m_vecVertex[up].p - m_vecVertex[down].p;

			D3DXVECTOR3 normal;
			D3DXVec3Cross(&normal, &downToUp, &leftToRight);
			D3DXVec3Normalize(&normal, &normal);

			int nIndex = z * m_nNumVertexWidth + x;
			m_vecVertex[nIndex].n = normal;
		}
	}
	
	//return;
	DWORD dw = m_vecIndex.size() / 3;
	HRESULT result = D3DXCreateMeshFVF
	(
		dw, 
		m_vecVertex.size(), 
		D3DXMESH_MANAGED | D3DXMESH_32BIT,
		ST_PNT_VERTEX::FVF, 
		g_pD3DDevice, 
		&m_pMesh
	);
	fprintf(stderr, "Error: %s error description: %s\n",
		DXGetErrorStringA(result), DXGetErrorDescriptionA(result));
	//DXGetErrorString(result);
	//DXGetErrorDescription(result);
	
	ST_PNT_VERTEX* pVertex = nullptr;
	m_pMesh->LockVertexBuffer(0, (LPVOID*)&pVertex);
	memcpy(pVertex, &m_vecVertex[0], m_vecVertex.size() * sizeof ST_PNT_VERTEX);
	m_pMesh->UnlockVertexBuffer();

	DWORD* pIndex = nullptr;
	m_pMesh->LockIndexBuffer(0, (LPVOID*)&pIndex);
	memcpy(pIndex, &m_vecIndex[0], m_vecIndex.size() * sizeof DWORD);
	m_pMesh->UnlockIndexBuffer();


	m_stMtl.Ambient  = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	m_stMtl.Diffuse  = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
}

void cFieldMap::render()
{
	if (m_pMesh)
	{
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
		g_pD3DDevice->SetMaterial(&m_stMtl);
		g_pD3DDevice->SetTexture(0, m_pTexture);
		m_pMesh->DrawSubset(0);
		//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

		g_pD3DDevice->SetTexture(0, 0);
	}
}

void cFieldMap::setFrustum()
{
	D3DVIEWPORT9 vp;
	D3DXMATRIXA16 matProj, matView;

	g_pD3DDevice->GetViewport(&vp);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);

	vector<D3DXVECTOR3> vecFrustumVertex;
	vecFrustumVertex.emplace_back(-1, -1, 0);
	vecFrustumVertex.emplace_back(-1,  1, 0);
	vecFrustumVertex.emplace_back( 1,  1, 0);
	vecFrustumVertex.emplace_back( 1, -1, 0);

	vecFrustumVertex.emplace_back(-1, -1, 1);
	vecFrustumVertex.emplace_back(-1,  1, 1);
	vecFrustumVertex.emplace_back( 1,  1, 1);
	vecFrustumVertex.emplace_back( 1, -1, 1);

	for (auto&& value : vecFrustumVertex)
	{
		//D3DXVec3Unproject(&value, &value, &vp, nullptr, nullptr, nullptr);
		D3DXVec3Unproject(&value, &value, nullptr, &matProj, &matView, nullptr);
	}
	D3DXPlaneFromPoints(&m_stLeft  , &vecFrustumVertex[4], &vecFrustumVertex[5], &vecFrustumVertex[1]);
	D3DXPlaneFromPoints(&m_stRight , &vecFrustumVertex[3], &vecFrustumVertex[2], &vecFrustumVertex[6]);
	D3DXPlaneFromPoints(&m_stTop   , &vecFrustumVertex[1], &vecFrustumVertex[5], &vecFrustumVertex[6]);
	D3DXPlaneFromPoints(&m_stBottom, &vecFrustumVertex[3], &vecFrustumVertex[7], &vecFrustumVertex[4]);
	D3DXPlaneFromPoints(&m_stNear  , &vecFrustumVertex[0], &vecFrustumVertex[1], &vecFrustumVertex[2]);
	D3DXPlaneFromPoints(&m_stFar   , &vecFrustumVertex[7], &vecFrustumVertex[6], &vecFrustumVertex[5]);

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
	//
	//
	//	
	//	D3DXPlaneFromPoints(&stLeft  , &(lt), &(center * 01), &(lb));
	//	D3DXPlaneFromPoints(&stRight , &(center * 01), &(rt), &(rb));
	//	D3DXPlaneFromPoints(&stTop   , &(center * 01), &(lt), &(rt));
	//	D3DXPlaneFromPoints(&stBottom, &(center * 01), &(rb), &(lb));
	//
	//
	//	D3DXVECTOR3 vDirlb = lb - center;
	//	D3DXVec3Normalize(&vDirlb, &vDirlb);
	//
	//	D3DXVECTOR3 vDirlt = lt - center;
	//	D3DXVec3Normalize(&vDirlt, &vDirlt);
	//
	//	D3DXVECTOR3 vDirrt = rt - center;
	//	D3DXVec3Normalize(&vDirrt, &vDirrt);
	//
	//	D3DXVECTOR3 a, b, c;
	//	a = (center + vDirlb * 1);
	//	b = (center + vDirlt * 1);
	//	c = (center + vDirrt * 1);
	//	D3DXPlaneFromPoints(&stNear  , &a, &b, &c);
	//
	//	a = (center + vDirlb * 20);
	//	b = (center + vDirlt * 20);
	//	c = (center + vDirrt * 20);
	//	D3DXPlaneFromPoints(&stFar, &a, &c, &b);
	//}


	//for (int i = 0; i < m_vecSphere.size(); ++i)
	//{
	//	D3DXVECTOR3 vPos = m_vecSphere[i]->getPosition();
	//	if (
	//		D3DXPlaneDotCoord(&stLeft, &vPos) < 0 &&
	//		D3DXPlaneDotCoord(&stRight, &vPos) < 0 &&
	//		D3DXPlaneDotCoord(&stTop, &vPos) < 0 &&
	//		D3DXPlaneDotCoord(&stBottom, &vPos) < 0 &&
	//		D3DXPlaneDotCoord(&stNear, &vPos) < 0 &&
	//		D3DXPlaneDotCoord(&stFar, &vPos) < 0
	//		)
	//		m_vecIsCull[i] = false;
	//	else
	//		m_vecIsCull[i] = true;
	//}
}

void cFieldMap::setCulling()
{
	setFrustum();
	
	vector<DWORD> vecIndex;
	set<DWORD> vecOutScene;

	for (size_t i = 0; i < m_vecVertex.size(); ++i)
	{
			D3DXVECTOR3 vPos = m_vecVertex[i].p;
		if (
			D3DXPlaneDotCoord(&m_stLeft  , &vPos) > 0 ||
			D3DXPlaneDotCoord(&m_stRight , &vPos) > 0 ||
			D3DXPlaneDotCoord(&m_stTop   , &vPos) > 0 ||
			D3DXPlaneDotCoord(&m_stBottom, &vPos) > 0 ||
			D3DXPlaneDotCoord(&m_stNear  , &vPos) > 0 ||
			D3DXPlaneDotCoord(&m_stFar   , &vPos) > 0
			)
			vecOutScene.emplace(i);
	}

	for (size_t i = 0; i < m_vecIndex.size(); i += 3)
	{
		if
		(
			vecOutScene.find(m_vecIndex[i + 0]) == vecOutScene.end() ||
			vecOutScene.find(m_vecIndex[i + 1]) == vecOutScene.end() ||
			vecOutScene.find(m_vecIndex[i + 2]) == vecOutScene.end()
		)
		{
			vecIndex.push_back(m_vecIndex[i + 0]);
			vecIndex.push_back(m_vecIndex[i + 1]);
			vecIndex.push_back(m_vecIndex[i + 2]);
		}
	}


	
	DWORD* pIndex = nullptr;
	m_pMesh->LockIndexBuffer(0, (LPVOID*)&pIndex);
	ZeroMemory(pIndex, m_vecIndex.size() * sizeof DWORD);
	if (!vecIndex.empty())
		memcpy(pIndex, &vecIndex[0], vecIndex.size() * sizeof DWORD);
	m_pMesh->UnlockIndexBuffer();
}

void cFieldMap::unsetCulling()
{
	DWORD* pIndex = nullptr;
	m_pMesh->LockIndexBuffer(0, (LPVOID*)&pIndex);
	ZeroMemory(pIndex, m_vecIndex.size() * sizeof DWORD);
	memcpy(pIndex, &m_vecIndex[0], m_vecIndex.size() * sizeof DWORD);
	m_pMesh->UnlockIndexBuffer();
}

