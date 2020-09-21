#include "stdafx.h"
#include "cSquare.h"
#include <string>



cSquare::cSquare()
	:vertex(),
	polygon(),
	camera()
{
	vertex.emplace_back(-1, 1, -1, 1);
	vertex.emplace_back(-1, -1, -1, 1);
	vertex.emplace_back(1, 1, -1, 1);
	vertex.emplace_back(1, -1, -1, 1);
	vertex.emplace_back(1, 1, 1, 1);
	vertex.emplace_back(1, -1, 1, 1);
	vertex.emplace_back(-1, 1, 1, 1);
	vertex.emplace_back(-1, -1, 1, 1);

	for (int i = 0; i < 8; ++i)
	{
		polygon.emplace_back(i, (i + 1) % 8, (i + 2) % 8, 1);
	}
	for (int i = 0; i < 8; i += 4)
	{
		polygon.emplace_back(i, (i + 2) % 8, (i + 4) % 8, 1);
		polygon.emplace_back(i + 1, (i + 3) % 8, (i + 5) % 8, 1);
	}
}

void cSquare::getInput()
{
	if(GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
	{
		rotate_.X += 10;
	}
	else if(GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
	{
		rotate_.X -= 10;
	}

	if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
	{
		rotate_.Y += 10;
	}
	else if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
	{
		rotate_.Y -= 10;
	}

	if (GetKeyState('e') & 0x8000 || GetKeyState('E') & 0x8000)
	{
		rotate_.Z += 10;
	}
	else if (GetKeyState('q') & 0x8000 || GetKeyState('Q') & 0x8000)
	{
		rotate_.Z -= 10;
	}

	if (GetKeyState(VK_UP) & 0x8000)// || GetKeyState('W') & 0x8000)
	{
		pos_.X += 1;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000)// || GetKeyState('S') & 0x8000)
	{
		pos_.X -= 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)// || GetKeyState('D') & 0x8000)
	{
		pos_.Y += 1;
	}
	else if (GetKeyState(VK_LEFT) & 0x8000)// || GetKeyState('A') & 0x8000)
	{
		pos_.Y -= 1;
	}
	
}

extern RECT g_view;
void DrawCircle(HDC hdc, int x, int y, int r = 5)
{
	Ellipse(hdc, x - r, y - r, x + r, y + r);
}
void cSquare::render(HDC hdc)
{
	cMatrix renderer(cMatrix::identity(4));
	renderer = renderer * cMatrix::scale(1);
	renderer = renderer * cMatrix::rotationX(rotate_.X);
	renderer = renderer * cMatrix::rotationY(rotate_.Y);
	renderer = renderer * cMatrix::rotationZ(rotate_.Z);
	renderer = renderer * cMatrix::translation(pos_.X, pos_.Y, 0);
	renderer = renderer * cMatrix::view(camera.position, camera.target);
	cout << renderer << endl;
	renderer = renderer * cMatrix::projection(camera.fFovY, camera.fAspect, camera.fNearZ, camera.fFarZ);
	renderer = renderer * cMatrix::viewport(0, 0, g_view.right, g_view.bottom);
	vector<cVector3> renderVertex;
	for (int i = 0; i < 8; ++i)
	{
		renderVertex.emplace_back(cVector3::transformCoord(vertex[i], renderer));
		//DrawCircle(hdc, renderVertex[i].X, renderVertex[i].Y);
		//std::wstring temp = std::to_wstring(i);
		//TextOut(hdc, renderVertex[i].X, renderVertex[i].Y, temp.c_str(), temp.length());
	}

	cMatrix worldRender(cMatrix::identity(4));
	worldRender = worldRender * cMatrix::view(camera.position, camera.target);
	worldRender = worldRender * cMatrix::projection(camera.fFovY, camera.fAspect, camera.fNearZ, camera.fFarZ);
	worldRender = worldRender * cMatrix::viewport(0, 0, g_view.right, g_view.bottom);
	
	vector<cVector3> test(4);
	test[1].X = 10;
	test[2].Y = 10;
	test[3].Z = 10;
	for (auto & vector3 : test)
	{
		vector3.W = 1;
		vector3 = cVector3::transformCoord(vector3, worldRender);
	}

	for (int i = 1; i < 4; ++i)
	{
		MoveToEx(hdc, test[0].X, test[0].Y, NULL);
		LineTo(hdc, test[i].X, test[i].Y);
		std::wstring temp;
		switch (i)
		{
		case 1: temp = L"X"; break;
		case 2: temp = L"Y"; break;
		case 3: temp = L"Z"; break;
		}

		TextOut(hdc, test[i].X, test[i].Y, temp.c_str(), temp.length());
	}
	TextOut(hdc, test[0].X, test[0].Y, _T("0"), _tcslen(_T("0")));

	for (auto & vector3 : polygon)
	{
		MoveToEx(hdc, renderVertex[vector3.X].X, renderVertex[vector3.X].Y, NULL);
		LineTo(hdc, renderVertex[vector3.Y].X, renderVertex[vector3.Y].Y);
		LineTo(hdc, renderVertex[vector3.Z].X, renderVertex[vector3.Z].Y);
		LineTo(hdc, renderVertex[vector3.X].X, renderVertex[vector3.X].Y);
	}


	
}
