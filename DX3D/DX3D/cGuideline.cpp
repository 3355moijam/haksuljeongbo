#include "stdafx.h"
#include "cGuideline.h"

#include "cPyramid.h"

cGuideline::cGuideline()
{
}

cGuideline::~cGuideline()
{
	for (auto * gizmo : m_Gizmo)
	{
		SafeDelete(gizmo);
	}
}

void cGuideline::setup(D3DCOLOR c)
{
	ST_PC_VERTEX v;
	const float _6route3 = 6 * pow(3, 0.5);
	v.c = c;

	v.p = D3DXVECTOR3(-12, 1, 0);			m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(-6, 1, _6route3);	m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(6, 1, _6route3);	m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(12, 1, 0);			m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(6, 1, -_6route3);	m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(-6, 1, -_6route3);	m_RouteNode.push_back(v);
	v.p = D3DXVECTOR3(-12, 1, 0);			m_RouteNode.push_back(v);

	D3DXMATRIXA16 matR;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	for (auto & node : m_RouteNode)
	{
		m_Gizmo.push_back(new cPyramid);
		m_Gizmo.back()->setup(c, matR, node.p);
	}
}

void cGuideline::render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIXA16 matI;
	D3DXMatrixIdentity(&matI);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matI);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	if (m_ShortCut.empty())
	{
		g_pD3DDevice->DrawPrimitiveUP
		(
			D3DPT_LINESTRIP,
			m_RouteNode.size() - 1,
			&m_RouteNode[0],
			sizeof ST_PC_VERTEX
		);
	}
	else
	{
		g_pD3DDevice->DrawPrimitiveUP
		(
			D3DPT_LINESTRIP,
			m_ShortCut.size() - 1,
			&m_ShortCut[0],
			sizeof ST_PC_VERTEX
		);
	}

	for (auto * p : m_Gizmo)
	{
		p->render();
	}
	//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void cGuideline::Interpolation(float div)
{
	float t = 1.0f / div;
	
	while(!m_Gizmo.empty())
	{
		SafeDelete(m_Gizmo.back());
		m_Gizmo.pop_back();
	}
	m_ShortCut.resize(0);

	ST_PC_VERTEX v;
	v.c = m_RouteNode[0].c;
	for (int i = 0; i < m_RouteNode.size() - 1; i += 2)
	{
		for (int j = 0; j < div; ++j)
		{
			v.p = pow(1 - (t*j), 2) * m_RouteNode[i].p + 2 * (1 - (t*j)) * (t*j) * m_RouteNode[i + 1].p + pow((t*j), 2) * m_RouteNode[i + 2].p;
			m_ShortCut.push_back(v);
		}
	}
	m_ShortCut.push_back(m_RouteNode.back());

	D3DXMATRIXA16 matR;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	
	for (auto & node : m_ShortCut)
	{
		m_Gizmo.push_back(new cPyramid);
		m_Gizmo.back()->setup(node.c, matR, node.p);
	}
	
}
