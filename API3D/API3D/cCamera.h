#pragma once
#include "stdafx.h"

#include "cVector3.h"

//class cVector3;
class cMatrix;

class cCamera
{
private:
	cVector3 vEye_;
	cVector3 vLookAt_;
	cVector3 vUp_;
	float fFovY_;
	float fAspect_;
	float fNearZ_;
	float fFarZ_;

	float fZoomScale;
	float fMoveSpeed;
	float fDistance;

public:
	cVector3 get_vEye() const {	return vEye_;	}
	void set_vEye(const cVector3& position)	{	this->vEye_ = position;	}
	__declspec(property(get = get_vEye, put = set_vEye)) cVector3 vEye;

	cVector3 get_vLookAt() const {	return vLookAt_;	}
	void set_vLookAt(const cVector3& target)	{	this->vLookAt_ = target;	}
	__declspec(property(get = get_vLookAt, put = set_vLookAt)) cVector3 vLookAt;

	cVector3 get_vUp() const	{	return vUp_;	}
	void set_vUp(const cVector3& v_up)	{	vUp_ = v_up;	}
	__declspec(property(get = get_vUp, put = set_vUp)) cVector3 vUp;

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

	cCamera();

	void update();
	void zoom(float inout);
	void move(float _x, float _y);
	
};
