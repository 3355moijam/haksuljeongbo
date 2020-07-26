#include "stdafx.h"

struct dot
{
	float X;
	float Y;
};

float incline(dot, dot);

int main()
{
	cout << "두 점의 좌표를 입력해주세요: " << endl;
	dot A, B;
	cin >> A.X >> A.Y;
	cin >> B.X >> B.Y;

	float incl = incline(A, B);
	if (incl == INT_MAX)
	{
		return 0;
	}
	cout << "기울기는 " << incl << "입니다." << endl;
	return 0;
}

float incline(dot a, dot b)
{
	if (a.X - b.X == 0)
	{
		cout << "두 점의 기울기는 무한입니다." << endl;
		return INT_MAX;
	}
	return (a.Y - b.Y) / (a.X - b.X);
}