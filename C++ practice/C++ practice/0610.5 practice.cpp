#include "stdafx.h"
#include <cmath>
#include <Windows.h>

struct dot
{
	float X;
	float Y;
};

float distance(dot, dot);

int main()
{
	dot a = { 0 };
	dot b = { 0 };
	cout << "두 점의 좌표를 입력해주세요 x, y" << endl;
	cout << "첫 번째 점의 좌표 :" << endl;
	cin >> a.X >> a.Y;
	cout << "두 번째 점의 좌표 :" << endl;
	cin >> b.X >> b.Y;

	cout << "두 점 사이의 거리 : " << distance(a, b) << endl;

	return 0;
}

float distance(dot a, dot b)
{
	float n = pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2);
	return pow(n, 0.5);
}