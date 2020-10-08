#pragma once
#include "cGuideline.h"
//#include "cCamera.h"
//#include "cCharacter.h"
//#include "cCube.h"
//#include "cGrid.h"

class cGroup;
class cCubeObj;
class cCubeMan2;
class cCubeMan;
class cCubePC;
class cCamera2;
class cGrid2;
class cPointLight;
class cDirectionalLight;
class cSpotLight;


class cMainGame
{
private:
	//vector<ST_PC_VERTEX> m_vecLineVertex;
	//vector<ST_PC_VERTEX> m_vecTriangleVertex;
	//cCube cube;
	//cGrid grid;
	//cCamera camera;
	//cCharacter player;

	cCubePC*	m_pCubePC;
	cCamera2*	m_pCamera;
	cGrid2*		m_pGrid;

	cCubeMan*	m_pCubeMan;

	// >> for texture
	LPDIRECT3DTEXTURE9	m_pTexture;
	vector<ST_PT_VERTEX> m_vecVertex;
	// <<

	// >> lighting
	cPointLight*		m_PointLight;
	cDirectionalLight*	m_DirectionalLight;
	cSpotLight*			m_SpotLight;
	// <<

	cGuideline*			m_pRoute;
	cGuideline*			m_pShort;

	cCubeMan2*			m_pRouteMan;
	cCubeMan2*			m_pShortCutMan;

	cCubeObj*			m_pCubeObj;

	vector<cGroup*>		m_vecGroup;
public:
	cMainGame();
	~cMainGame();

	void setup();
	void update();
	void Draw_Texture();
	void render();
	
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Set_Light();

	void Setup_Obj();
	void Obj_Render();
};
