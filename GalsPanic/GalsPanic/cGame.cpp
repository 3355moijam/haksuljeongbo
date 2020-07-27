#include "cGame.h"

extern RECT view;


cArea::cArea() :vertex(4)
{
	vertex[0] = { 100, 100 };
	vertex[1] = { 400, 100 };
	vertex[2] = { 400, 400 };
	vertex[3] = { 100, 400 };

	int length = vertex.size();
	POINT* temp = new POINT[length];
	for (size_t i = 0; i < length; i++)
		temp[i] = vertex[i];

	region = CreatePolygonRgn(temp, length, WINDING);
}

void cArea::show(HDC hdc)
{

	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 100));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	FillRgn(hdc, region, hBrush);
	PaintRgn(hdc, region);
	DeleteObject((HBRUSH)SelectObject(hdc, hOldBrush));

}

void cArea::update()
{
	DeleteObject(region);

	int length = vertex.size();
	POINT* temp = new POINT[length];
	for (size_t i = 0; i < length; i++)
		temp[i] = vertex[i];

	region = CreatePolygonRgn(temp, length, WINDING);
}

cPlayer::cPlayer() :radius(10), speed(10), from(0), to(-1), path(), before_direct(0), current_direct(0)
{
	center.x = 100;
	center.y = 100;
}

cPlayer::cPlayer(int _x, int _y) :radius(10), speed(10), from(0), to(-1), path(), before_direct(0), current_direct(0)
{
	center.x = _x;
	center.y = _y;
}

void cPlayer::show(HDC hdc)
{
	int length = path.size();
	if (length)
	{
		MoveToEx(hdc, path[0]);
		for (size_t i = 1; i < length; i++)
		{
			LineTo(hdc, path[i]);
		}
	}

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	DrawCircle(hdc, center, radius);
	DeleteObject(SelectObject(hdc, hOldBrush));
}

bool cPlayer::move(WPARAM wParam, cArea* area)
{
	POINT temp = center;
	switch (wParam)
	{
	case VK_LEFT:
		temp.x -= speed;
		break;
	case VK_UP:
		temp.y -= speed;
		break;
	case VK_RIGHT:
		temp.x += speed;
		break;
	case VK_DOWN:
		temp.y += speed;
		break;
	default:
		return false;
	}
	if (before_direct == 0)
	{
		before_direct = wParam;
	}
	else
		before_direct = current_direct;
	current_direct = wParam;
	

	int ntemp1, ntemp2;
	ntemp1 = from == 0 ? area->vertex.size() - 1 : from - 1;
	ntemp2 = (from + 1) == area->vertex.size() ? 0 : from + 1;
	

	// >> 선따라 이동 판정
	if (path.size() == 0)
	{
		if (to != -1)
		{
			if (IsBetweenPt(temp, area->vertex[from], area->vertex[to]))
			{
				center = temp;

				if (temp == area->vertex[from])
					to = -1;
				else if (temp == area->vertex[to])
				{
					from = to;
					to = -1;
				}
				return false;
			}
		}
		else // to == -1
		{
			if (IsBetweenPt(temp, area->vertex[from], area->vertex[ntemp1]))
			{
				center = temp;
				if (temp == area->vertex[ntemp1])
					from = ntemp1;
				else
					to = ntemp1;
				return false;
			}
			else if (IsBetweenPt(temp, area->vertex[from], area->vertex[ntemp2]))
			{
				center = temp;
				if (temp == area->vertex[ntemp2])
					from = ntemp2;
				else
					to = ntemp2;
				return false;
			}
		}
	}
	// <<
	/*
	if (PtInRegion(area->get_region(), temp.x, temp.y))
	{
	}
	else
	{
		if (GetKeyState('A') & 0x8000)
		{
			if (path.size() == 0)
			{
				path.push_back(center);

			}

		}
	}
	*/
	
	return false;
}

int cPlayer::set_to()
{
	return to;
}

cGame::cGame() :area(), player()
{

}

cGame::~cGame()
{
}

void cGame::show(HDC hdc)
{
	DrawGrid(hdc, 0, 0, view.right, view.left, 10);
	area.show(hdc);
	player.show(hdc);
}

void cGame::move(WPARAM wParam)
{
	if(player.move(wParam, &area))
		area.update();
}