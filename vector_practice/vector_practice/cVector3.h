#pragma once
#include <iostream>

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
	
	bool operator==(cVector3& vector3);
	bool operator!=(cVector3& vector3);
	cVector3 operator+(cVector3& vector3);
	cVector3 operator+(float f_x);
	cVector3& operator+=(float f_x);
	cVector3 operator-(float f_x);
	cVector3& operator-=(float f_x);
	cVector3 operator-(cVector3& vector3);
	cVector3 operator*(float f_x);
	friend cVector3 operator*(float f_x, cVector3& vector3);
	cVector3 operator/(float f_x);

	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);
	// mode 0(default): 라디안, 1: 도
	static float Angle(cVector3& v1, cVector3& v2, bool mode = 0);
	float Length();
	cVector3 Normalize();

	friend std::ostream& operator<<(std::ostream& os, cVector3& vector3);
	friend std::istream& operator>>(std::istream& is, cVector3& vector3);
};
