#include "stdafx.h"

int main(void)
{
	printf("당신의 나이를 알려주세요 : ");
	int age = 0, price = 1000;
	scanf("%d", &age);

	if (age >= 65 || age <= 3)
		price = 0;
	else if (age <= 19)
		price *= 0.75;
	else if (age <= 13)
		price *= 0.5;
	
	printf("요금은 %d원 입니다.\n", price);

	return 0;
}
