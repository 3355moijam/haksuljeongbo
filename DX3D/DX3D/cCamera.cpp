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
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	fAspect_ = (float)rc.right / rc.bottom;

	vLookAt = target.pos;
	vEye = vLookAt + -vRotateAngle * fDistance;


	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);

	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, fFovY, fAspect, fNearZ, fFarZ);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

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

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static float x = 0, y = 0;
	switch (message)
	{
	case WM_RBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_RBUTTONUP:
		x = 0; y = 0;
		break;
	case WM_MOUSEMOVE:
		switch (wParam)
		{
		case MK_RBUTTON:
			//camera.move(x - LOWORD(lParam), HIWORD(lParam) - y);
			move(LOWORD(lParam) - x, HIWORD(lParam) - y);
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			break;
		}
		break;
	case WM_MOUSEWHEEL:
		GET_WHEEL_DELTA_WPARAM(wParam);
		zoom(GET_WHEEL_DELTA_WPARAM(wParam));
		break;
	default:
		break;
	}
}
