#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter(): head(), leg_left(), leg_right(), arm_left(), arm_right(), body(),
	pos_(0,2.44,0),
	rotate_(0,0,0),
	scale_(1,1,1),
	direct_(0,0,1),
	fMoveSpeed(0.2f),
	fRotateSpeed(5 * D3DX_PI / 180)
{
	head.setup		(D3DXVECTOR3(0.8, 0.8, 0.8), D3DXVECTOR3(0, 1.8, 0));
	body.setup		(D3DXVECTOR3(1, 1, 0.5), D3DXVECTOR3(0, 0, 0));
	arm_left.setup	(D3DXVECTOR3(0.4, 0.8, 0.4), D3DXVECTOR3(-1.4, 0.8, 0));
	arm_left.cube.pos.y += -1;
	arm_right.setup	(D3DXVECTOR3(0.4, 0.8, 0.4), D3DXVECTOR3(+1.4, 0.8, 0));
	arm_right.cube.pos.y += -1;
	leg_left.setup	(D3DXVECTOR3(0.4, 0.8, 0.4), D3DXVECTOR3(-0.4, -1, 0));
	leg_left.cube.pos.y += -1;
	leg_right.setup(D3DXVECTOR3(0.4, 0.8, 0.4), D3DXVECTOR3(+0.4, -1, 0));
	leg_right.cube.pos.y += -1;
}

cCharacter::~cCharacter()
{
}

void cCharacter::update()
{
	bool isKeyDown = false;
	if (GetKeyState('a') & 0x8000 || GetKeyState('A') & 0x8000)
	{
		rotate_.y -= fRotateSpeed;
		isKeyDown = true;
	}
	else if (GetKeyState('d') & 0x8000 || GetKeyState('D') & 0x8000)
	{
		rotate_.y += fRotateSpeed;
		isKeyDown = true;
	}

	if (GetKeyState('w') & 0x8000 || GetKeyState('W') & 0x8000)
	{
		move(1);
		isKeyDown = true;
	}
	else if (GetKeyState('s') & 0x8000 || GetKeyState('S') & 0x8000)
	{
		move(-1);
		isKeyDown = true;
	}

	if (isKeyDown)
		animMove();
	else
		animIdle();
}

void cCharacter::render()
{
	D3DXMATRIXA16 matWorld, matScale, matPos, matRotX, matRotY, matRotZ;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, scale_.x, scale_.y, scale_.z);
	D3DXMatrixRotationX(&matRotX, rotate_.x);
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXMatrixRotationZ(&matRotZ, rotate_.z);
	D3DXMatrixTranslation(&matPos, pos_.x, pos_.y, pos_.z);
	matWorld = matScale * matRotX * matRotY * matRotZ * matPos;

	head.render		(matWorld);
	body.render		(matWorld);
	arm_left.render	(matWorld);
	arm_right.render(matWorld);
	leg_left.render	(matWorld);
	leg_right.render(matWorld);
	

	//head.render		(matScale, matRotX, matRotY, matRotZ, matPos);
	//body.render		(matScale, matRotX, matRotY, matRotZ, matPos);
	//arm_left.render	(matScale, matRotX, matRotY, matRotZ, matPos);
	//arm_right.render(matScale, matRotX, matRotY, matRotZ, matPos);
	//leg_left.render	(matScale, matRotX, matRotY, matRotZ, matPos);
	//leg_right.render(matScale, matRotX, matRotY, matRotZ, matPos);
	
}

void cCharacter::move(float dir)
{
	if (dir == 0)
		return;
	D3DXMATRIXA16 matRotY;
	D3DXMatrixRotationY(&matRotY, rotate_.y);
	D3DXVECTOR3 temp_go;// = cVector3::transformCoord(direct_, cMatrix::rotationY(rotate_.Y)).normalize();
	D3DXVec3TransformNormal(&temp_go, &direct_, &matRotY);
	temp_go *= dir * fMoveSpeed;
	pos_ += temp_go;
}

void cCharacter::rotation(float _y)
{
	D3DXMATRIXA16 matRotY;
	D3DXMatrixRotationY(&matRotY, _y);
	
	D3DXVec3TransformCoord(&head.pos, &head.pos, &matRotY);
	D3DXVec3TransformCoord(&body.pos, &body.pos, &matRotY);
	D3DXVec3TransformCoord(&leg_left.pos, &leg_left.pos, &matRotY);
	D3DXVec3TransformCoord(&leg_right.pos, &leg_right.pos, &matRotY);
	D3DXVec3TransformCoord(&arm_left.pos, &arm_left.pos, &matRotY);
	D3DXVec3TransformCoord(&arm_right.pos, &arm_right.pos, &matRotY);
}

void cCharacter::animMove()
{
	static float fClamp = D3DX_PI / 6.0f;
	static float fMove = 5.0f * D3DX_PI / 180;
	static bool bFoot = false;
	if(bFoot)
	{
		arm_left.rotate.x += fMove;
		leg_right.rotate.x += fMove;

		arm_right.rotate.x += -fMove;
		leg_left.rotate.x += -fMove;
		
		if (arm_left.rotate.x > fClamp)
			bFoot = !bFoot;
	}
	else
	{
		arm_left.rotate.x += -fMove;
		leg_right.rotate.x += -fMove;

		arm_right.rotate.x += fMove;
		leg_left.rotate.x += fMove;

		if (arm_right.rotate.x > fClamp)
			bFoot = !bFoot;
	}
}

void cCharacter::animIdle()
{
	if (abs(arm_left.rotate.x) < ELIPSE)
		return;
	static float fMove = 5.0f * D3DX_PI / 180;
	if(arm_left.rotate.x < 0)
	{
		arm_left.rotate.x += fMove;
		leg_right.rotate.x += fMove;

		arm_right.rotate.x += -fMove;
		leg_left.rotate.x += -fMove;

		if (abs(arm_left.rotate.x) < ELIPSE)
		{
			arm_left.rotate.x = 0;
			leg_right.rotate.x = 0;
							  
			arm_right.rotate.x = 0;
			leg_left.rotate.x = 0;
		}
	}
	else
	{
		arm_left.rotate.x += -fMove;
		leg_right.rotate.x += -fMove;

		arm_right.rotate.x += fMove;
		leg_left.rotate.x += fMove;

		if (abs(arm_left.rotate.x) < ELIPSE)
		{
			arm_left.rotate.x = 0;
			leg_right.rotate.x = 0;

			arm_right.rotate.x = 0;
			leg_left.rotate.x = 0;
		}
	}
}

