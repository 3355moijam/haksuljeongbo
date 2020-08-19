#pragma once
#include "stdafx.h"
#define MAPSIZE 10
#define INF 1024
enum { EMPTY, WALL, START, END, SEARCH, VISIT };

struct Point
{
	short x, y;
};

struct node
{
	int g_value;
	int h_value;
	int f_value;
	unsigned short before_direct;
};

class cAstar
{
private:
	Point start;
	Point end;
	Point current;
	node routeMap[MAPSIZE][MAPSIZE];
	int Map[MAPSIZE][MAPSIZE];
	vector<Point> vecSearch;
	cAstar();

public:
	~cAstar();

	static cAstar& GetInstance() { 
		static cAstar pathfinder; 
		return pathfinder; }
	bool path_find();
	void setH(Point target, Point *tempPoint);
	void setG(Point src, Point *tempPoint);
	void setF(Point *tempPoint);
	void initRouteMap();
	void show(HDC hdc);
	void setPath();
	cAstar(cAstar const&) = delete;
	cAstar(cAstar&&) = delete;
	cAstar& operator=(cAstar const&) = delete;
	cAstar& operator=(cAstar&&) = delete;

};