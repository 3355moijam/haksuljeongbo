#include "stdafx.h"
#include "cCharacter.h"

cCharacter::cCharacter()
	: m_fRotY(D3DX_PI)
	, m_vDirection(0,0,-1)
	, m_vPosition(0,1,0)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCharacter::~cCharacter()
{
}

void cCharacter::setup()
{
}

void cCharacter::update()
{
	if (GetKeyState('K') & 0x0001)
		return;
	if (GetKeyState('L') & 0x0001)
		return;
	
	if (GetKeyState('A') & 0x8000)
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

	m_vDirection = D3DXVECTOR3(0, 0, -1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = matR * matT;
}

void cCharacter::render()
{
}

D3DXVECTOR3& cCharacter::getPosition()
{
	return m_vPosition;
}
