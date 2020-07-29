#pragma once
#include "framework.h"
#include <vector>
using std::vector;

class cPlayer;
//class cArea;

class cArea
{
private:
	HRGN region;
public:
	vector<POINT> vertex;
	cArea();
	~cArea();
	void show(HDC hdc);
	void update();
	HRGN get_region() { return region; }
	double PtOnArea(POINT &target);
	void set_new_area(cPlayer &player, vector<POINT> &path, double start, double end);
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
	vector<POINT> path;
	bool check_comeback(cArea &area);
public:
	POINT center;
	cPlayer();
	cPlayer(int _x, int _y);
	void show(HDC hdc);
	bool move(WPARAM wParam, cArea & area);
	int get_from() { return from; }
	int get_to() { return to; }
	void path_rewind();
	bool PtOnPath(POINT & target);
	
	

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
};
