#pragma once
#include "stdafx.h"

class cMatrix;
class cVector3
{
public:
	cVector3();
	cVector3(float _x, float _y, float _z);
	~cVector3();

private:
	float x, y, z;

public:
	float get_x() const	{	return x;	}
	void set_x(float x)	{	this->x = x;	}
	__declspec(property(get = get_x, put = set_x)) float X;

	float get_y() const	{	return y;	}
	void set_y(float y)	{	this->y = y;	}
	__declspec(property(get = get_y, put = set_y)) float Y;

	float get_z() const	{	return z;	}
	void set_z(float z)	{	this->z = z;	}
		__declspec(property(get = get_z, put = set_z)) float Z;

	//float get_w() const	{	return w;	}
	//void set_w(float w)	{	this->w = w;	}
	//__declspec(property(get = get_w, put = set_w)) float W;
	
	bool operator==(cVector3& vector3);
	bool operator!=(cVector3& vector3);
	cVector3 operator+(cVector3& vector3);
	cVector3 operator+(float f_x);
	cVector3& operator+=(cVector3& vector3);
	cVector3& operator+=(float f_x);
	cVector3 operator-(float f_x);
	cVector3& operator-=(float f_x);
	cVector3 operator-(cVector3& vector3);
	cVector3 operator*(float f_x);
	cVector3& operator*=(float f_x);
	friend cVector3 operator*(float f_x, cVector3& vector3);
	cVector3 operator/(float f_x);

	static float dot(cVector3& v1, cVector3& v2);
	static cVector3 cross(cVector3& v1, cVector3& v2);
	// mode 0(default): 라디안, 1: 도
	static float angle(cVector3& v1, cVector3& v2, bool mode = 0);
	float length();
	cVector3 normalize();

	friend std::ostream& operator<<(std::ostream& os, cVector3& vector3);
	friend std::istream& operator>>(std::istream& is, cVector3& vector3);

	//========================================
	static cVector3 transformCoord(cVector3& vector3, cMatrix& matrix); // : 이동;
	static cVector3 transformNormal(cVector3& vector3, cMatrix& matrix); // : 벡터이동
};
