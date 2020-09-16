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
	bool operator==(cVector3& vector3);
	bool operator!=(cVector3& vector3);
	cVector3 operator+(cVector3& vector3);
	cVector3 operator+(float f_x);
	cVector3& operator+=(float f_x);
	cVector3 operator-(float f_x);
	cVector3& operator-=(float f_x);
	cVector3 operator-(cVector3& vector3);
	cVector3 operator*(float f_x);
	cVector3 operator/(float f_x);

	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);
	float Length();
	cVector3 Normalize();

	friend std::ostream& operator<<(std::ostream& os, cVector3& vector3);
};
