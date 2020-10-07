#include "stdafx.h"
#include "cPointLight.h"

cPointLight::cPointLight(): m_pSphere(), m_Scale(10,10,10), m_Position()
{
}

cPointLight::~cPointLight()
{
	g_pD3DDevice->LightEnable(2, false);
	SafeRelease(m_pSphere);
}

void cPointLight::setup()
{
	light.Type = D3DLIGHT_POINT;
	light.Ambient = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	light.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	light.Specular = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);

	D3DXVECTOR3 vPos(10, 5, 0);
	m_Position = vPos;
	light.Position = vPos;
	light.Range = 10.0f;

	light.Attenuation0 = 0.0625f;
	light.Attenuation1 = 0.0625f;
	light.Attenuation2 = 0.0625f;

	g_pD3DDevice->SetLight(2, &light);
	g_pD3DDevice->LightEnable(2, true);
	D3DXCreateSphere(g_pD3DDevice, 1.0f, 10, 10, &m_pSphere, NULL);
}

void cPointLight::update()
{
	if (GetKeyState('L') & 0x0001)
	{
		if (!g_pD3DDevice->GetLight(2, &light))
		{

			if (GetKeyState('Q') & 0x8000)
			{
				light.Range += -0.1f;
			}
			if (GetKeyState('E') & 0x8000)
			{
				light.Range += 0.1f;
			}

			g_pD3DDevice->SetLight(2, &light);
		}
	}

	m_Scale.x = light.Range;
	m_Scale.y = light.Range;
	m_Scale.z = light.Range;
}

void cPointLight::render()
{

	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		D3DXMATRIXA16 matWorld, matS, matT;
		D3DXMatrixIdentity(&matWorld);

		D3DXMatrixScaling(&matS, m_Scale.x, m_Scale.y, m_Scale.z);
		D3DXMatrixTranslation(&matT, m_Position.x, m_Position.y, m_Position.z);
		matWorld = matS * matT;
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		
		m_pSphere->DrawSubset(0);

		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	}
}
