#include "stdafx.h"
#include "cSquare.h"
#include <string>



cSquare::cSquare()
	:vertex(),
	speed(0.5f), direct_(0, 0, -1),
	scale_(1, 1, 1)
{
	//vertex.emplace_back(-1, 1, -1, 1);
	//vertex.emplace_back(-1, -1, -1, 1);
	//vertex.emplace_back(1, 1, -1, 1);
	//vertex.emplace_back(1, -1, -1, 1);
	//vertex.emplace_back(1, 1, 1, 1);
	//vertex.emplace_back(1, -1, 1, 1);
	//vertex.emplace_back(-1, 1, 1, 1);
	//vertex.emplace_back(-1, -1, 1, 1);
	vertex.emplace_back(-1, -1, -1);
	vertex.emplace_back(-1, 1, -1);
	vertex.emplace_back(1, 1, -1);
	vertex.emplace_back(1, -1, -1);

	vertex.emplace_back(-1, -1, 1);
	vertex.emplace_back(-1, 1, 1);
	vertex.emplace_back(1, 1, 1);
	vertex.emplace_back(1, -1, 1);
	// 폴리곤 만들기
	{
		//front
		verIndex.push_back(0);
		verIndex.push_back(1);
		verIndex.push_back(2);

		verIndex.push_back(0);
		verIndex.push_back(2);
		verIndex.push_back(3);
		//back
		verIndex.push_back(4);
		verIndex.push_back(6);
		verIndex.push_back(5);

		verIndex.push_back(4);
		verIndex.push_back(7);
		verIndex.push_back(6);

		//left
		verIndex.push_back(4);
		verIndex.push_back(5);
		verIndex.push_back(1);

		verIndex.push_back(4);
		verIndex.push_back(1);
		verIndex.push_back(0);

		//right
		verIndex.push_back(3);
		verIndex.push_back(2);
		verIndex.push_back(6);

		verIndex.push_back(3);
		verIndex.push_back(6);
		verIndex.push_back(7);

		//up
		verIndex.push_back(1);
		verIndex.push_back(5);
		verIndex.push_back(6);

		verIndex.push_back(1);
		verIndex.push_back(6);
		verIndex.push_back(2);

		//down
		verIndex.push_back(4);
		verIndex.push_back(0);
		verIndex.push_back(3);

		verIndex.push_back(4);
		verIndex.push_back(3);
		verIndex.push_back(7);
	}

}



extern RECT g_view;
void DrawCircle(HDC hdc, int x, int y, int r = 5)
{
	Ellipse(hdc, x - r, y - r, x + r, y + r);
}
void cSquare::render(HDC hdc, cMatrix& matWVP, cMatrix& matViewport, cVector3& cameraDirect)
{
	for (int i = 0; i < verIndex.size(); i += 3)
	{
		cVector3 v1 = vertex[verIndex[i + 0]];
		cVector3 v2 = vertex[verIndex[i + 1]];
		cVector3 v3 = vertex[verIndex[i + 2]];

		v1 = cVector3::transformCoord(v1, matWVP);
		v2 = cVector3::transformCoord(v2, matWVP);
		v3 = cVector3::transformCoord(v3, matWVP);

		
		{
			// 법선벡터 구하기
			cVector3 temp = cVector3::cross(v2 - v1, v3 - v1);
			if ((cameraDirect.Z >= 0 && cVector3::dot(temp, cameraDirect) > 0) ||
				(cameraDirect.Z <  0 && cVector3::dot(temp, cameraDirect) < 0))
				continue;
		}
		
		v1 = cVector3::transformCoord(v1, matViewport);
		v2 = cVector3::transformCoord(v2, matViewport);
		v3 = cVector3::transformCoord(v3, matViewport);


		MoveToEx(hdc, v1.X, v1.Y, NULL);
		LineTo(hdc, v2.X, v2.Y);
		LineTo(hdc, v3.X, v3.Y);
		LineTo(hdc, v1.X, v1.Y);

		//std::wstring ws1 = std::to_wstring(verIndex[i + 0]);
		//std::wstring ws2 = std::to_wstring(verIndex[i + 1]);
		//std::wstring ws3 = std::to_wstring(verIndex[i + 2]);
		//TextOut(hdc, v1.X, v1.Y, ws1.c_str(), 1);
		//TextOut(hdc, v2.X, v2.Y, ws2.c_str(), 1);
		//TextOut(hdc, v3.X, v3.Y, ws3.c_str(), 1);
	}
}

cVector3 cSquare::move(float dir)
{
	cVector3 temp_go = cVector3::transformCoord(direct_, cMatrix::rotationY(rotate_.Y)).normalize();
	temp_go *= dir * speed;
	pos_ += temp_go;
	return temp_go;
}

void cSquare::scaleControl(float s)
{
	scale_ += s;
}

cMatrix cSquare::get_world_matrix()
{
	cMatrix matWorld = cMatrix::scale(scale_);
	matWorld = matWorld
			* cMatrix::rotationX(rotate_.X)
			* cMatrix::rotationY(rotate_.Y)
			* cMatrix::rotationZ(rotate_.Z)
			* cMatrix::translation(pos_);
	return matWorld;
}

