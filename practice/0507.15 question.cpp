#include "stdafx.h"

int main(void)
{
	float a = 0;
	float b = 0;
	
	printf("�� ���� �Է��� �ּ��� : ");
	scanf("%f%f", &a, &b);

	printf("�Է¹��� �� : %f %f\n", a, b);
	printf("���� : %.2f\n", a+b);
	printf("���� : %.2f\n", a-b);
	printf("���� : %.2f\n", a*b);
	printf("������ : %.2f\n", a/b);
	printf("��� : %.2f\n", (a+b)/2);

	return 0;
}
