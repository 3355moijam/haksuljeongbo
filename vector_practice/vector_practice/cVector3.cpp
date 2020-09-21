#define _USE_MATH_DEFINES
#include "cVector3.h"
#include <cmath>

cVector3::cVector3() : x(0.0f), y(0.0f), z(0.0f)
{
}
cVector3::cVector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

cVector3::~cVector3()
{
}


bool cVector3::operator==(cVector3& vector3)
{
	return	(abs(x - vector3.x) <= FLT_EPSILON) && 
			(abs(y - vector3.y) <= FLT_EPSILON) && 
			(abs(z - vector3.z) <= FLT_EPSILON);
	//return (x == vector3.x) && (y == vector3.y) && (z == vector3.z);
}

bool cVector3::operator!=(cVector3& vector3)
{
	return	(abs(x - vector3.x) > FLT_EPSILON) || 
			(abs(y - vector3.y) > FLT_EPSILON) || 
			(abs(z - vector3.z) > FLT_EPSILON);
}

cVector3 cVector3::operator+(cVector3& vector3)
{
	cVector3 temp = {  };
	temp.x = x + vector3.x;
	temp.y = y + vector3.y;
	temp.z = z + vector3.z;
	return temp;
}

cVector3 cVector3::operator+(float f_x)
{
	cVector3 temp = {};
	temp.x = x + f_x;
	temp.y = y + f_x;
	temp.z = z + f_x;
	return temp;
}

cVector3& cVector3::operator+=(float f_x)
{
	*this = *this + f_x;
	return *this;
}

cVector3 cVector3::operator-(float f_x)
{
	cVector3 temp = {};
	temp.x = x - f_x;
	temp.y = y - f_x;
	temp.z = z - f_x;
	return temp;
}

cVector3& cVector3::operator-=(float f_x)
{
	*this = *this - f_x;
	return *this;
}

cVector3 cVector3::operator-(cVector3& vector3)
{
	cVector3 temp = {};
	temp.x = x - vector3.x;
	temp.y = y - vector3.y;
	temp.z = z - vector3.z;
	return temp;
}

cVector3 cVector3::operator*(float f_x)
{
	cVector3 temp = {};
	temp.x = x * f_x;
	temp.y = y * f_x;
	temp.z = z * f_x;
	return temp;
}

cVector3 operator*(float f_x, cVector3& vector3)
{
	cVector3 temp = vector3 * f_x;
	return temp;
}

cVector3 cVector3::operator/(float f_x)
{
	cVector3 temp = {};
	float f_x_ = 1 / f_x;
	temp.x = x * f_x_;
	temp.y = y * f_x_;
	temp.z = z * f_x_;
	return temp;
}

float cVector3::dot(cVector3& v1, cVector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

cVector3 cVector3::cross(cVector3& v1, cVector3& v2)
{
	cVector3 temp = {};
	temp.x = v1.y * v2.z - v1.z * v2.y;
	temp.y = v1.z * v2.x - v1.x * v2.z;
	temp.z = v1.x * v2.y - v1.y * v2.x;
	return temp;
}

float cVector3::angle(cVector3& v1, cVector3& v2, bool mode)
{
	float rad = acos(dot(v1, v2) / v1.length() / v2.length());
	if (mode)
		return rad * 180 * M_1_PI;
	else
		return rad;
}

float cVector3::length()
{
	return sqrt(x * x + y * y + z * z);
}

cVector3 cVector3::normalize()
{
	return *this / length();
}


std::ostream& operator<<(std::ostream& os, cVector3& vector3)
{
	os << "(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")";
	return os;
}

std::istream& operator>>(std::istream& is, cVector3& vector3)
{
	is >> vector3.x >> vector3.y >> vector3.z;
	return is;
}
