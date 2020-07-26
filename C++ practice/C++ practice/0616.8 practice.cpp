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
	cout << "bsearch 함수를 사용해 검색.\n요소 개수 : ";
	cin >> nx;
	x = new int[nx];

	cout << "오름차순으로 입력하세요." << endl;
	for (int i = 0; i < nx; i++)
	{
		cout << "x[" << i << "] : ";
		cin >> x[i];
	}

	cout << "검색값 : ";
	cin >> ky;

	//p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))int_cmp);
	p = (int*)bsearch(&ky, x, nx, sizeof(int), int_cmp);

	if (p == NULL)
		cout << "검색에 실패했습니다." << endl;
	else
		cout << ky << "는 x[" << (int)(p - x) << "]에 있습니다." << endl;
	return 0;
}
