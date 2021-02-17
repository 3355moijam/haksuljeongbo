#include "stdafx.h"
#include "CGimbalTest.h"

CGimbalTest::CGimbalTest():
	m_stMtl({})
{
	m_stMtl.Ambient = D3DXCOLOR(1, 1, 1, 1);
	m_stMtl.Diffuse = D3DXCOLOR(1, 1, 1, 1);
	m_stMtl.Specular = D3DXCOLOR(1, 1, 1, 1);

	m_vecMesh.resize(2);
	D3DXCreateTeapot(g_pD3DDevice, &m_vecMesh[0], nullptr);
	D3DXCreateTeapot(g_pD3DDevice, &m_vecMesh[1], nullptr);
	m_fRot.resize(3);
	m_matRot.resize(3);
}

CGimbalTest::~CGimbalTest()
{
	for (auto && p : m_vecMesh)
	{
		SafeRelease(p);
	}
}

void CGimbalTest::Update()
{
	
}

void CGimbalTest::Render()
{
	D3DXMATRIXA16 matT1, matT2, matWorld;
	D3DXMatrixTranslation(&matT1, -1, 1, 0);
	D3DXMatrixTranslation(&matT2, 1, 1, 0);

	D3DXMatrixRotationX(&m_matRot[0], D3DXToRadian(m_fRot[0]));
	D3DXMatrixRotationY(&m_matRot[1], D3DXToRadian(m_fRot[1]));
	D3DXMatrixRotationZ(&m_matRot[2], D3DXToRadian(m_fRot[2]));
	matWorld = m_matRot[0] * m_matRot[1] * m_matRot[2] * matT1;
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetTexture(0, 0);
	
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_vecMesh[0]->DrawSubset(0);

	D3DXQUATERNION qx, qy, qz;
	D3DXQuaternionRotationYawPitchRoll(&qx, D3DXToRadian(m_fRot[1]), D3DXToRadian(m_fRot[0]), D3DXToRadian(m_fRot[2]));
	//D3DXQuaternionRotationAxis(&qx, &D3DXVECTOR3(1, 0, 0), D3DXToRadian(m_fRot[0]));
	//D3DXQuaternionRotationAxis(&qy, &D3DXVECTOR3(0, 1, 0), D3DXToRadian(m_fRot[1]));
	//D3DXQuaternionRotationAxis(&qz, &D3DXVECTOR3(0, 0, 1), D3DXToRadian(m_fRot[2]));
	//qx = qx * qz * qy;
	D3DXMatrixRotationQuaternion(&m_matRot[0], &qx);
	matWorld = m_matRot[0] * matT2;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_vecMesh[1]->DrawSubset(0);
	
}

void CGimbalTest::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_KEYDOWN:
	{
		if (wParam == 'T')
			m_fRot[0] += 10;
		if (wParam == 'Y')
			m_fRot[0] -= 10;
		if (wParam == 'G')
			m_fRot[1] += 10;
		if (wParam == 'H')
			m_fRot[1] -= 10;
		if (wParam == 'B')
			m_fRot[2] += 10;
		if (wParam == 'N')
			m_fRot[2] -= 10;
	}
		break;
	}
}
