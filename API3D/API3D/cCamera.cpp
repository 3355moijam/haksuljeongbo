#include "stdafx.h"
#include "cCamera.h"
extern HWND g_hWnd;
cCamera::cCamera()
	: vEye_(0, 5, 5),
	vLookAt_(0, 0, 0),
	vUp_(0, 1, 0),
	fFovY_(M_PI_4),
	fAspect_(),
	fNearZ_(1),
	fFarZ_(1000),
	fZoomScale(1.0f),
	fMoveSpeed(0.5f)
{
}

void cCamera::update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	fAspect_ = (float)rc.right / rc.bottom;

	
}

void cCamera::zoom(float inout)
{
	float weight = inout / 120.0f;
	cVector3 temp = (vLookAt - vEye).normalize();
	vEye = vEye + temp * weight * fZoomScale;
	
}

void cCamera::move(float _x, float _y)
{
	cVector3 look = (vLookAt_ - vEye_);
	float before_dist = look.length();
	look = look.normalize();
	cVector3 right = cVector3::cross(vUp_, look).normalize();
	cVector3 up = cVector3::cross(look, right).normalize();

	vEye_ = vEye_ + right * _x * fMoveSpeed;
	vEye_ = vEye_ + up * _y * fMoveSpeed;
	//float eye_dist = vEye_.length();
	vEye_ = vLookAt_ + (vEye_ - vLookAt_).normalize() * before_dist;
}
