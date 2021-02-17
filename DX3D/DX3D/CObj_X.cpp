#include "stdafx.h"
#include "CObj_X.h"

#include "cMtlTex.h"

int CObj_X::m_num = -4;
int g_flip = 1;

CObj_X::CObj_X(): m_pMesh(nullptr)
{
	
}

CObj_X::~CObj_X()
{
	SafeRelease(m_pMesh);

}

bool CObj_X::open(string sFileName, string sFolder, float scale)
{
	D3DXMATRIXA16 matPos, matScale;
	D3DXMatrixTranslation(&matPos, m_num+=2, 1.5, g_flip *= -1);
	D3DXMatrixScaling(&matScale, scale, scale, scale);
	m_matWorldTM = matScale * matPos;
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
		// 텍스쳐 설정

		//g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		//g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		//g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

		// 알파 블렌딩 설정
		//g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		//g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		//g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		//g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);
		
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
		
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		for (int i = 0; i < m_vecMtlTex.size(); ++i)
		{
			g_pD3DDevice->SetMaterial(&m_vecMtlTex[i].GetMaterial());
			g_pD3DDevice->SetTexture(0, m_vecMtlTex[i].GetTexture());
			m_pMesh->DrawSubset(i);
		}
		g_pD3DDevice->SetTexture(0, 0);
		//g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
		
	}
}
