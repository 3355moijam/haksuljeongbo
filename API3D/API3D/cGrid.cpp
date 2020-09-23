#include "stdafx.h"
#include "cGrid.h"
#include "cVector3.h"
#include "cMatrix.h"

cGrid::cGrid() :
	top(), bottom(), left(), right(), interval(5)
{
	for (int i = 0; i < 11; ++i)
	{
		top.emplace_back(interval * -5 + i * interval, 0, interval * -5);
		bottom.emplace_back(interval * -5 + i * interval, 0, interval * 5);
		left.emplace_back(interval * -5, 0, interval * -5 + i * interval);
		right.emplace_back(interval * 5, 0, interval * -5 + i * interval);
	}
}

void cGrid::render(HDC hdc, cMatrix& matWVP, cMatrix& matViewport)
{
	for (int i = 0; i < top.size(); i++)
	{
		cVector3 v1 = top[i];
		cVector3 v2 = bottom[i];
		cVector3 v3 = left[i];
		cVector3 v4 = right[i];

		v1 = cVector3::transformCoord(v1, matWVP);
		v2 = cVector3::transformCoord(v2, matWVP);
		v3 = cVector3::transformCoord(v3, matWVP);
		v4 = cVector3::transformCoord(v4, matWVP);

		v1 = cVector3::transformCoord(v1, matViewport);
		v2 = cVector3::transformCoord(v2, matViewport);
		v3 = cVector3::transformCoord(v3, matViewport);
		v4 = cVector3::transformCoord(v4, matViewport);

		MoveToEx(hdc, v1.X, v1.Y, NULL);
		LineTo(hdc, v2.X, v2.Y);
		MoveToEx(hdc, v3.X, v3.Y, NULL);
		LineTo(hdc, v4.X, v4.Y);

	}
}
