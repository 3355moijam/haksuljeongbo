#include "stdafx.h"
#include "cCubeObj.h"
#include "cObjParser.h"


cCubeObj::cCubeObj(): m_stMtl(), m_pTexture(nullptr)
{
}

cCubeObj::~cCubeObj()
{
	SafeRelease(m_pTexture);
}

void cCubeObj::setup()
{
	cObjParser parser;
	parser.setRoot("data/obj/");
	assert(!parser.open("box.obj"));

	parser.objParse();
	parser.createObj(m_vecVertex, &m_stMtl, m_pTexture);
	
}

void cCubeObj::update()
{
}

void cCubeObj::render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTexture(0, m_pTexture);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof ST_PNT_VERTEX
		);

		g_pD3DDevice->SetTexture(0, NULL);

	}
}
