#pragma once
#define _USE_MATH_DEFINES
#include "framework.h"
#include "cEnemy.h"
#include <cmath>

extern RECT view;
vector<cBullet*> BulletContainer;

cEnemy::cEnemy() : direct(-M_PI_2), current_state(cEnemy::state::idle)
{
	new cEnemyHead({ view.right - 100, view.bottom - 100 }, &body);
	for (size_t i = 0; i < 5; i++)
	{
		POINT temp = body[i]->get_center();
		temp.y += body[i]->get_radius();
		new cEnemyBody(temp, &body);
	}
}


cEnemy::~cEnemy()
{
	while (BulletContainer.size())
		delete BulletContainer[0];
}

void cEnemy::show(HDC hdc)
{
	int length = body.size();
	for (size_t i = 0; i < length; i++)
	{
		body[i]->show(hdc);
	}
}

void cEnemy::update()
{
	switch (current_state)
	{
	case cEnemy::state::idle:
		anim_idle();
		break;
	case cEnemy::state::move:
		anim_move();
		break;
	case cEnemy::state::shoot:
		anim_shoot();
		break;
	default:
		break;
	}
}

cBullet::cBullet(double dir, const POINT &cen) : lifetime(5), direct(dir), center(cen)
{
	BulletContainer.push_back(this);
}

cBullet::~cBullet()
{
	int index = get_index();
	BulletContainer.erase(BulletContainer.begin() + index);
}

int cBullet::get_index()
{
	for (size_t i = 0;; i++)
	{
		if(BulletContainer[i] == this)
			return i;
	}
}

void cBullet::update()
{
	move();
	if (lifetime == 0)
		delete this;
}

cEnemyBody::cEnemyBody(POINT cen, vector<cEnemyBody*>* vec) : center(cen), vecBody(vec), radius(20), direct()
{
	vecBody->push_back(this);
}

int cEnemyBody::get_index()
{
	for (int i = 0;; i++)
	{
		if ((*vecBody)[i] == this)
			return i;
	}
}

cEnemyBody::~cEnemyBody()
{
	int index = get_index();
	vecBody->erase(vecBody->begin() + index);
}

void cEnemyBody::show(HDC hdc)
{
	DrawCircle(hdc, center, radius);
}


cEnemyHead::~cEnemyHead()
{
}

void cEnemyHead::show(HDC hdc)
{
	poly[0].x = cos(direct) * radius;
	poly[0].y = sin(direct) * radius;
	poly[1] = PointRotate(center.x, center.y, M_PI / 3, poly[0]);
	poly[2] = PointRotate(center.x, center.y, M_PI / 3, poly[1]);

	MoveToEx(hdc, center);
	LineTo(hdc, poly[0]);
	Polygon(hdc, poly, 3);
}
