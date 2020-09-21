#pragma once
#include "stdafx.h"

#include "cCamera.h"
#include "cMatrix.h"

class cVector3;

class cSquare
{
private:
	vector<cVector3> vertex;
	vector<cVector3> polygon;
	cCamera camera;
	cVector3 pos_;
	cVector3 rotate_;
public:
	cSquare();
	void getInput();
	void render(HDC hdc);
};
