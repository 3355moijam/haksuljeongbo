#include "stdafx.h"

int main(void)
{
	// break는 반복문을 탈출, continue는 반복문의 다음 스텝으로 점프

	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (i % 2 != 0)
			continue;

		if (i > 10)
			break;

		printf("%d\n", i);
	}

	return 0;
}
