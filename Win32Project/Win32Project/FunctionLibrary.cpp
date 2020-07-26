#pragma once
#include "stdafx.h"
#include "FunctionLibrary.h"
#include <random>

extern RECT view;

random_device rd;
mt19937_64 gen(rd());

int randomInt(int from, int to)
{
	uniform_int_distribution<int> dis(from, to);

	return dis(gen);
}


double DegreeToRadian(int arcDegree)
{
	return arcDegree * (M_PI / 180);
}

void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
}
void DrawGrid(HDC hdc, int x1, int y1, int x2, int y2, int interval)
{
	for (int i = x1; i < x2; i += interval)
	{
		for (int j = y1; j < y2; j += interval)
		{
			MoveToEx(hdc, x1, j, NULL);
			LineTo(hdc, x2, j);
			MoveToEx(hdc, i, y1, NULL);
			LineTo(hdc, i, y2);
		}
	}
	MoveToEx(hdc, x2, y1, NULL);
	LineTo(hdc, x2, y2);
	MoveToEx(hdc, x1, y2, NULL);
	LineTo(hdc, x2, y2);
}



POINT PointRotate(int centerX, int centerY, int degree, const POINT *point)
{
	double rad = DegreeToRadian(degree);

	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);

	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

POINT PointRotate(int centerX, int centerY, double rad, const POINT *point)
{
	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

void PointRotate(int centerX, int centerY, int degree, POINT &point)
{
	double rad = DegreeToRadian(degree);

	double tempX = cos(rad) * (point.x - centerX) - sin(rad) * (point.y - centerY);
	double tempY = sin(rad) * (point.x - centerX) + cos(rad) * (point.y - centerY);
	point.x = centerX + tempX;
	point.y = centerY + tempY;
}

void OutFromFile(TCHAR filename[], HWND hWnd)
{
	FILE *fPtr;
	HDC hdc;
	int line;
	TCHAR buffer[500];
	line = 0;
	hdc = GetDC(hWnd);

#ifdef _UNICODE
	_tfopen_s(&fPtr, filename, _T("r, ccs = UNICODE"));
#else
	_tfopen_s(&fPtr, filename, _T("r"));
#endif
	while (_fgetts(buffer, 100, fPtr) != NULL)
	{
		if (buffer[_tcslen(buffer) - 1] == _T('\n'))
			buffer[_tcslen(buffer) - 1] = NULL;
		TextOut(hdc, 0, line * 20, buffer, _tcslen(buffer));
		line++;
	}
	
	fclose(fPtr);
	ReleaseDC(hWnd, hdc);
}
HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP	hTransparentImage;
BITMAP bitTransparent;

HBITMAP	hAniImage;
BITMAP bitAni;
const int sprite_size_x = 57;
const int sprite_size_y = 52;
int run_right_frame_max = 0;
int run_right_frame_min = 0;
int cur_frame = run_right_frame_min;
int run_left_frame_max = 0;
int run_left_frame_min = 13;

void CreateBitmap()
{
	hBackImage = (HBITMAP)LoadImage(NULL, TEXT("file/mables.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);


	hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("file/sigong.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);


	hAniImage= (HBITMAP)LoadImage(NULL, TEXT("file/zero_run.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAniImage, sizeof(BITMAP), &bitAni);
	run_right_frame_max = bitAni.bmWidth / sprite_size_x - 1;
	run_right_frame_min = 2;
	cur_frame = 0;// run_right_frame_min;
}
//void DrawBitmap(HWND hWnd, HDC hdc)
//{
//	HDC hMemDC;//, hMemDC2;
//	HBITMAP hOldBitmap; // , hOldBitmap2;
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
//		int bx = bitBack.bmWidth;
//		int by = bitBack.bmHeight;
//		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
//		SelectObject(hMemDC, hOldBitmap);
//
//	}
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
//		int bx = bitTransparent.bmWidth;
//		int by = bitTransparent.bmHeight;
//		BitBlt(hdc, 100, 100, bx, by, hMemDC, 0, 0, SRCCOPY);
//		TransparentBlt(hdc, 200, 100, bx, by, hMemDC, 0, 0, bx, by, RGB(255,0,255));
//		SelectObject(hMemDC, hOldBitmap);
//
//	}
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
//		int bx = bitAni.bmWidth / 16;
//		int by = bitAni.bmHeight / 2;
//		int xStart = cur_frame * bx;
//		int yStart = 0;
//		//BitBlt(hdc, 400, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
//		TransparentBlt(hdc, 400, 100, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
//		SelectObject(hMemDC, hOldBitmap);
//	}
//	
//	DeleteDC(hMemDC);
//	//DeleteDC(hMemDC2);
//}
void DeleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
}

void UpdateFrame(HWND hWnd)
{
	static bool isRight = true;
	if (GetKeyState('D') & 0x8000)
	{
		if (isRight == false)
		{
			isRight = true;
			cur_frame = run_right_frame_min;
		}
		cur_frame++;
		if (cur_frame > run_right_frame_max)
		{
			cur_frame = run_right_frame_min;
		}
	}
	else if (GetKeyState('A') & 0x8000)
	{
		if (isRight == true)
		{
			isRight = false;
			cur_frame = run_left_frame_min;
		}
		cur_frame--;
		if (cur_frame < run_left_frame_max)
		{
			cur_frame = run_left_frame_min;
		}
	}
	//cur_frame %= (run_frame_max - run_frame_min);
	//cur_frame += run_frame_min;
}
extern TCHAR sKeyState[128];
void DrawRectText(HDC hdc, int xPos)
{
	TCHAR strTest[] = _T("텍스트 출력");
	TextOut(hdc, xPos, 0, strTest, _tcslen(strTest));
	TextOut(hdc, 100, 20, sKeyState, _tcslen(sKeyState));
}

HBITMAP hDoubleBufferImage;
extern POINT pos;
extern int xStart;
extern int yStart;
void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc)
{
	HDC hMemDC, hMemDC2;
	HBITMAP hOldBitmap, hOldBitmap2;
	int bx, by;

	hMemDC = CreateCompatibleDC(hdc);
	if (hDoubleBufferImage == NULL)
	{
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, view.right, view.bottom);
	}
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;
		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);
		SelectObject(hMemDC2, hOldBitmap2);

	}
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;
		BitBlt(hMemDC, 100, 100, bx, by, hMemDC2, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, 200, 100, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC2, hOldBitmap2);

	}
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;
			xStart = cur_frame * bx;
		if (GetKeyState('A') & 0x8000)
		{
			yStart = by;
		}
		else if (GetKeyState('D') & 0x8000)
		{
			yStart = 0;
			//xStart = cur_frame * bx;
		}
		//BitBlt(hdc, 400, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, pos.x, 300, bx, by, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC2, hOldBitmap2);
	}
	BitBlt(hdc, 0, 0, view.right, view.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hMemDC);
}