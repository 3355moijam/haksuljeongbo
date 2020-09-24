#pragma once
#include "stdafx.h"

#include "cCamera.h"
#include "cMatrix.h"

class cVector3;

class cSquare
{
private:
	vector<cVector3> vertex;
	vector<DWORD> verIndex;

	cVector3 pos_;
	cVector3 rotate_;
	cVector3 direct_;
	cVector3 scale_;
	float speed;

public:
	cSquare();

	cVector3& get_pos()
	{
		return pos_;
	}

	__declspec(property(get = get_pos)) cVector3& pos;

	cVector3& get_rotate()
	{
		return rotate_;
	}

	__declspec(property(get = get_rotate)) cVector3& rotate;
	//void getInput();
	void render(HDC hdc, cMatrix& matWVP, cMatrix& matViewport, cVector3& cameraDirect);
	cVector3 move(float dir);
	void scaleControl(float s);
	cMatrix get_world_matrix();
};
