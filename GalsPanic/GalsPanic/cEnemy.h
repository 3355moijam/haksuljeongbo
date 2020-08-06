#pragma once
class cEnemyBody;

class cEnemy
{
private:
	double direct;
	//POINT center;
	vector<cEnemyBody*> body;
	enum class state { idle, move, shoot };
	state current_state;

	void anim_idle();
	void anim_move();
	void anim_shoot();

public:
	cEnemy();
	~cEnemy();
	void show(HDC hdc);
	void update();
};


class cEnemyBody
{
protected:
	POINT center;
	int radius;
	double direct;
	vector<cEnemyBody*> *vecBody;
public:
	cEnemyBody(POINT cen, vector<cEnemyBody*> *vec);
	int get_index();
	int get_radius() { return radius; }
	POINT get_center() { return center; }
	void set_direct(const POINT &target) { direct = directFromTo(center, target); }
	virtual ~cEnemyBody();
	virtual void show(HDC hdc);
	//virtual void update();
};

class cEnemyHead : public cEnemyBody
{
private:
	POINT poly[3];
public:
	cEnemyHead(POINT cen, vector<cEnemyBody*> *vec) :cEnemyBody(cen, vec) {};
	~cEnemyHead();
	void show(HDC hdc);
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
