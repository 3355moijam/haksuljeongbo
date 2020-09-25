#pragma once
#include "cCamera.h"
#include "cCharacter.h"
#include "cCube.h"
#include "cGrid.h"

//class cCubePC;
//class cCamera2;
//class cGrid2;

class cMainGame
{
private:
	//vector<ST_PC_VERTEX> m_vecLineVertex;
	//vector<ST_PC_VERTEX> m_vecTriangleVertex;
	cCube cube;
	cGrid grid;
	cCamera camera;

	cCharacter player;
	//cCubePC*	m_pCubePC;
	//cCamera2*	m_pCamera;
	//cGrid2*		m_pGrid;
public:
	cMainGame();
	~cMainGame();

	void setup();
	void update();
	void render();
	
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
