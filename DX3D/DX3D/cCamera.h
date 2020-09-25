#pragma once
#include "stdafx.h"
class cCube;
class cCamera
{
private:
	D3DXVECTOR3 vEye_;
	D3DXVECTOR3 vLookAt_;
	D3DXVECTOR3 vUp_;
	float fFovY_;
	float fAspect_;
	float fNearZ_;
	float fFarZ_;

	float fZoomScale;
	float fMoveSpeed;

	float fDistance;
	D3DXVECTOR3 vRotateAngle;

public:
	cCamera();

	D3DXVECTOR3 get_vEye() const {	return vEye_;	}
	void set_vEye(const D3DXVECTOR3& position)	{	this->vEye_ = position;	}
	__declspec(property(get = get_vEye, put = set_vEye)) D3DXVECTOR3 vEye;

	D3DXVECTOR3 get_vLookAt() const {	return vLookAt_;	}
	void set_vLookAt(const D3DXVECTOR3& target)	{	this->vLookAt_ = target;	}
	__declspec(property(get = get_vLookAt, put = set_vLookAt)) D3DXVECTOR3 vLookAt;

	D3DXVECTOR3 get_vUp() const	{	return vUp_;	}
	void set_vUp(const D3DXVECTOR3& v_up)	{	vUp_ = v_up;	}
	__declspec(property(get = get_vUp, put = set_vUp)) D3DXVECTOR3 vUp;

	float get_f_fov_y() const {	return fFovY_;	}
	void set_f_fov_y(float f_fov_y)	{	fFovY_ = f_fov_y;	}
	__declspec(property(get = get_f_fov_y, put = set_f_fov_y)) float fFovY;

	float get_f_aspect() const	{	return fAspect_;	}
	void set_f_aspect(float f_aspect)	{	fAspect_ = f_aspect;	}
	__declspec(property(get = get_f_aspect, put = set_f_aspect)) float fAspect;

	float get_f_near_z() const	{	return fNearZ_;	}
	void set_f_near_z(float f_near_z)	{	fNearZ_ = f_near_z;	}
	__declspec(property(get = get_f_near_z, put = set_f_near_z)) float fNearZ;

	float get_f_far_z() const	{	return fFarZ_;	}
	void set_f_far_z(float f_far_z)	{	fFarZ_ = f_far_z;	}
	__declspec(property(get = get_f_far_z, put = set_f_far_z)) float fFarZ;


	void update(cCube& target);
	void zoom(float inout);
	void move(float _x, float _y);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};
