#include "stdafx.h"

int main(void)
{
	//char ch = 0;

	//while ((ch = getchar()) != '\n') // ���͸� ġ�� ������ �Է��� ���ڵ��� ��ȯ
	//{
	//	putchar(ch);
	//}
	////////////////////////////////

	
	// while �ȿ� while
	// ������ ����ϱ�
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
