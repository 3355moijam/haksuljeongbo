#include "stdafx.h"

int main(void)
{
	//char ch = 0;

	//while ((ch = getchar()) != '\n') // 엔터를 치기 전까지 입력한 문자들을 반환
	//{
	//	putchar(ch);
	//}
	////////////////////////////////

	
	// while 안에 while
	// 구구단 출력하기
	int i = 0, j = 0;
	
	i = 2;
	while (i <= 9)
	{
		j = 1;
		while (j <= 9)
		{
			printf("%d * %d = %d\n", i, j, i*j);
			j++;
		}
		putchar('\n');
		i++;
	}
	

	return 0;
}
