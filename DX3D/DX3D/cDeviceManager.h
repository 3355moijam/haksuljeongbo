#pragma once

#define g_pDeviceManager cDeviceManager::getInstance()
#define g_pD3DDevice cDeviceManager::getInstance().getDevice()

class cDeviceManager
{
	Singletone(cDeviceManager);

private:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;
public:

	LPDIRECT3DDEVICE9	getDevice();
	void Destroy();
	
};
