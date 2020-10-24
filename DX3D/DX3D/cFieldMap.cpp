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

	if(x < 0.0f || z < 0.0f || x >= m_nWidth || z >= m_nDepth)
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
