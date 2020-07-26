#include "stdafx.h"

struct dot
{
	float x, y;
};

int getInput(vector<dot> & arr);
float getNear(vector<dot> & arr, vector<dot> & near);
float getDist(dot &a, dot &b);

int main()
{
	vector<dot> dotArr;
	vector<dot> near;
	float dist = 0;

	while (1)
	{
		if (getInput(dotArr))
			break;

		dist = getNear(dotArr, near);
		if (dist != -1)
		{
			cout << "가까운 두 점: ";
			cout << "(" << near[0].x << ", " << near[0].y << ") ";
			cout << "(" << near[1].x << ", " << near[1].y << ") " << endl;
			cout << "거리 : " << sqrt(dist);
		}
	}
	return 0;
}

int getInput(vector<dot> & arr)
{
	dot tmp;
	cout << "점을 입력해주세요. (숫자가 아닌 값을 넣으면 종료)" << endl;
	cout << "X Y : ";
	cin >> tmp.x >> tmp.y;
	if (cin.fail())
		return 1;

	arr.push_back(tmp);

	return 0;
}

float getNear(vector<dot> & arr, vector<dot> & near)
{
	int len = arr.size() - 1;
	float nearBest;

	if (arr.size() < 2)
	{
		cout << "2개 이상의 점을 입력해주세요." << endl;
		return -1;
	}
	if (near.size() == 0)
	{
		near.push_back(arr[0]);
		near.push_back(arr[1]);
		return getDist(near[0], near[1]);
	}
	nearBest = getDist(near[0], near[1]);
	float nearCheck = 0;
	for (int i = 0; i < len; i++)
	{
		nearCheck = getDist(arr[i], arr[len]);
		if (nearBest > nearCheck)
		{
			nearBest = nearCheck;
			near[0] = arr[i];
			near[1] = arr[len];
		}
	}

	return nearBest;
}

float getDist(dot &a, dot &b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}