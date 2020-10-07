#include "stdafx.h"
#include "cSpotLight.h"

cSpotLight::cSpotLight(): m_pCylinder(),
                       m_Rotation(0,0,0),
                       m_Position()
{
}

cSpotLight::~cSpotLight()
{
	g_pD3DDevice->LightEnable(1, false);
	SafeRelease(m_pCylinder);
}

void cSpotLight::setup()
{
	light.Type = D3DLIGHT_SPOT;
	light.Ambient = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	light.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	light.Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 0.5f);

	
	D3DXVECTOR3 vDir(0.0f, -1.0f, 0.0f);
	D3DXVECTOR3 vPos(0, 13, 0);
	m_Position = vPos;
	//m_Position.y -= 10;
	
	
	D3DXVec3Normalize(&vDir, &vDir);
	light.Direction = vDir;
	light.Position = vPos;
	light.Range = 20.0f;
	light.Falloff = 1.0f;

	light.Attenuation0 = 0.0625f;
	light.Attenuation1 = 0.0625f;
	light.Attenuation2 = 0.00625f;


	light.Phi = D3DX_PI / 4;
	light.Theta = D3DX_PI / 4;

	g_pD3DDevice->SetLight(1, &light);
	g_pD3DDevice->LightEnable(1, true);

	D3DXCreateCylinder(g_pD3DDevice, 0, tan(light.Phi / 2) * light.Range, light.Range, 10, 10, &m_pCylinder, NULL);

	D3DXMatrixRotationX(&matLocalR, D3DX_PI / 2);
	D3DXMatrixRotationX(&matRX, m_Rotation.x);
	D3DXMatrixRotationZ(&matRZ, m_Rotation.z);
	D3DXMatrixTranslation(&matLocalT, 0, -10, 0);
	D3DXMatrixTranslation(&matT, m_Position.x, m_Position.y, m_Position.z);
	matWorld = matLocalR * matLocalT * matRX * matRZ * matT;
	
}

void cSpotLight::update()
{
	if (GetKeyState('K') & 0x0001)
	{
		if (!g_pD3DDevice->GetLight(1, &light))
		{

			if (GetKeyState('A') & 0x8000)
			{
				m_Rotation.z += -0.1f;
			}
			if (GetKeyState('D') & 0x8000)
			{
				m_Rotation.z += 0.1f;
			}

			if (GetKeyState('W') & 0x8000)
			{
				m_Rotation.x += 0.1f;
			}
			if (GetKeyState('S') & 0x8000)
			{
				m_Rotation.x += -0.1f;
			}
			D3DXVECTOR3 vDir(0, -1, 0);
			
			D3DXMatrixRotationX(&matRX, m_Rotation.x);
			D3DXMatrixRotationZ(&matRZ, m_Rotation.z);
			D3DXMATRIXA16 matR = matRX * matRZ;
			D3DXVec3TransformCoord(&vDir, &vDir, &matR);
			light.Direction = vDir;
			matWorld = matLocalR * matLocalT * matR * matT;
			g_pD3DDevice->SetLight(1, &light);
		}
	}
}

void cSpotLight::render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		m_pCylinder->DrawSubset(0);

		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	}
}
