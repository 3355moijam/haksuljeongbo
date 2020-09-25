#pragma once

class cCamera2
{
public:
	cCamera2();
	~cCamera2();

private:
	D3DXVECTOR3		m_vEye;
	D3DXVECTOR3		m_vLookAt;
	D3DXVECTOR3		m_vUp;
	D3DXVECTOR3*	m_pvTarget;

	POINT			m_ptPrevMouse;
	bool			m_isRButtonDown;
	float			m_fCameraDistance;
	D3DXVECTOR3		m_vCamRotAngle;

public:
	void setup(D3DXVECTOR3* pvTarget);
	void update();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
