#include "stdafx.h"

int main(void)
{
	printf("����� ���̸� �˷��ּ��� : ");
	int age = 0, price = 1000;
	scanf("%d", &age);

	if (age >= 65 || age <= 3)
		price = 0;
	else if (age <= 19)
		price *= 0.75;
	else if (age <= 13)
		price *= 0.5;
	
	printf("����� %d�� �Դϴ�.\n", price);

	return 0;
}
