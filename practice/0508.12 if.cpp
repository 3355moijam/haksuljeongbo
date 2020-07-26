#include "stdafx.h"

int main(void)
{
	//int nAge = 0;

	//printf("나이를 입력하세요. : ");
	//scanf("%d", &nAge);

	//if (nAge >= 20)
	//	printf("당신의 나이는 %d세 입니다.\n", nAge);

	//puts("End");
	///////////////////////////////


	//int nInput = 0;
	//
	//printf("숫자를 입력하세요. : ");
	//scanf("%d", &nInput);

	//if (nInput > 0)
	//{
	//	printf("%d는 양수입니다.\n", nInput);
	//}

	//if (nInput < 0)
	//{
	//	printf("%d는 음수입니다.\n", nInput);
	//}

	//if (nInput == 0)
	//{
	//	printf("%d는 0입니다.\n", nInput);
	//}
	////////////////////////////////////////////


	//int nInput = -9999, nMax = 0;

	//printf("세 정수를 넣어주세요 : ");
	//
	//scanf("%d", &nInput);
	//nMax = nInput;
	//
	//scanf("%d", &nInput);
	//if (nMax < nInput)
	//{
	//	nMax = nInput;
	//}

	//scanf("%d", &nInput);
	//if (nMax < nInput)
	//{
	//	nMax = nInput;
	//}

	//printf("최대 : %d\n", nMax);
	/////////////////////////////////////////


	printf("당신의 나이는? : ");
	int age = 0;
	float price = 1000;
	
	scanf("%d", &age);

	if (age < 20)
		price *= 0.75;

	printf("요금은 %.0f원 입니다.\n", price);
	/////////////////////////////////


	return 0;
}