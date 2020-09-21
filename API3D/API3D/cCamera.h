#pragma once
#include "stdafx.h"

#include "cVector3.h"

//class cVector3;
class cMatrix;

class cCamera
{
private:
	cVector3 position_;
	cVector3 target_;
	float fFovY_;
	float fAspect_;
	float fNearZ_;
	float fFarZ_;

public:
	cVector3 get_position() const {	return position_;	}
	void set_position(const cVector3& position)	{	this->position_ = position;	}
	__declspec(property(get = get_position, put = set_position)) cVector3 position;

	cVector3 get_target() const {	return target_;	}
	void set_target(const cVector3& target)	{	this->target_ = target;	}
		__declspec(property(get = get_target, put = set_target)) cVector3 target;

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
};
