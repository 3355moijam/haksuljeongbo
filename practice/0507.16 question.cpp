#include "stdafx.h"

int main(void)
{
	printf("���ʴ� ���ϱ�? : ");
	int input;
	scanf("%d", &input);

	printf("%d�ʴ� %02d�ð� %02d�� %02d�� �Դϴ�.\n", input, input / 3600, input % 3600 / 60, input % 60); 
	// ������ ������ ���� ���� �������� ��������, printf�� ������ �ӵ��� �� ��������.

	
	return 0;
}
