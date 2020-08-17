#include "omok_framework.h"
#include "omok_dll.h"
#pragma comment(lib, "msimg32.lib")
#include <cmath>

const double gridSize = 38.67;


cGame_omok::cGame_omok() : field(), omok_field(), omok_black(), omok_white(), player_type(WATCH), player_turn(BLACK), player_id(-1)
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


cGame_omok::~cGame_omok()
{
	DeleteObject(omok_field);
	DeleteObject(omok_black);
	DeleteObject(omok_white);
}

void cGame_omok::show(HDC hdc)
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
			if (field[j][i])
			{
				POINT DrawCoord = IndexToCoord(i, j);
				if (field[j][i] == BLACK)
				{
					TransparentBlt(hdc, DrawCoord.x - 20, DrawCoord.y - 20, bx, by, hBlackMemDC, 0, 0, bx, by, RGB(255, 0, 255));
				}
				else if (field[j][i] == WHITE)
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

bool cGame_omok::PutStone(unsigned int mouse_x, unsigned int mouse_y, int color)
{
	if (player_turn != player_type)
		return false;
	if (CheckPossible(mouse_x, mouse_y))
	{
		POINT index = MouseToIndex(mouse_x, mouse_y);
		field[index.y][index.x] = color;
		return true;
	}
	return false;
}

bool cGame_omok::CheckPossible(unsigned int mouse_x, unsigned int mouse_y)
{
	RECT field = { local_coord.x, local_coord.y, local_coord.x + fieldData.bmWidth, local_coord.y + fieldData.bmHeight };
	POINT mouse = { mouse_x, mouse_y };
	return PtInRect(&field, mouse);

	//return false;
}

POINT cGame_omok::MouseToIndex(unsigned int mouse_x, unsigned int mouse_y)
{
	POINT mouse = { mouse_x, mouse_y };
	POINT temp = { 20, 20 };

	mouse -= local_coord;
	mouse -= 9;
	temp.x = round(((double)mouse.x) / gridSize);
	temp.y = round(((double)mouse.y) / gridSize);

	return temp;
}

POINT cGame_omok::IndexToCoord(unsigned int index_x, unsigned int index_y)
{
	POINT field_coord = local_coord;
	field_coord += 9;
	field_coord.x += index_x * gridSize;
	field_coord.y += index_y * gridSize;
	return field_coord;
}

bool cGame_omok::setPlayLog(omok_playlog& log)
{
	field[log.index.y][log.index.x] = log.player_type;
	player_turn = log.player_turn;
	return true;
}


bool cGame_omok::CheckGameEnd(POINT index, int color)
{
	int count = 0;
	POINT temp = index;
	// °¡·Î
	while (!(temp.x >= 19))
	{
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x++;

		}
		else
			break;
	}
	temp = index;
	temp.x--;

	while (!(temp.x < 0))
	{
		
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x--;
		}
		else
			break;
	}
	if (count == 5)
		return true;
	// ¼¼·Î
	count = 0;
	temp = index;
	while (!(temp.y >= 19))
	{
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.y++;
		}
		else
			break;
	}
	temp = index;
	temp.y--;

	while (!(temp.y < 0))
	{
		
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.y--;
		}
		else
			break;
	}
	if (count == 5)
		return true;
	// ÁÂ»ó->¿ìÇÏ
	count = 0;
	temp = index;
	while (!(temp.x >= 19 || temp.y >= 19))
	{
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x++;
			temp.y++;

		}
		else
			break;
	}
	temp = index;
	temp.x--;
	temp.y--;

	while (!(temp.x < 0 || temp.y < 0))
	{
		
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x--;
			temp.y--;
		}
		else
			break;
	}
	if (count == 5)
		return true;
	// ¿ì»ó->ÁÂÇÏ
	count = 0;
	temp = index;
	while (!(temp.x >= 19 || temp.y < 0))
	{
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x++;
			temp.y--;
		}
		else
			break;
	}
	temp = index;
	temp.x--;
	temp.y++;

	while (!(temp.x < 0 || temp.y >= 19))
	{
		
		if (field[temp.y][temp.x] == color)
		{
			count++;
			temp.x--;
			temp.y++;
		}
		else
			break;
	}
	if (count == 5)
		return true;


	return false;
}

int cGame_omok::GameOver(int winner)
{
	TCHAR message[10];
	if (winner == BLACK)
		_tcscpy_s(message,_T("ÈæÀÇ ½Â¸®!"));

	else
		_tcscpy_s(message, _T("¹éÀÇ ½Â¸®!"));

	return MessageBox(NULL, message, _T("Á¾·á"), MB_OK);
}