#include "stdafx.h"
#include "cDirectionalLight.h"

cDirectionalLight::~cDirectionalLight()
{
	g_pD3DDevice->LightEnable(0, false);

}

void cDirectionalLight::setup()
{
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	light.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	light.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 0.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	light.Direction = vDir;
	g_pD3DDevice->SetLight(0, &light);
	g_pD3DDevice->LightEnable(0, true);
}

void cDirectionalLight::update()
{
	//return;
	D3DXMATRIXA16 matRZ;
	D3DXMatrixRotationZ(&matRZ, 1 * D3DX_PI / 180);
	D3DXVECTOR3 tempDir(light.Direction);
	D3DXVec3TransformNormal(&tempDir, &tempDir, &matRZ);
	light.Direction = tempDir;
	g_pD3DDevice->SetLight(0, &light);
}

void cDirectionalLight::render()
{
}
