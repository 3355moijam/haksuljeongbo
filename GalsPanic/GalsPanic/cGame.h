#pragma once
#include "framework.h"
#include <vector>
using std::vector;

//class cPlayer;
//class cArea;

class cArea
{
private:
	HRGN region;
public:
	vector<POINT> vertex;
	cArea();
	void show(HDC hdc);
	void update();
	HRGN get_region() { return region; }
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
public:
	POINT center;
	cPlayer();
	cPlayer(int _x, int _y);
	void show(HDC hdc);
	bool move(WPARAM wParam, cArea* area);
	int get_from() { return from; }
	int get_to() { return to; }
	int set_to();

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