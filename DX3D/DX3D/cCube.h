#pragma once
#include "stdafx.h"


class cCube
{
private:
	vector<ST_PC_VERTEX> vertex;
	//vector<DWORD> verIndex;
	vector<ST_PC_VERTEX> verIndex;

	D3DXVECTOR3 pos_;
	D3DXVECTOR3 rotate_;
	D3DXVECTOR3 direct_;
	D3DXVECTOR3 scale_;
	float speed;

public:
	cCube();

	D3DXVECTOR3& get_pos()
	{
		return pos_;
	}

	__declspec(property(get = get_pos)) D3DXVECTOR3& pos;

	D3DXVECTOR3& get_rotate()
	{
		return rotate_;
	}

	__declspec(property(get = get_rotate)) D3DXVECTOR3& rotate;
	void render();
	void update();
	//void getInput();
	//void render(HDC hdc, cMatrix& matWVP, cMatrix& matViewport, D3DXVECTOR3& cameraDirect);
	D3DXVECTOR3 move(float dir);
};
