#include "stdafx.h"
#include <cstdio>
#include <cstdlib>

int int_cmp(const int *a, const int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else 
		return 0;
}

int int_cmp(const void *a, const void *b)
{
	if (*(int*)a < *(int*)b)
		return -1;
	else if (*(int*)a > *(int*)b)
		return 1;
	else
		return 0;
}

int main()
{
	int i, nx, ky;
	int *x;
	int *p;
	cout << "bsearch �Լ��� ����� �˻�.\n��� ���� : ";
	cin >> nx;
	x = new int[nx];

	cout << "������������ �Է��ϼ���." << endl;
	for (int i = 0; i < nx; i++)
	{
		cout << "x[" << i << "] : ";
		cin >> x[i];
	}

	cout << "�˻��� : ";
	cin >> ky;

	//p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
	p = (int*)bsearch(&ky, x, nx, sizeof(int), int_cmp);

	if (p == NULL)
		cout << "�˻��� �����߽��ϴ�." << endl;
	else
		cout << ky << "�� x[" << (int)(p - x) << "]�� �ֽ��ϴ�." << endl;
	return 0;
}
