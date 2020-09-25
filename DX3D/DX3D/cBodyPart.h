#pragma once
#include "cCube.h"

class cBodyPart
{
public:
	cBodyPart();
	~cBodyPart();

private:
	cCube	cube_;
	D3DXVECTOR3 pos_;
	D3DXVECTOR3 rotate_;
	D3DXVECTOR3 direct_;
	D3DXVECTOR3 scale_;

public:
	D3DXVECTOR3& get_pos() { return pos_; }
	__declspec(property(get = get_pos)) D3DXVECTOR3& pos;

	D3DXVECTOR3& get_rotate() { return rotate_; }
	__declspec(property(get = get_rotate)) D3DXVECTOR3& rotate;

	D3DXVECTOR3& get_scale() { return scale_; }
	__declspec(property(get = get_scale)) D3DXVECTOR3& scale;

	cCube& get_cube() { return cube_; }
	__declspec(property(get = get_cube)) cCube& cube;
	
	void setup(D3DXVECTOR3& scale, D3DXVECTOR3& pos);
	void render(D3DXMATRIXA16& matUpperWorld);
	void render(D3DXMATRIXA16& matS, D3DXMATRIXA16& matX, D3DXMATRIXA16& matY, D3DXMATRIXA16& matZ, D3DXMATRIXA16& matT);
	
};
