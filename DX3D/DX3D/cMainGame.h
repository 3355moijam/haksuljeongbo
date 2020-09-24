#pragma once
#include "cCamera.h"
#include "cCube.h"
#include "cGrid.h"

class cMainGame
{
private:
	vector<ST_PC_VERTEX> m_vecLineVertex;
	vector<ST_PC_VERTEX> m_vecTriangleVertex;
	cCube cube;
	cGrid grid;
	cCamera camera;
public:
	cMainGame();
	~cMainGame();

	void setup();
	void update();
	void render();

	void setupLine();
	void drawLine();

	void setupTriangle();
	void drawTriangle();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
