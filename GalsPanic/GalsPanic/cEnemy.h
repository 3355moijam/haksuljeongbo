#pragma once
#include "framework.h"
class cEnemySnakeBody;
class cArea;
class cPlayer;

class cEnemySnake
{
private:
	//POINT center;
	vector<cEnemySnakeBody*> body_parts;
	enum class state { idle, move, shoot };
	state current_state;


	void anim_idle();
	void anim_move(cArea &area);
	void anim_shoot(cPlayer &player);

	int idle_count;
	int move_count;
	int shoot_count;
	double direct;
	//POINT move_destination;
	
public:
	cEnemySnake();
	~cEnemySnake();
	void show(HDC hdc);
	void update(cPlayer &player, cArea &area);
};


class cEnemySnakeBody
{
protected:
	POINT center;
	int radius;
	double direct;
	vector<cEnemySnakeBody*> *vecBody;
	static int move_speed;
	POINT move_destination;
	int body_index;
public:
	cEnemySnakeBody(vector<cEnemySnakeBody*> *vec);
	int get_index();
	int get_radius() { return radius; }
	POINT get_center() { return center; }
	void set_direct();
	void set_direct(POINT& target) { direct = directFromTo(center, target); }
	void set_direct(double dir) { direct = dir; }
	virtual void move(cArea &area);
	virtual ~cEnemySnakeBody();
	virtual void show(HDC hdc);
	//virtual void update();
};

class cEnemySnakeHead : public cEnemySnakeBody
{
private:
	POINT poly[4];
public:
	cEnemySnakeHead(POINT cen, vector<cEnemySnakeBody*> *vec) : cEnemySnakeBody(vec) { radius = 20; center = cen; }
	~cEnemySnakeHead();
	void show(HDC hdc);
	void move(cArea& area);
	//void update();
};






class cBullet
{
protected:
	int lifetime;
	double direct;
	POINT center;
	int bullet_speed;
public:
	cBullet(double dir, const POINT &cen);
	virtual ~cBullet();
	int get_index();
	virtual void show(HDC hdc) = 0;
	virtual void move() = 0;
	virtual bool isCollide(cPlayer& player) = 0;
	void update();
};

class cSpeedBullet : public cBullet
{
private:
	static int delay;
	int bullet_length;
public:
	cSpeedBullet(double dir, const POINT &cen);
	void show(HDC hdc);
	void move();
	bool isCollide(cPlayer& player);
};