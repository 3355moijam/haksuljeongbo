#include "stdafx.h"

int main(void)
{
	/*int nResult = 0;
	
	nResult = 3 + 4;

	printf("nResult : %d\n", nResult - 5);*/
	

	/*char ch = 'A';

	printf("%c\n", ch);

	printf("%c\n", ch + 1);
	printf("%c\n", 'A' + 2);

	printf("%d : d\n", 5.0 + 2);
	printf("%f : f\n", 5.0 + 2);*/

	//int x = 10;
	//
	//printf("%d\n", x * 10); // int * int
	//printf("%d\n", x * 10.0); // int * double > 출력불능

	//printf("%d\n", x / 10);
	//printf("%d\n", 5 / 2); // int / int는 int가 출력된다. 소수점은 절삭
	//printf("%f\n", 5 / 2); // 이것도 int / int이므로 2가 출력. 단 double 형식으로 출력되어 2.0이 나온다.

	//printf("%f\n", 5.0 / 2); // double / int 는 double 이 출력

	//int x = 0;
	//scanf("%d", &x);

	//printf("몫 : %d\n", x / 3);
	//printf("나머지 : %d\n", x % 3);  
	//printf("나머지 : %d\n", x % 3.0); // 나머지연산은 반드시 int를 써야한다.


	// szBuffer가 배열일때 szBuffer = 'A'라고 하면 szBuffer의 메모리를 변경하려고 한 것이기 때문에 불가능. 배열은 & 없이 쓰면 주소를 가리킨다.

	// >>복합대입 연산자
	int nResult = 0, nData = 10;

	nResult += 3;
	printf("%d\n", nResult); 

	nResult *= nData;
	printf("%d\n", nResult);

	nResult /= 2;
	printf("%d\n", nResult);

	nResult -= nData - 5;
	printf("%d\n", nResult);

	nResult %= 3;
	printf("%d\n", nResult);
	// >> 끝


	return 0;
}
