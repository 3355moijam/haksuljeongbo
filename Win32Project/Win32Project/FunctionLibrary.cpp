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
void DrawStar(HDC hdc, POINT *center, int radius)
{
	POINT star[10];
	star[0] = { center->x, (center->y - radius) };
	for (int i = 2; i < 10; i += 2)
	{
		star[i] = PointRotate(center->x, center->y, 72, &star[i - 2]);
	}
	double a = (double)(star[0].y - star[4].y) / (double)(star[0].x - star[4].x);
	double b = star[0].y - a * star[0].x;
	star[1].x = (star[2].y - b) / a;
	star[1].y = star[2].y;

	for (int i = 3; i < 10; i += 2)
	{
		star[i] = PointRotate(center->x, center->y, 72, &star[i - 2]);
	}

	Polygon(hdc, star, 10);
}