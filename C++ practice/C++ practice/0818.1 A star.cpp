#include "stdafx.h"
#include <cmath>
#include <algorithm>
#define MAPSIZE 10
#define INF 1024
struct Point
{
	short x, y;
};

bool operator==(Point& left, Point& right) { return (left.x == right.x) && (left.y == right.y); }


struct node
{
	int g_value;
	int h_value;
	int f_value;
	unsigned short before_direct;
};
enum { VOID, WALL, START, END, SEARCH, VISIT };
node routeMap[MAPSIZE][MAPSIZE] = { 0 };
int Map[MAPSIZE][MAPSIZE] =
{
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1 },
	{ 0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,1,1,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};
vector<Point> path_stack;

void Astar(Point &src, Point &target);
void Astar_recur(Point src, Point target);
void setH(Point target, Point *tempPoint);
void setG(Point src, Point *tempPoint);
void setF(Point *tempPoint);
void initRouteMap();

int main()
{
	Point start = { 0,0 };
	Point end = { 6,9 };
	Astar(start, end);
	return 0;
}

void Astar(Point &src, Point &target)
{
	initRouteMap();
	Map[src.y][src.x] = START;
	Map[target.y][target.x] = END;
	routeMap[src.y][src.x].g_value = 0;
	Astar_recur(src, target);
}

void Astar_recur(Point src, Point target)
{
	if (src == target)
		return;
	if (Map[src.y][src.x] != START)
		Map[src.y][src.x] = VISIT;
	// 1. 8방향 fgh를 구한다
	Point tempPoint[9];
	fill_n(tempPoint, 9, src);
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
		if (Map[tempPoint[i].y][tempPoint[i].x] == VOID)
			Map[tempPoint[i].y][tempPoint[i].x] = SEARCH;
	}
	setH(target, tempPoint);
	setG(src, tempPoint);
	setF(tempPoint);
	// 2. f가 가장 작은 노드를 src로 재귀
	Point tempIndex = { -1,-1 };
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == SEARCH)
		{
			if (tempIndex.x == -1)
				tempIndex = tempPoint[i];
			if (routeMap[tempIndex.y][tempIndex.x].f_value > routeMap[tempPoint[i].y][tempPoint[i].x].f_value)
				tempIndex = tempPoint[i];
		}
		
	}

	Astar_recur(tempIndex, target);
}

void setH(Point target, Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == SEARCH)
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

void setG(Point src, Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		if (tempPoint[i].x < 0 || tempPoint[i].x >= MAPSIZE || tempPoint[i].y < 0 || tempPoint[i].y >= MAPSIZE)
			continue;
		if (Map[tempPoint[i].y][tempPoint[i].x] == SEARCH)
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

void setF(Point *tempPoint)
{
	for (size_t i = 1; i < 9; i++)
	{
		routeMap[tempPoint[i].y][tempPoint[i].x].f_value = routeMap[tempPoint[i].y][tempPoint[i].x].g_value + routeMap[tempPoint[i].y][tempPoint[i].x].h_value;
	}
}

void initRouteMap()
{
	for (size_t i = 0; i < MAPSIZE; i++)
	{
		for (size_t j = 0; j < MAPSIZE; j++)
		{ // i = x, j = y
			routeMap[j][i].g_value = INF;
		}
	}
}