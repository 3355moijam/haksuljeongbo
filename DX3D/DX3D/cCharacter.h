#pragma once
#include "cBodyPart.h"


class cCharacter
{
public:
	cCharacter();
	~cCharacter();
	
private:
	cBodyPart		head;
	cBodyPart		body;
	cBodyPart		arm_left;
	cBodyPart		arm_right;
	cBodyPart		leg_left;
	cBodyPart		leg_right;

	D3DXVECTOR3		pos_;
	D3DXVECTOR3		rotate_;
	D3DXVECTOR3		direct_;
	D3DXVECTOR3		scale_;
	float			fMoveSpeed;
	float			fRotateSpeed;
	
public:
	void update();
	void render();
	void move(float dir);
	void rotation(float _y);
	void animMove();
	void animIdle();

	D3DXVECTOR3& get_pos() { return pos_; }
	__declspec(property(get = get_pos)) D3DXVECTOR3& pos;

	D3DXVECTOR3& get_rotate() { return rotate_; }
	__declspec(property(get = get_rotate)) D3DXVECTOR3& rotate;

	D3DXVECTOR3& get_scale() { return scale_; }
	__declspec(property(get = get_scale)) D3DXVECTOR3& scale;
};
