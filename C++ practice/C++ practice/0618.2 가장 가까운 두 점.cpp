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
			cout << "����� �� ��: ";
			cout << "(" << near[0].x << ", " << near[0].y << ") ";
			cout << "(" << near[1].x << ", " << near[1].y << ") " << endl;
			cout << "�Ÿ� : " << sqrt(dist);
		}
	}
	return 0;
}

int getInput(vector<dot> & arr)
{
	dot tmp;
	cout << "���� �Է����ּ���. (���ڰ� �ƴ� ���� ������ ����)" << endl;
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
		cout << "2�� �̻��� ���� �Է����ּ���." << endl;
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