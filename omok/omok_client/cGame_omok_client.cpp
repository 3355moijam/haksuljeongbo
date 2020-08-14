#include "stdafx.h"
#include "cGame_omok_client.h"
#pragma comment(lib, "msimg32.lib")
#include <cmath>

const double gridSize = 38.67;


cGame_omok_client::cGame_omok_client() : field(), omok_field(), omok_black(), omok_white()
{

	omok_field = (HBITMAP)LoadImage(NULL, TEXT("src/go_field.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_field, sizeof(BITMAP), &fieldData);

	omok_black = (HBITMAP)LoadImage(NULL, TEXT("src/go_black.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_black, sizeof(BITMAP), &blackData);

	omok_white = (HBITMAP)LoadImage(NULL, TEXT("src/go_white.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_white, sizeof(BITMAP), &whiteData);

	local_coord = { 400, 50 };
	int length = 19;
	//field[0][0] = WHITE;
	/*for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if ((i + j) % 2 == BLACK)
				field[i][j] = BLACK;
			else
				field[i][j] = WHITE;
		}
	}*/
}


cGame_omok_client::~cGame_omok_client()
{
	DeleteObject(omok_field);
	DeleteObject(omok_black);
	DeleteObject(omok_white);
}

void cGame_omok_client::show(HDC hdc)
{
	HDC hFieldMemDC, hBlackMemDC, hWhiteMemDC;
	HBITMAP hOldBitmap, hOldBitmapW, hOldBitmapB;
	
	{
		hFieldMemDC = CreateCompatibleDC(hdc);
		hOldBitmap = (HBITMAP)SelectObject(hFieldMemDC, omok_field);
		int fx = fieldData.bmWidth;
		int fy = fieldData.bmHeight;
		BitBlt(hdc, local_coord.x, local_coord.y, fx, fy, hFieldMemDC, 0, 0, SRCCOPY);
		SelectObject(hFieldMemDC, hOldBitmap);
		DeleteDC(hFieldMemDC);
	}

	hBlackMemDC = CreateCompatibleDC(hdc);
	hWhiteMemDC = CreateCompatibleDC(hdc);
	hOldBitmapB = (HBITMAP)SelectObject(hBlackMemDC, omok_black);
	hOldBitmapW = (HBITMAP)SelectObject(hWhiteMemDC, omok_white);

	int bx = blackData.bmWidth;
	int by = blackData.bmHeight;
	int wx = whiteData.bmWidth;
	int wy = whiteData.bmHeight;

	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 19; j++)
		{
			if (field[i][j])
			{
				POINT DrawCoord = IndexToCoord(i, j);
				if (field[i][j] == BLACK)
				{
					TransparentBlt(hdc, DrawCoord.x - 20, DrawCoord.y - 20, bx, by, hBlackMemDC, 0, 0, bx, by, RGB(255, 0, 255));
				}
				else if (field[i][j] == WHITE)
				{
					TransparentBlt(hdc, DrawCoord.x - 20, DrawCoord.y - 20, wx, wy, hWhiteMemDC, 0, 0, wx, wy, RGB(255, 0, 255));
				}
			}
		}
	}


	SelectObject(hBlackMemDC, hOldBitmapB);
	SelectObject(hWhiteMemDC, hOldBitmapW);
	DeleteDC(hBlackMemDC);
	DeleteDC(hWhiteMemDC);
}

bool cGame_omok_client::PutStone(unsigned int x, unsigned int y, int color)
{
	if (CheckPossible(x, y))
	{
		POINT index = MouseToIndex(x, y);
		field[index.x][index.y] = color;
		return true;
	}
	return false;
}

bool cGame_omok_client::CheckPossible(unsigned int x, unsigned int y)
{
	RECT field = { local_coord.x, local_coord.y, local_coord.x + fieldData.bmWidth, local_coord.y + fieldData.bmHeight };
	POINT mouse = { x, y };
	return PtInRect(&field, mouse);
	
	//return false;
}

POINT cGame_omok_client::MouseToIndex(unsigned int x, unsigned int y)
{
	POINT mouse = { x, y };
	POINT temp = { 20, 20 };

	mouse -= local_coord;
	mouse -= 9;
	temp.x = round(((double)mouse.x) / gridSize);
	temp.y = round(((double)mouse.y) / gridSize);
	
	return temp;
}

POINT cGame_omok_client::IndexToCoord(unsigned int x, unsigned int y)
{
	POINT field_coord = local_coord;
	field_coord += 9;
	field_coord.x += x * gridSize;
	field_coord.y += y * gridSize;
	return field_coord;
}


