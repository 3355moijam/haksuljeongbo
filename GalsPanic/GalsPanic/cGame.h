#pragma once
#include "framework.h"
//#include <vector>
//using std::vector;

class cPlayer;
//class cArea;

class cArea
{
private:
	HRGN region;
	HRGN OriginRegion;
	HRGN MaskRegion;
	HBITMAP img;
	BITMAP imgData;
	double imgSize;
	double areaSize;
public:
	polygon vertex;
	cArea();
	~cArea();
	void show(HDC hdc);
	void update();
	HRGN get_region() { return region; }
	double PtOnArea(POINT &target);
	void set_new_area(polygon &path, double start, double end);
	void setSize() { areaSize = getPolyArea(vertex); }
};

class cPlayer
{
private:
	int radius;
	int speed;
	int from;
	int to;
	int before_direct;
	int current_direct;
	polygon path;
	void setDirect(const POINT &temp);
	void setDirect();
	bool check_comeback(cArea &area);
public:
	POINT center;
	cPlayer();
	cPlayer(int _x, int _y);
	void show(HDC hdc);
	bool move(cArea & area);
	int get_from() { return from; }
	int get_to() { return to; }
	void path_rewind();
	bool PtOnPath(POINT & target);
	void update();
};

class cGame
{
private:
	cPlayer player;
	cArea area;
public:
	cGame();
	~cGame();
	void show(HDC hdc);
	void move(WPARAM wParam);
	void update();
};
