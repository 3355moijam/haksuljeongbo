#include "stdafx.h"
#include "cGroupNode.h"

cGroupNode::cGroupNode(): m_fRotX(0), m_pParentWorldTM(nullptr), m_fRotDeltaX(0.1f)
{
}

void cGroupNode::render()
{
	if (m_pMtlTex)
	{
		//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		g_pD3DDevice->SetTexture(0, m_pMtlTex->GetTexture());
		g_pD3DDevice->SetMaterial(&m_pMtlTex->GetMaterial());

		D3DXMATRIXA16 matI;
		D3DXMatrixIdentity(&matI);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);
		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP
		(
			D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof ST_PNT_VERTEX
		);
	}
	

	
	for (auto* child : children)
	{
		child->render();
	}
}
