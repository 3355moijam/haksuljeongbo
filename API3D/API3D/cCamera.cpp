#include "stdafx.h"
#include "cCamera.h"
extern RECT g_view;
cCamera::cCamera()
	: position_( 10, 10, -10, 1),
	target_(0,0,0,1),
	fFovY_(M_PI_2),
	fAspect_((float)g_view.right / g_view.bottom),
	fNearZ_(10),
	fFarZ_(1000)
{
}
