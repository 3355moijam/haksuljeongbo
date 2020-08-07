#pragma once
#define _USE_MATH_DEFINES
#include "framework.h"
#include <cmath>
#include "FunctionLibrary.h"
#include <random>


std::random_device rd;
std::mt19937_64 gen(rd());


void randomArr(int * arr, int size, int from, int to)
{
	std::uniform_int_distribution<int> dis(from, to); // 원하는 범위의 숫자

	for (size_t i = 0; i < size; i++)
		arr[i] = dis(gen);
}

int randomInt(int from, int to)
{
	std::uniform_int_distribution<int> dis(from, to);

	return dis(gen);
}

double DegreeToRadian(int arcDegree)
{
	return arcDegree * (M_PI / 180);
}

POINT PointRotate(int centerX, int centerY, int degree, const POINT &point)
{
	double rad = DegreeToRadian(degree);

	double tempX = cos(rad) * (point.x - centerX) - sin(rad) * (point.y - centerY);
	double tempY = sin(rad) * (point.x - centerX) + cos(rad) * (point.y - centerY);

	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

POINT PointRotate(int centerX, int centerY, double rad, const POINT &point)
{
	double tempX = cos(rad) * (point.x - centerX) - sin(rad) * (point.y - centerY);
	double tempY = sin(rad) * (point.x - centerX) + cos(rad) * (point.y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
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

void DrawCircle(HDC hdc, POINT center, int radius)
{
	Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

BOOL MoveToEx(HDC hdc, POINT to)
{
	return MoveToEx(hdc, to.x, to.y, NULL);
}

BOOL LineTo(HDC hdc, POINT to)
{
	return LineTo(hdc, to.x, to.y);
}

bool isBetweenPt(POINT& target, POINT& p1, POINT& p2, int mode)
{
	if (mode == 0)
	{
		if (p1.x == p2.x)
		{
			if (target.x != p1.x)
				return false;

			if (target.y >= p1.y && target.y <= p2.y)
				return true;
			else if (target.y <= p1.y && target.y >= p2.y)
				return true;
			else
				return false;
		}
		else if (p1.y == p2.y)
		{
			if (target.y != p1.y)
				return false;

			if (target.x >= p1.x && target.x <= p2.x)
				return true;
			else if (target.x <= p1.x && target.x >= p2.x)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (p1.x == p2.x)
		{
			if (target.x != p1.x)
				return false;

			if (target.y > p1.y && target.y < p2.y)
				return true;
			else if (target.y < p1.y && target.y > p2.y)
				return true;
			else
				return false;
		}
		else if (p1.y == p2.y)
		{
			if (target.y != p1.y)
				return false;

			if (target.x > p1.x && target.x < p2.x)
				return true;
			else if (target.x < p1.x && target.x > p2.x)
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

bool operator==(const POINT& lhs, const POINT& rhs)
{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool operator!=(const POINT& lhs, const POINT& rhs)
{
	return (lhs.x != rhs.x) || (lhs.y != rhs.y);
}

POINT operator-(const POINT& lhs, const POINT& rhs)
{
	return{ lhs.x - rhs.x,lhs.y - rhs.y };
}

HRGN CreatePolyVectorRgn(polygon &poly, int iMode)
{
	unsigned int length = poly.size();
	POINT * temp = new POINT[length];
	for (size_t i = 0; i < length; i++)
		temp[i] = poly[i];

	HRGN rgn = CreatePolygonRgn(temp, length, iMode);
	delete[] temp;

	return rgn;
}

BOOL PtInRegion(HRGN &hrgn, POINT &target)
{
	return PtInRegion(hrgn, target.x, target.y);
}

bool PtOnPoly(polygon &poly, POINT &target)
{
	bool position = false;
	int length = poly.size();
	for (int i = 0; i < length; i++)
	{
		int temp = i + 1;
		if (temp == length)
			temp = 0;

		if (target == poly[i])
		{
			position = true;
			break;
		}
		else if (isBetweenPt(target, poly[i], poly[temp]))
		{
			position = true;
			break;
		}
	}
	return position;
}

int PtDistance(const POINT &p1, const POINT &p2)
{
	return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
}

bool PtInPoly(const polygon & poly, POINT & target) 
{
	int crosses = 0;
	unsigned int length = poly.size();
	for (size_t i = 0; i < length; i++)
	{
		int j = (i + 1) % poly.size();
		
		//if (((poly[i].y >= target.y) && (poly[j].y < target.y)) || ((poly[i].y <= target.y) && (poly[j].y > target.y)))
		if((poly[i].y > target.y) != (poly[j].y > target.y))
		{
			
			double atX = (poly[j].x - poly[i].x)*(target.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x;
			
			if (target.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}

long getPolyArea(const polygon& poly)
{
	long sum = 0, diff = 0, area = 0;
	int length = poly.size();
	for (int i = 0; i < length; i++)
	{
		sum += poly[i].x * poly[(i + 1) % length].y;
		diff += poly[i].y * poly[(i + 1) % length].x;
	}
	area = abs(sum - diff) >> 1;
	return area;
}

void makeRect(polygon &poly)
{
	int x, y, width, height;
	x = randomInt(10, 50) * 10;
	y = randomInt(10, 50) * 10;
	width = randomInt(1, 20) * 10;
	height = randomInt(1, 20) * 10;

	poly.push_back({ x, y });
	poly.push_back({ x + width, y });
	poly.push_back({ x + width, y + height });
	poly.push_back({ x, y + height });
}

double directFromTo(const POINT &from, const POINT &to)
{
	return atan2(to.y - from.y, to.x - from.x);
}

double setRandomDirect()
{
	int arc_degree = randomInt(0, 359);
	return DegreeToRadian(arc_degree);
}