#pragma once
#define _USE_MATH_DEFINES
#include "framework.h"
#include "cEnemy.h"
#include <cmath>
extern RECT g_view;
//class cPlayer;
const int framerate = 60;
const int anim_idle_time = 1;
const int anim_move_time = 3;
const int anim_shoot_time = 3;
//const int shoot_delay = 10; // 재장전시간은 bullet이 가지고 있다.
vector<cBullet*> BulletContainer;
int cEnemySnakeBody::move_speed = 10;

void cEnemySnake::anim_idle()
{
	idle_count--;
	if (idle_count == 0)
	{
		idle_count = anim_idle_time * framerate;
		current_state = cEnemySnake::state::move;
	}
}

void cEnemySnake::anim_move(cArea& area)
{
	// >> 방향 설정하기
	if (move_count == anim_move_time * framerate)
	{
		body_parts[0]->set_direct(setRandomDirect());
	}
	// <<
	move_count--;
	// >> 이동 전 몸통 방향 초기화
	for (size_t i = 1; i < body_parts.size(); i++)
	{
		body_parts[i]->set_direct();
	}
	// <<
	// >> 이동하기
	//for (int i = body_parts.size() - 1; i >= 0; i--)
	for (size_t i = 0; i < body_parts.size(); i++)
	{
		body_parts[i]->move(area);
	}
	if (move_count == 0)
	{
		move_count = anim_move_time * framerate;
		current_state = cEnemySnake::state::shoot;
	}
	// <<
}

void cEnemySnake::anim_shoot(cPlayer& player)
{
	if (shoot_count)
	{
	// >> 3초간 캐릭터 추적
		shoot_count--;
		body_parts[0]->set_direct(player.get_center());
	// <<
	}
	else
	{
	// >> 슈팅 딜레이를 두고 총알 발사
		current_state = cEnemySnake::state::idle;
	// << 
	}
}

cEnemySnake::cEnemySnake() : direct(-M_PI_2), current_state(cEnemySnake::state::idle), idle_count(anim_idle_time * framerate),
							move_count(anim_move_time * framerate), shoot_count(anim_shoot_time * framerate)
{
	new cEnemySnakeHead({ g_view.right - 100, g_view.bottom - 100 }, &body_parts);
	for (size_t i = 0; i < 10; i++)
	{
		//POINT temp = body_parts[i]->get_center();
		//temp.y += body_parts[i]->get_radius() + 10;
		new cEnemySnakeBody(&body_parts);
	}
}


cEnemySnake::~cEnemySnake()
{
	while (BulletContainer.size())
		delete BulletContainer[0];
}

void cEnemySnake::show(HDC hdc)
{
	int length = body_parts.size();
	for (size_t i = 0; i < length; i++)
	{
		body_parts[i]->show(hdc);
	}
}

void cEnemySnake::update(cPlayer& player, cArea& area)
{
	switch (current_state)
	{
	case cEnemySnake::state::idle:
		anim_idle();
		break;
	case cEnemySnake::state::move:
		anim_move(area);
		break;
	case cEnemySnake::state::shoot:
		anim_shoot(player);
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

cEnemySnakeBody::cEnemySnakeBody(vector<cEnemySnakeBody*>* vec) : vecBody(vec), radius(10), direct(-M_PI_2)
{
	body_index = vecBody->size();
	vecBody->push_back(this);
	if (body_index != 0)
	{
		center = (*vecBody)[body_index - 1]->center;
		center.y += radius + (*vecBody)[body_index - 1]->radius;
		move_destination = (*vecBody)[body_index - 1]->center;
		direct = directFromTo(center, move_destination);
	}
}

int cEnemySnakeBody::get_index()
{
	for (int i = 0;; i++)
	{
		if ((*vecBody)[i] == this)
			return i;
	}
}

void cEnemySnakeBody::set_direct()
{
	//if (body_index != 0 && sqrt(PtDistance(center, move_destination)) <= (move_speed >> 1))
	//{
		move_destination = (*vecBody)[body_index - 1]->center;
		direct = directFromTo(center, move_destination);
	//}
}

void cEnemySnakeBody::move(cArea& area)
{
	POINT temp = center;
	temp.x += cos(direct) * move_speed;
	temp.y += sin(direct) * move_speed;
	if (PtDistance(temp, (*vecBody)[body_index - 1]->center) >= pow(radius + (*vecBody)[body_index - 1]->radius,2))
		center = temp;
}

cEnemySnakeBody::~cEnemySnakeBody()
{
	int index = get_index();
	vecBody->erase(vecBody->begin() + index);
}

void cEnemySnakeBody::show(HDC hdc)
{
	DrawCircle(hdc, center, radius);
}


cEnemySnakeHead::~cEnemySnakeHead()
{
}

void cEnemySnakeHead::show(HDC hdc)
{
	poly[0].x = center.x + cos(direct) * radius;
	poly[0].y = center.y + sin(direct) * radius;
	poly[1] = PointRotate(center.x, center.y, 140, poly[0]);
	poly[2] = PointRotate(center.x, center.y, 180, poly[0]);
	poly[3] = PointRotate(center.x, center.y, 220, poly[0]);

	MoveToEx(hdc, center);
	LineTo(hdc, poly[0]);
	Polygon(hdc, poly, 4);
}

void cEnemySnakeHead::move(cArea& area)
{
	POINT temp = center;
	temp.x += cos(direct) * move_speed;
	temp.y += sin(direct) * move_speed;

	if (PtInRect(&g_view, temp) && !PtInPoly(area.vertex,temp))
		center = temp;
	else
		direct = setRandomDirect();
}

int cSpeedBullet::delay = 3;
cSpeedBullet::cSpeedBullet(double dir, const POINT& cen) : cBullet(dir, cen), bullet_length(30)
{
	bullet_speed = 25;
}


void cSpeedBullet::show(HDC hdc)
{
	POINT temp = center;
	temp.x += cos(direct) * bullet_length;
	temp.y += sin(direct) * bullet_length;
	MoveToEx(hdc, center);
	LineTo(hdc, temp);
	
}

void cSpeedBullet::move()
{
	center.x += cos(direct) * bullet_speed;
	center.y += sin(direct) * bullet_speed;

	if (!PtInRect(&g_view, center))
		delete this;
}

bool cSpeedBullet::isCollide(cPlayer& player)
{
	if (player.get_path().size())
	{
		// 플레이어 판정
		// 코사인(각도차) * 거리 = 원과 직선사이의 거리
		// 경로 판정
		// 
	}
	else
		return false;
}
