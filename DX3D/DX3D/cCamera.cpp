#include "stdafx.h"
#include "cCamera.h"
#include "cCube.h"
extern HWND g_hWnd;
cCamera::cCamera()
	: vEye_(0, 5, -25),
	vLookAt_(0, 0, 0),
	vUp_(0, 1, 0),
	fFovY_(D3DX_PI / 4.0f),
	fAspect_(),
	fNearZ_(1),
	fFarZ_(1000),
	fZoomScale(3.0f),
	fMoveSpeed(0.1f),
	fDistance(D3DXVec3Length(&(vLookAt - vEye))),
	vRotateAngle(vLookAt - vEye)
{
	//fDistance = D3DXVec3Length(&(vLookAt - vEye));
	D3DXVec3Normalize(&vRotateAngle, &vRotateAngle);
}

void cCamera::update(cCube& target)
{
	//RECT rc;
	//GetClientRect(g_hWnd, &rc);

	//fAspect_ = (float)rc.right / rc.bottom;

	vLookAt = target.pos;
	vEye = vLookAt + -vRotateAngle * fDistance;
}

void cCamera::zoom(float inout)
{
	float weight = inout / 120.0f;
	D3DXVECTOR3 temp;
	D3DXVec3Normalize(&temp, &(vLookAt - vEye));
	vEye += temp * weight * fZoomScale;
	fDistance = D3DXVec3Length(&(vLookAt - vEye));
	//// lookat은 타겟 포지션
	//// eye는 default 위치 + 타겟포지션
}

void cCamera::move(float _x, float _y)
{
	D3DXVECTOR3 look;
	D3DXVec3Normalize(&look, &(vLookAt_ - vEye_));
	D3DXVECTOR3 right;
	D3DXVec3Cross(&right, &vUp_, &look);
	D3DXVec3Normalize(&right, &right);
	D3DXVECTOR3 up;
	D3DXVec3Cross(&up, &look, &right);
	D3DXVec3Normalize(&up, &up);

	vEye_ += right * _x * fMoveSpeed;
	vEye_ += up * _y * fMoveSpeed;

	D3DXVec3Normalize(&vRotateAngle, &(vLookAt - vEye));
}
