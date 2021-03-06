﻿#include "stdafx.h"
#include "cDeviceManager.h"

cDeviceManager::cDeviceManager() : m_pD3D(NULL), m_pD3DDevice(NULL)
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9 caps;
	m_pD3D->GetDeviceCaps(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		&caps
	);

	int nVertexProcessing = 0;
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	D3DPRESENT_PARAMETERS d3dpp{};
	d3dpp.BackBufferFormat =  D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.hDeviceWindow = g_hWnd;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;


	HRESULT hr = m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&d3dpp,		//parameter
		&m_pD3DDevice
	);

	if (FAILED(hr))
	{
		::MessageBox(0, _T("CreateDevice() - FAILED"), 0, 0);
		return;
	}
}

cDeviceManager::~cDeviceManager()
{

}



LPDIRECT3DDEVICE9 cDeviceManager::getDevice()
{
	return m_pD3DDevice;
}

void cDeviceManager::Destroy()
{
	SafeRelease(m_pD3D);
	SafeRelease(m_pD3DDevice);
}
