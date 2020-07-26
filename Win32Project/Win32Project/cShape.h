#pragma once
#include "stdafx.h"

class cShape;
extern vector<cShape*> shapeList;

class cShape
{
private:
	static int mode;
	int getIndex();
	void bound();
	void broken(cShape* target, double vec);
protected:
	POINT pos;
	int radius;

	enum class shape { circle, rect, star };
	shape type;

	double rot;
	double rotate_speed;
	double move_speed;
	double move_direct;

	cShape* collide;
	double getDistance(cShape* tar);
public:
	cShape(int x, int y);
	virtual ~cShape();
	bool collision();
	virtual void show(HDC hdc) = 0;
	virtual void move();
	virtual void rotate();

	static void set_mode(int n);
	static void create(LPARAM lParam);
	static void update();
	static void check_set();
	static void draw(HDC hdc);
	static void delete_all();
	POINT position() { return pos; }

};

class cCircle : public cShape
{
public:
	cCircle(int x, int y);
	virtual ~cCircle();
	void show(HDC hdc);
	void rotate();
};


class cRect : public cShape
{
private:
	POINT poly[4];
public:
	cRect(int x, int y);
	virtual ~cRect();
	void show(HDC hdc);
};

class cStar : public cShape
{
private:
	POINT poly[5];
public:
	cStar(int x, int y);
	virtual ~cStar();
	void show(HDC hdc);
};