#include "stdafx.h"

int main(void)
{
	// aList[2][5] ���� ��, �ڰ� ��.
	// aList[0]�� 0���� �ּ�. aList[1]�� 1���� �ּ�.
	// 3���� ��ĵ� �����ѵ� �׷��� ���α׷� ���⼺�� �ö󰡰� �޸𸮵� ���� �Ծ ����� ����.

	int aInt[3][4] = { 0 };  // [][]�� �����ص� �ǰ�(���� �ȵ�), �� ������ �����ص� ��. �� ������ �����ϴ°� �ȵ�.
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
