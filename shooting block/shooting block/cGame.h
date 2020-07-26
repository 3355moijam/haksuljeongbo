#pragma once
#include "stdafx.h"

class cGame;
enum {nCharacter, nBullet, nBlock, nEffect};

class cGame
{
private:
	static bool start;
protected:
	POINT center;
	double direct;
	
public:
	cGame(int x, int y, double dir = 0);
	virtual ~cGame();
	virtual int find_self() = 0;
	virtual void show(HDC hdc) = 0;
	virtual bool move() { return false; }
	POINT* get_center() { return &center; }
	double get_direct() { return direct; }
	void set_direct(int x, int y);

	static void init();
	static void draw(HDC hdc);
	static bool is_start() { return start; }
	static void set_start() { start = !start; }
	static void update();
	static void delete_all();
	
};

class cChar :public cGame
{
private:
	POINT poly[4];
	POINT temp[4];
	int radius;
public:
	cChar();
	~cChar();
	int find_self();
	void show(HDC hdc);
	void shoot();
};

class cBullet :public cGame
{
private:
	int radius;
	double move_speed;
	static int count;
	static int max;
public:
	cBullet(int x, int y, double dir);
	~cBullet();
	int find_self();
	void show(HDC hdc);
	bool move(); 
	bool collide();

	static int get_count() { return count; }
	static int get_max() { return max; }
	static int is_max() { return count >= max; }
	static int max_up();
	static void init_max() { max = 3; }
	
};

class cBlock :public cGame
{
private:
	RECT rect;
	RECT collision;
	static double move_speed;
public:
	cBlock(int x, int y);
	~cBlock();
	int find_self();
	void show(HDC hdc);
	bool move();
	int collide(cBullet* target);
	static void line_create();
	static double get_speed() { return move_speed; }
	static void speed_up() { move_speed++; }
};

class cEffect : public cGame
{
protected:
	double rotate_speed;
	int c_down;
	virtual void rotate() = 0;
public:
	cEffect(const int x, const int y, double dir = 0);
	virtual ~cEffect();
	int find_self();
	virtual void show(HDC hdc) = 0;
	virtual bool move() = 0;
};

class cERect : public cEffect
{
private:
	POINT poly[4];
	void rotate();
public:
	cERect(const int x, const int y);
	void show(HDC hdc);
	bool move() 
	{
		rotate(); c_down--; 
		if (c_down < 0) { delete this; return true; } 
		return false;
	}
};

class cEStar : public cEffect
{
private:
	POINT poly[5];
	void rotate();
public:
	cEStar(const int x, const int y, double dir);
	void show(HDC hdc);
	bool move()
	{ 
		center.x += cos(direct) * 5;
		center.y += sin(direct) * 5;
		rotate(); c_down--;
		if (c_down < 0) { delete this; return true; }
		return false;
	}
};