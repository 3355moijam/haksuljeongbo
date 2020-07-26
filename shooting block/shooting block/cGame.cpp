#include "stdafx.h"
#include "cGame.h"

extern RECT view;
vector<vector<cGame*>> objectList(4);
extern cUI ui;
cGame::cGame(int x, int y, double dir) : direct(dir)
{
	center.x = x;
	center.y = y;
}


cGame::~cGame()
{
}

void cGame::set_direct(int x, int y)
{
	direct = atan2(y - center.y, x - center.x);
}

void cGame::init()
{
	new cChar;
	cBullet::init_max();
	int _x = 75;
	int _y = 90;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			new cBlock(_x + j * 50, _y - i * 20);
		}
	}
}

void cGame::draw(HDC hdc)
{
	for (int i = 0; i < objectList.size(); i++)
	{
		for (int j = 0; j < objectList[i].size(); j++)
		{
			objectList[i][j]->show(hdc);
		}
	}
}



void cGame::update()
{
	if (start)
	{
		static int count = 0;
		count++;
		int listLength = objectList[nBullet].size();
		for (int j = 0; j < listLength; j++)
		{
			dynamic_cast<cBullet*>(objectList[nBullet][j])->collide();
		}
		
		for (int i = 0; i < objectList.size(); i++)
		{
			for (int j = 0; j < objectList[i].size(); j++)
			{
				if (objectList[i][j]->move())
					j--;
			}
		}
		if (count * cBlock::get_speed() >= 20)
		{
			count = 0;
			cBlock::line_create();
		}
	}
}

void cGame::delete_all()
{
	for (int i = 0; i < objectList.size(); i++)
	{
		int listLength = objectList[i].size();
		for (int j = 0; j < listLength; j++)
		{
			delete objectList[i][0];
		}
	}
}


cChar::cChar() : cGame(view.right / 2, view.bottom, -M_PI_2), radius(50)
{
	objectList[0].push_back(this);
	poly[0] = { center.x, center.y - 5 };
	poly[1] = { center.x + radius + 20, center.y - 5};
	poly[2] = { center.x + radius + 20, center.y + 5 };
	poly[3] = { center.x, center.y + 5 };
}

cChar::~cChar()
{
	int temp = find_self();
	objectList[nCharacter].erase(objectList[nCharacter].begin() + temp);
}

int cChar::find_self()
{
	for (size_t i = 0; i < objectList[nCharacter].size(); i++)
	{
		if (objectList[nCharacter][i] == this)
			return i;
	}
	return -1;
}

void cChar::show(HDC hdc)
{
	for (size_t i = 0; i < 4; i++)
	{
		temp[i] = PointRotate(center.x, center.y, direct, &poly[i]);
	}
	Polygon(hdc, temp, 4);
	DrawCircle(hdc, center.x, center.y, radius);
}

void cChar::shoot()
{
	if(!cBullet::is_max())
		cBullet* newBullet = new cBullet((temp[2].x + temp[1].x) / 2, (temp[2].y + temp[1].y) / 2, direct);
}

int cBullet::count = 0;
int cBullet::max = 3;
cBullet::cBullet(int x, int y, double dir) : cGame(x, y, dir), move_speed(15), radius(7)
{
	objectList[nBullet].push_back(this);
	count++;

}

cBullet::~cBullet()
{
	int temp = find_self();
	objectList[nBullet].erase(objectList[nBullet].begin() + temp);
	count--;
}

int cBullet::find_self()
{
	for (size_t i = 0; i < objectList[nBullet].size(); i++)
	{
		if (objectList[nBullet][i] == this)
			return i;
	}
	return -1;
}

void cBullet::show(HDC hdc)
{
	DrawCircle(hdc, center.x, center.y, radius);
}

bool cBullet::move()
{
	center.x += cos(direct) * move_speed;
	center.y += sin(direct) * move_speed;


	if (center.x + radius > view.right)
		center.x = view.right - radius;
	else if (center.x - radius < view.left)
		center.x = view.left + radius;

	//if (center.y + radius > view.bottom)
	//	center.y = view.bottom - radius;
	if (center.y - radius < view.top)
		center.y = view.top + radius;

	if (center.y - radius >= view.bottom)
	{
		delete this;
		return true;
	}
	else
		return false;
}

bool cBullet::collide()
{
	if (objectList[nBlock].size() > 0)
	{
		cBlock* target; 
		bool isCollide = false;
		int col_dir; int max_distance;


		for (int i = 0; i < objectList[nBlock].size(); i++)
		{
			target = dynamic_cast<cBlock*> (objectList[nBlock][i]);
			if (col_dir = target->collide(this))
			{
				isCollide = true;
				score++;
				max_up();
				new cEStar(center.x, center.y, -direct);
				break;
			}
		}

		if (isCollide)
		{
			// 사각형의 collision 크기 구하기
			switch (col_dir)
			{
			case 1:
			case 2:
				direct *= -1;
				break;
			case 3:
			case 4:
				direct = M_PI - direct;
				break;
			default:
				break;
			}
			new cERect(target->get_center()->x, target->get_center()->y);
			delete target;
		}

	}


	if (center.y - radius <= view.top)// || center.y + radius >= view.bottom)
	{
		if ((int)sin(direct) * move_speed == 0)
			direct += M_PI_4 / 8;
		direct *= -1;
	}

	if (center.x - radius <= view.left || center.x + radius >= view.right)
		direct = M_PI - direct;
	return false;
}

int cBullet::max_up()
{
	for (int i = 0; i < 2500; i += 50)
	{
		if (score == 20 || score == i)// || score == 100 || score == 150 || score == 200 || score == 300)
		{
			max++;
			break;
		}
		else if (score == 500 || score == 1000 || score == 1500 || score == 2000)
		{
			max++;
			cBlock::speed_up();
			break;
		}

	}

	return max;
}

double cBlock::move_speed = 1;
cBlock::cBlock(int x, int y) : cGame(x, y, M_PI_2)
{
	objectList[nBlock].push_back(this);

	SetRect(&rect, x - 25, y - 10, x + 25, y + 10);
	SetRect(&collision, x - 35, y - 20, x + 35, y + 20);
}

cBlock::~cBlock()
{
	int temp = find_self();
	objectList[nBlock].erase(objectList[nBlock].begin() + temp);
}

int cBlock::find_self()
{
	for (size_t i = 0; i < objectList[nBlock].size(); i++)
	{
		if (objectList[nBlock][i] == this)
			return i;
	}
	return -1;
}

void cBlock::show(HDC hdc)
{
	DrawRectangle(hdc, &rect);
}

bool cBlock::move()
{
	rect.top += move_speed;
	rect.bottom += move_speed;
	collision.top += move_speed;
	collision.bottom += move_speed;
	center.y += move_speed;

	if (rect.top >= view.bottom)
	{
		ui.set_mode(gameover);
		//delete this;
		return true;
	}
	else
		return false;
}
// 0:충돌x, 1:상, 2:하, 3:좌, 4:우
int cBlock::collide(cBullet* target)
{
	POINT* tCenter = target->get_center();
	if (!PtInRect(&collision, *tCenter))
		return 0;

	if (tCenter->x >= rect.left && tCenter->x <= rect.right)
	{
		if (tCenter->y <= rect.top)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		if (tCenter->x <= rect.left)
		{
			return 3;
		}
		else
		{
			return 4;
		}
	}
	
}

void cBlock::line_create()
{
	int _x = 75;
	int _y = -10;

	for (int i = 0; i < 6; i++)
	{
		new cBlock(_x + i * 50, _y);
	}
}

cEffect::cEffect(const int x, const int y, double dir) : cGame(x, y, dir), rotate_speed(M_PI_2 / 3), c_down(10)
{
	objectList[nEffect].push_back(this);
}

cEffect::~cEffect()
{
	int temp = find_self();
	objectList[nEffect].erase(objectList[nEffect].begin() + temp);
}

int cEffect::find_self()
{
	for (size_t i = 0; i < objectList[nEffect].size(); i++)
	{
		if (objectList[nEffect][i] == this)
			return i;
	}
	return -1;
}

void cERect::rotate()
{
	for (int i = 0; i < 4; i++)
	{
		poly[i].x = cos(rotate_speed) * (poly[i].x - center.x) - sin(rotate_speed) * (poly[i].y - center.y) + center.x;
		poly[i].y = sin(rotate_speed) * (poly[i].x - center.x) + cos(rotate_speed) * (poly[i].y - center.y) + center.y;
	}
}

cERect::cERect(const int x, const int y) : cEffect(x, y)
{
	c_down = 15;
	poly[0] = { x - 25, y - 10 };
	poly[1] = { x + 25, y - 10 };
	poly[2] = { x + 25, y + 10 };
	poly[3] = { x - 25, y + 10 };
}

void cERect::show(HDC hdc)
{
	Polygon(hdc, poly, 4);
}

void cEStar::rotate()
{
	for (int i = 0; i < 5; i++)
	{
		poly[i].x = cos(rotate_speed) * (poly[i].x - center.x) - sin(rotate_speed) * (poly[i].y - center.y) + center.x;
		poly[i].y = sin(rotate_speed) * (poly[i].x - center.x) + cos(rotate_speed) *(poly[i].y - center.y) + center.y;
	}
}

cEStar::cEStar(const int x, const int y, double dir) : cEffect(x, y, dir)
{
	poly[0] = { x, y - 10 };
	for (int i = 1; i < 5; i++)
	{
		poly[i] = PointRotate(x, y, 144, &poly[i - 1]);
	}
}

void cEStar::show(HDC hdc)
{
	Polygon(hdc, poly, 5);
}
