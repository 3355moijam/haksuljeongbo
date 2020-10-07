#include "stdafx.h"
#include "cCubePC.h"

cCubePC::cCubePC():
	m_vDirection(0,0,1),
	m_vPosition(0,0,0),
	m_fRotY(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCubePC::~cCubePC()
{
	
}

void cCubePC::setup()
{
	ST_PC_VERTEX v;
	//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.c = D3DCOLOR_ARGB(0, rand() % 256, rand() % 256, rand() % 256);
	vector<ST_PC_VERTEX> tempVertex;
	//tempVertex.emplace_back(-1, -1, -1, D3DCOLOR_XRGB(255, 0, 0));
	//tempVertex.emplace_back(-1, 1, -1, D3DCOLOR_XRGB(0, 255, 0));
	//tempVertex.emplace_back(1, 1, -1, D3DCOLOR_XRGB(0, 0, 255));
	//tempVertex.emplace_back(1, -1, -1, D3DCOLOR_XRGB(255, 0, 0));


	////
	//tempVertex.emplace_back(-1, -1, 1, D3DCOLOR_XRGB(0, 0, 255));
	//tempVertex.emplace_back(-1, 1, 1, D3DCOLOR_XRGB(0, 0, 255));
	//tempVertex.emplace_back(1, 1, 1, D3DCOLOR_XRGB(0, 0, 255));
	//tempVertex.emplace_back(1, -1, 1, D3DCOLOR_XRGB(0, 0, 255));


	tempVertex.emplace_back(-0.5, -0.5, -0.5, D3DCOLOR_XRGB(255, 0, 0));
	tempVertex.emplace_back(-0.5, 0.5, -0.5, D3DCOLOR_XRGB(0, 255, 0));
	tempVertex.emplace_back(0.5, 0.5, -0.5, D3DCOLOR_XRGB(0, 0, 255));
	tempVertex.emplace_back(0.5, -0.5, -0.5, D3DCOLOR_XRGB(255, 0, 0));


	//
	tempVertex.emplace_back(-0.5, -0.5, 0.5, D3DCOLOR_XRGB(0, 0, 255));
	tempVertex.emplace_back(-0.5, 0.5, 0.5, D3DCOLOR_XRGB(0, 0, 255));
	tempVertex.emplace_back(0.5, 0.5, 0.5, D3DCOLOR_XRGB(0, 0, 255));
	tempVertex.emplace_back(0.5, -0.5, 0.5, D3DCOLOR_XRGB(0, 0, 255));
	
	// 폴리곤 만들기
	{
		v.c = D3DCOLOR_ARGB(0, rand() % 256, rand() % 256, rand() % 256);

		//front
		m_vecVertex.push_back(tempVertex[0]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[1]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[2]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[0]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[2]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[3]);
		m_vecVertex.back().c = v.c;
		//back
		//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[5]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[7]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;

		//left
		//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[5]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[1]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[1]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[0]);
		m_vecVertex.back().c = v.c;

		//right
		//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		m_vecVertex.push_back(tempVertex[3]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[2]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[3]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[7]);
		m_vecVertex.back().c = v.c;

		//up
		//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		m_vecVertex.push_back(tempVertex[1]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[5]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[1]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[6]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[2]);
		m_vecVertex.back().c = v.c;

		//down
		//v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[0]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[3]);
		m_vecVertex.back().c = v.c;

		m_vecVertex.push_back(tempVertex[4]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[3]);
		m_vecVertex.back().c = v.c;
		m_vecVertex.push_back(tempVertex[7]);
		m_vecVertex.back().c = v.c;
	}
}

void cCubePC::update()
{
	if(GetKeyState('A') & 0x8000)
	{
		m_fRotY += -0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition += (m_vDirection*0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition -= (m_vDirection*0.1f);
	}

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCubePC::render()
{
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, false);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP
	(
		D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof ST_PC_VERTEX
	);
}
