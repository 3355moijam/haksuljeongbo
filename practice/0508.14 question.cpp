#include "stdafx.h"

int main(void)
{
	int a, b;
	printf("서로 다른 두 수를 입력 해 주세요. : ");
	scanf("%d%d", &a, &b);

	if (a > b)
	{
		printf("%d\n", a - b);
	}
	else if (a < b)
		printf("%d\n", b - a);
	else
		printf("서로 다른 수를 입력 해 주세요.\n");


	return 0;
}
