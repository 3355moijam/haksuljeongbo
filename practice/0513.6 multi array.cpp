#include "stdafx.h"

int main(void)
{
	// aList[2][5] 앞이 행, 뒤가 열.
	// aList[0]은 0행의 주소. aList[1]은 1행의 주소.
	// 3차원 행렬도 가능한데 그러면 프로그램 복잡성이 올라가고 메모리도 많이 먹어서 사용을 피함.

	int aInt[3][4] = { 0 };  // [][]로 정의해도 되고(이젠 안됨), 열 개수만 정의해도 됨. 행 개수만 정의하는건 안됨.
	int nCounter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			aInt[i][j] = ++nCounter;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", aInt[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}
