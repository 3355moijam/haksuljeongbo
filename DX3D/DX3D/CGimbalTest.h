#pragma once

class CGimbalTest
{
private:
	vector<LPD3DXMESH>	m_vecMesh;
	D3DMATERIAL9		m_stMtl;

	vector<float>		m_fRot;
	vector<D3DXMATRIXA16> m_matRot;
public:
	CGimbalTest();
	~CGimbalTest();

	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
