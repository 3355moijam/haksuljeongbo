#pragma once
#include "stdafx.h"
#include "FunctionLibrary.h"
#include <random>



std::random_device rd;
std::mt19937_64 gen(rd());
bool cGame::start = false;

int randomInt(int from, int to)
{
	std::uniform_int_distribution<int> dis(from, to);

	return dis(gen);
}


double DegreeToRadian(int arcDegree)
{
	return arcDegree * (M_PI / 180);
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

void DrawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	Ellipse(hdc, centerX - radius, centerY - radius, centerX + radius, centerY + radius);
}

BOOL DrawRectangle(HDC hdc, LPRECT rectangle)
{
	return Rectangle(hdc, rectangle->left, rectangle->top, rectangle->right, rectangle->bottom);
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

