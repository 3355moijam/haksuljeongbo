#pragma once
#include "framework.h"
//#include <vector>
//using std::vector;
class cEnemySnake;
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
	class cCircularEffect
	{
	private:
		POINT poly[4];
		POINT center;
		int effect_radius;
		int particle_radius;
		double rotate_speed;
		double direct;
	public:
		cCircularEffect();
		void set_center(const POINT &pt) { center = pt; }
		void set_effect_radius(int radius);
		void set_poly();
		void set_rotate(int mode);
		void rotate(){ direct += rotate_speed; }
		void show(HDC hdc);
		void update(const POINT &pt);
	};
	int radius;
	int speed;
	int from;
	int to;
	int before_direct;
	int current_direct;
	polygon path;
	cCircularEffect effect;
	void setDirect(const POINT &temp);
	void setDirect();
	bool check_comeback(cArea &area);
	POINT center;
public:
	cPlayer();
	cPlayer(int _x, int _y);
	void set_center(POINT &cen) { center = cen; }
	void show(HDC hdc);
	bool move(cArea & area);
	POINT& get_center() { return center; }
	int get_from() { return from; }
	int get_to() { return to; }
	const polygon& get_path() { return path; }
	void path_rewind();
	bool PtOnPath(POINT & target);

	void update();
};

class cGame
{
private:
	cPlayer player;
	cArea area;
	cEnemySnake snake;
public:
	cGame();
	~cGame();
	void show(HDC hdc);
	void move();
	void update();
};
