#pragma once
#include "stdafx.h"
#include "cShape.h"

extern RECT view;
vector<cShape*> shapeList;
int cShape::mode = 1;

int cShape::getIndex()
{
	for (int i = 0; i < shapeList.size(); i++)
	{
		if (shapeList[i] == this)
			return i;
	}
	return -1;
}

void cShape::bound()
{
	POINT colpos = collide->position();
	double vec = atan2((double)(pos.y - colpos.y), (double)(pos.x - colpos.x));

	move_direct = vec;
	collide->move_direct = -vec;
}

void cShape::broken(cShape * target, double vec)
{
	int newR = target->radius - 20;
	if (newR <= 0)
		return;

	cShape* new1;
	cShape* new2;
	switch ((int)target->type)
	{
	case (int)shape::circle:
		new1 = new cCircle(target->pos.x, target->pos.y);
		new2 = new cCircle(target->pos.x, target->pos.y);
		break;
	case (int)shape::rect:
		new1 = new cRect(target->pos.x, target->pos.y);
		new2 = new cRect(target->pos.x, target->pos.y);
		break;
	case (int)shape::star:
		new1 = new cStar(target->pos.x, target->pos.y);
		new2 = new cStar(target->pos.x, target->pos.y);
		break;
	default:
		break;
	}

	new1->move_direct = vec + M_PI_2 / 3;
	new2->move_direct = vec - M_PI_2 / 3;

	new1->radius = newR;
	new2->radius = newR;

	new1->move_speed = target->move_speed + 5;
	new2->move_speed = target->move_speed + 5;

	new1->move();
	new2->move();
}

double cShape::getDistance(cShape * tar)
{
	return sqrt(pow(pos.x - tar->pos.x, 2) + pow(pos.y - tar->pos.y, 2));
}

cShape::cShape(int x, int y) : radius(50), move_speed(20), rot(0), collide(nullptr)
{
	shapeList.push_back(this);
	pos.x = x;
	pos.y = y;
	rotate_speed = randomInt(-60, 60) * M_PI / 180;
	move_direct = randomInt(0, 360) * M_PI / 180;

}


cShape::~cShape()
{
	int index = getIndex();
	shapeList.erase(shapeList.begin() + index);
}

void cShape::set_mode(int n)
{
	switch (n)
	{
	case 1:
	case 2:
	case 3:
		mode = n;
		break;
	default:
		break;
	}
}

void cShape::create(LPARAM lParam)
{
	int swch = randomInt(0, 2);
	if (swch == 0)
		cCircle* newCircle = new cCircle(LOWORD(lParam), HIWORD(lParam));

	else if (swch == 1)
		cRect* newRect = new cRect(LOWORD(lParam), HIWORD(lParam));
	else
		cStar* newStar = new cStar(LOWORD(lParam), HIWORD(lParam));
}

void cShape::update()
{
	for (int i = 0; i < shapeList.size(); i++)
	{
		shapeList[i]->rotate();
	}

	for (int i = 0; i < shapeList.size(); i++)
	{
		if (shapeList[i]->collision())
			delete shapeList[i--];
	}

	for (int i = 0; i < shapeList.size(); i++)
	{
		shapeList[i]->move();
	}

}

bool cShape::collision()
{

	int i; bool eated = false;
	for (i = getIndex() + 1; i < shapeList.size(); i++)
	{

		double dist = getDistance(shapeList[i]);
		if (dist <= radius + shapeList[i]->radius)
		{
			collide = shapeList[i];
			
			if (mode == 1)
			{
				bound();
			}
			else if (mode == 2)
			{
				switch ((((int)type - (int)collide->type) + 3) % 3)
				{
				case 0: 
					bound();
					break;
				case 1: // eat
					delete collide;
					radius += 20;
					break;
				case 2: // eated
					collide->radius += 20;
					eated = true;
					break;
				default:
					break;
				}
			}
			else if (mode == 3)
			{
				switch ((((int)type - (int)collide->type) + 3) % 3)
				{
				case 0:
					bound();
					break;
				case 1: // eat
					broken(collide, move_direct);
					delete collide;
					break;
				case 2: // eated
					broken(this, collide->move_direct);
					eated = true;
					break;
				default:
					break;
				}
			}
			
			
			break;
		}
	}

	// º® Ãæµ¹
	if (pos.y - radius <= view.top || pos.y + radius >= view.bottom)
		move_direct = (2 * M_PI) - move_direct;
	
	if (pos.x - radius <= view.left || pos.x + radius >= view.right)
		move_direct = M_PI - move_direct;
	
	return eated;
}

void cShape::move()
{
	if (pos.x + radius > view.right)
		pos.x = view.right - radius;
	else if (pos.x - radius < view.left)
		pos.x = view.left + radius;

	if (pos.y + radius > view.bottom)
		pos.y = view.bottom - radius;
	else if (pos.y - radius < view.top)
		pos.y = view.top + radius;
	double temp = collide == nullptr ? move_speed : (radius + collide->radius) / 2;
	pos.x += cos(move_direct) * temp;
	pos.y += sin(move_direct) * temp;
}

void cShape::rotate()
{
	rot += rotate_speed;
}

void cShape::check_set()
{
	for (size_t i = 0; i < shapeList.size(); i++)
	{
		shapeList[i]->collide = nullptr;
	}
}

void cShape::draw(HDC hdc)
{
	for (size_t i = 0; i < shapeList.size(); i++)
	{
		shapeList[i]->show(hdc);
	}
}

void cShape::delete_all()
{
	int size = shapeList.size();
	for (size_t i = 0; i < size; i++)
	{
		delete shapeList[0];
	}
}

cCircle::cCircle(int x, int y) : cShape(x, y)
{
	type = shape::circle;
	rotate_speed = 0;
}

cCircle::~cCircle()
{
}

void cCircle::show(HDC hdc)
{
	DrawCircle(hdc, pos.x, pos.y, radius);
	MoveToEx(hdc, pos.x, pos.y, NULL);
	LineTo(hdc, pos.x + cos(move_direct) * radius, pos.y + sin(move_direct) * radius);
		
		
}

void cCircle::rotate()
{
}

cRect::cRect(int x, int y) : cShape(x, y)
{
	type = shape::rect;

}

cRect::~cRect()
{
}

void cRect::show(HDC hdc)
{
	poly[0].x = pos.x + cos(rot) * radius;
	poly[0].y = pos.y + sin(rot) * radius;
	for (size_t i = 1; i < 4; i++)
	{
		poly[i] = PointRotate(pos.x, pos.y, M_PI_2, &poly[i - 1]);
	}

	Polygon(hdc, poly, 4);
}

cStar::cStar(int x, int y) : cShape(x, y)
{
	type = shape::star;
}

cStar::~cStar()
{
}

void cStar::show(HDC hdc)
{
	poly[0].x = pos.x + cos(rot) * radius;
	poly[0].y = pos.y + sin(rot) * radius;
	for (size_t i = 1; i < 5; i++)
	{
		poly[i] = PointRotate(pos.x, pos.y, 144, &poly[i - 1]);
	}

	Polygon(hdc, poly, 5);
}

