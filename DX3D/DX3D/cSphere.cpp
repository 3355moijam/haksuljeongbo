#include "stdafx.h"
#include "cSphere.h"

cSphere::cSphere() : m_pMesh(nullptr), m_stMtl({}), m_vPos(0, 0, 0), m_fRadius(1.0f), m_bFlip(false)
{
	D3DXMatrixIdentity(&m_matWorld);
	m_stMtl.Ambient = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	m_stMtl.Diffuse = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	m_stMtl.Specular = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);

	D3DXCreateSphere(g_pD3DDevice, m_fRadius, 20, 20, &m_pMesh, NULL);
}

cSphere::cSphere(float _x, float _y, float _z) : cSphere()
{
	setPosition(_x, _y, _z);
}

cSphere::~cSphere()
{
	SafeRelease(m_pMesh);
}

void cSphere::setColor(D3DXCOLOR color)
{
	m_stMtl.Ambient  = color;
	m_stMtl.Diffuse  = color;
	m_stMtl.Specular = color;
}

void cSphere::setPosition(float _x, float _y, float _z)
{
	m_vPos.x = _x;
	m_vPos.y = _y;
	m_vPos.z = _z;
	D3DXMatrixTranslation(&m_matWorld, _x, _y, _z);
}

void cSphere::setPosition(D3DXVECTOR3& _xyz)
{
	m_vPos = _xyz;
	D3DXMatrixTranslation(&m_matWorld, m_vPos.x, m_vPos.y, m_vPos.z);
}

void cSphere::FlipColor()
{
	if(m_bFlip)
	{
		m_stMtl.Ambient  = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
		m_stMtl.Diffuse  = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
		m_stMtl.Specular = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	}
	else
	{
		m_stMtl.Ambient  = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_stMtl.Diffuse  = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_stMtl.Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}
	m_bFlip = !m_bFlip;
}

void cSphere::render()
{
	if(g_pD3DDevice)
	{
		g_pD3DDevice->SetTexture(0, NULL);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
		g_pD3DDevice->SetMaterial(&m_stMtl);
		m_pMesh->DrawSubset(0);
	}
}
