#pragma once
#include "stdafx.h"
#include "cAstar.h"
#include <string>
vector<Point> path_stack;


//node cAstar::routeMap[MAPSIZE][MAPSIZE] = { 0 };
//int cAstar::Map[MAPSIZE][MAPSIZE] =
//{
//	{ 0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,1,1,1 },
//	{ 0,0,0,0,0,0,0,1,0,0 },
//	{ 0,0,0,0,0,0,0,1,0,0 },
//	{ 0,0,0,0,0,0,0,1,0,0 },
//	{ 0,0,0,1,1,1,1,1,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0 }
//};
bool operator==(Point& left, Point& right) { return (left.x == right.x) && (left.y == right.y); }

cAstar::cAstar() : start(), end(), current(), vecSearch()
{
	start = { 0,0 };
	end = { 9,9 };
	current = start;

	//memset(routeMap, 0, sizeof(routeMap));
	int tempMap[MAPSIZE][MAPSIZE] =
	{
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,0,0,0,0,1,1,0 },
		{ 0,0,1,1,0,0,0,1,0,0 },
		{ 0,0,0,1,1,0,0,1,0,0 },
		{ 0,0,0,0,1,1,0,1,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 }
	};
	memcpy(Map, tempMap, sizeof(tempMap));

	initRouteMap();
	Map[start.y][start.x] = START;
	Map[end.y][end.x] = END;
	routeMap[start.y][start.x].g_value = 0;
}


cAstar::~cAstar()
{
}


bool cAstar::path_find()
{
	if (current == end)
		return true;
	if (Map[current.y][current.x] != START)
	{
		Map[current.y][current.x] = VISIT;
		for (size_t i = 0; i < vecSearch.size(); i++)
		{
			if (vecSearch[i] == current)
			{
				vecSearch.erase(vecSearch.begin() + i);
				break;
			}
		}
	}

	// 1. 8방향 fgh를 구한다
	Point tempPoint[9];
	std::fill_n(tempPoint, 9, current);
	{
		tempPoint[1].x--;
		tempPoint[2].y--;
		tempPoint[3].x++;
		tempPoint[4].y++;

		tempPoint[5].x--;
		tempPoint[5].y--;
		tempPoint[6].x++;
		tempPoint[6].y--;
		tempPoint[7].x++;
		tempPoint[7].y++;
		tempPoint[8].x--;
		tempPoint[8].y++;
	}
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == EMPTY)
		{
			Map[tempPoint[i].y][tempPoint[i].x] = SEARCH;
			vecSearch.push_back(tempPoint[i]);
		}
		else if (Map[tempPoint[i].y][tempPoint[i].x] == END)
		{
			setH(end, tempPoint);
			setG(current, tempPoint);
			setF(tempPoint);
			setPath();
			return true;
		}
	}
	setH(end, tempPoint);
	setG(current, tempPoint);
	setF(tempPoint);
	// 2. f가 가장 작은 노드를 current로 재귀
	Point tempIndex;
	if (vecSearch.size())
	{
		tempIndex = vecSearch[0];
		for (size_t i = 1; i < vecSearch.size(); i++)
		{
			//if (routeMap[tempIndex.y][tempIndex.x].f_value > routeMap[vecSearch[i].y][vecSearch[i].x].f_value)
			//	tempIndex = vecSearch[i];

			//if (routeMap[tempIndex.y][tempIndex.x].h_value > routeMap[vecSearch[i].y][vecSearch[i].x].h_value)
			//	tempIndex = vecSearch[i];
			//else if (routeMap[tempIndex.y][tempIndex.x].h_value == routeMap[vecSearch[i].y][vecSearch[i].x].h_value)
			//	if (routeMap[tempIndex.y][tempIndex.x].f_value > routeMap[vecSearch[i].y][vecSearch[i].x].f_value)
			//		tempIndex = vecSearch[i];

			if (routeMap[tempIndex.y][tempIndex.x].f_value + routeMap[tempIndex.y][tempIndex.x].h_value > routeMap[vecSearch[i].y][vecSearch[i].x].f_value + routeMap[vecSearch[i].y][vecSearch[i].x].h_value)
				tempIndex = vecSearch[i];
		}
	}
	else
		return true; // 길이 막힘

	current = tempIndex;
	return false;
}

void cAstar::setH(Point target, Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == SEARCH || Map[tempPoint[i].y][tempPoint[i].x] == END)
		{
			Point temp;
			int h = 0;
			temp.x = abs(tempPoint[i].x - target.x);
			temp.y = abs(tempPoint[i].y - target.y);

			h += min(temp.x, temp.y) * 14;
			h += abs(temp.x - temp.y) * 10;

			routeMap[tempPoint[i].y][tempPoint[i].x].h_value = h;
		}
	}
}

void cAstar::setG(Point src, Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == SEARCH || Map[tempPoint[i].y][tempPoint[i].x] == END)
		{
			int tempG = 0;
			tempG = routeMap[src.y][src.x].g_value;
			if (i < 5)
				tempG += 10;
			else
				tempG += 14;

			if (tempG < routeMap[tempPoint[i].y][tempPoint[i].x].g_value)
			{
				routeMap[tempPoint[i].y][tempPoint[i].x].g_value = tempG;
				routeMap[tempPoint[i].y][tempPoint[i].x].before_direct = i;
			}
		}
	}
}

void cAstar::setF(Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		routeMap[tempPoint[i].y][tempPoint[i].x].f_value = routeMap[tempPoint[i].y][tempPoint[i].x].g_value + routeMap[tempPoint[i].y][tempPoint[i].x].h_value;
	}
}

void cAstar::initRouteMap()
{
	for (size_t i = 0; i < MAPSIZE; i++)
	{
		for (size_t j = 0; j < MAPSIZE; j++)
		{ // i = x, j = y
			routeMap[j][i].g_value = INF;
		}
	}
}

void cAstar::show(HDC hdc)
{
	HBRUSH hbrRed = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hbrBlue = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH hbrGreen = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hbrMagenta = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH hbrYellow = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hbrRed);
	POINT center; int width = 30;
	for (size_t i = 0; i < MAPSIZE; i++)
	{
		for (size_t j = 0; j < MAPSIZE; j++)
		{
			switch (Map[j][i])
			{
			case WALL:
				SelectObject(hdc, hbrBlue);
				break;
			case START:
				SelectObject(hdc, hbrRed);
				break;
			case END:
				SelectObject(hdc, hbrYellow);
				break;
			case SEARCH:
				SelectObject(hdc, hbrGreen);
				break;
			case VISIT:
				SelectObject(hdc, hbrMagenta);
				break;
			default:
				SelectObject(hdc, hOldBrush);
				break;
			}
			center.x = i * width * 2 + width;
			center.y = j * width * 2 + width;
			DrawSquare(hdc, center, width);

			if (Map[j][i] == START || Map[j][i] == VISIT || Map[j][i] == SEARCH || Map[j][i] == END)
			{
				using std::wstring;
				RECT textbox = { center.x - width, center.y - width, center.x + width, center.y + width };
				wstring tempText = std::to_wstring(routeMap[j][i].g_value) + _T("   ") + std::to_wstring(routeMap[j][i].h_value) + _T("\n  ") + std::to_wstring(routeMap[j][i].f_value);
				DrawText(hdc, tempText.c_str(), tempText.size(), &textbox, 0);
			}
		}
	}
	if (path_stack.size())
	{
		center.x = path_stack.back().x * width * 2 + width;
		center.y = path_stack.back().y * width * 2 + width;
		MoveToEx(hdc, center.x, center.y, NULL);
		path_stack.pop_back();
		while (path_stack.size())
		{
			center.x = path_stack.back().x * width * 2 + width;
			center.y = path_stack.back().y * width * 2 + width;
			LineTo(hdc, center.x, center.y);
			path_stack.pop_back();
		}
	}

	SelectObject(hdc, hOldBrush);
	DeleteObject(hbrRed);
	DeleteObject(hbrBlue);
	DeleteObject(hbrGreen);
	DeleteObject(hbrMagenta);
	DeleteObject(hbrYellow);
}

void cAstar::setPath()
{
	//path_stack.push_back(end);
	Point temp = end;
	while (!(temp == start))
	{

		path_stack.push_back(temp);
		switch (routeMap[temp.y][temp.x].before_direct)
		{
		case 1:
			temp.x++;
			break;
		case 2:
			temp.y++;
			break;
		case 3:
			temp.x--;
			break;
		case 4:
			temp.y--;
			break;
		case 5:
			temp.x++;
			temp.y++;
			break;
		case 6:
			temp.x--;
			temp.y++;
			break;
		case 7:
			temp.x--;
			temp.y--;
			break;
		case 8:
			temp.x++;
			temp.y--;
			break;
		default:
			break;
		}

	}
	path_stack.push_back(temp);
}

