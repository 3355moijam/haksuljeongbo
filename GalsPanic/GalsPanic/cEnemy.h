#pragma once
class cEnemySnakeBody;

class cEnemySnake
{
private:
	//POINT center;
	vector<cEnemySnakeBody*> body_parts;
	enum class state { idle, move, shoot };
	state current_state;


	void anim_idle();
	void anim_move();
	void anim_shoot();

	int idle_count;
	int move_count;
	double direct;
	//POINT move_destination;
	
public:
	cEnemySnake();
	~cEnemySnake();
	void show(HDC hdc);
	void update();
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
	void set_direct(double dir) { direct = dir; }
	virtual void move();
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
	void move();
	//void update();
};






class cBullet
{
private:
	int lifetime;
	double direct;
	POINT center;
public:
	cBullet(double dir, const POINT &cen);
	virtual ~cBullet();
	int get_index();
	virtual void show(HDC hdc) = 0;
	virtual void move() = 0;
	void update();
};
