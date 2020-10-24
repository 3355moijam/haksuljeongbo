#include "stdafx.h"
#include "CObj_X.h"

#include "cMtlTex.h"

CObj_X::CObj_X(): m_pMesh(nullptr)
{
}

CObj_X::~CObj_X()
{
	SafeRelease(m_pMesh);

}

bool CObj_X::open(string sFileName, string sFolder)
{
	if (m_pMesh)
		return false;
	string sFolderLink = sFolder + string("/");
	ID3DXBuffer* adjBuffer = 0;
	ID3DXBuffer* mtlBuffer = 0;

	DWORD numMtls = 0;
	HRESULT hr;

	D3DXLoadMeshFromXA
	(
		(sFolderLink + sFileName).c_str(),
		D3DXMESH_MANAGED,
		g_pD3DDevice,
		&adjBuffer,
		&mtlBuffer,
		0,
		&numMtls,
		&m_pMesh
	);
	if (mtlBuffer != 0 && numMtls != 0)
	{
		D3DXMATERIAL* pMtls = (D3DXMATERIAL*)mtlBuffer->GetBufferPointer();
		m_vecMtlTex.resize(numMtls);
		for (int i = 0; i < numMtls; ++i)
		{
			pMtls[i].MatD3D.Ambient = pMtls[i].MatD3D.Diffuse;

			m_vecMtlTex[i].SetMaterial(pMtls[i].MatD3D);
			if (pMtls[i].pTextureFilename)
			{
				m_vecMtlTex[i].SetTexture(g_pTextureManager.GetTexture(sFolderLink + pMtls[i].pTextureFilename));
			}
			else
				m_vecMtlTex[i].SetTexture(0);
		}
	}
	SafeRelease(mtlBuffer);
	SafeRelease(adjBuffer);
	return true;
}

void CObj_X::render()
{
	if(m_pMesh)
	{
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		for (int i = 0; i < m_vecMtlTex.size(); ++i)
		{
			g_pD3DDevice->SetMaterial(&m_vecMtlTex[i].GetMaterial());
			g_pD3DDevice->SetTexture(0, m_vecMtlTex[i].GetTexture());
			m_pMesh->DrawSubset(i);
		}
		g_pD3DDevice->SetTexture(0, 0);
		
	}
}
