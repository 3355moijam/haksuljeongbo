#include "stdafx.h"

int main(void)
{
	//형변환
	//강제로 변환하는 것이기 때문에 주의해야함. 정수>실수 같은 건 손실이 없지만 실수>정수는 데이터 손실이 생긴다.
	//>>기본적인 방법
	//int x = 5;
	//double y = 0.0;

	//y = (double)x;
	//printf("%f\n", y);

	//x = (int)y;
	//printf("%d\n", x);
	///////////////

	int x = 5;
	
	printf("%d\n", 5 / 2); // int / int > int
	printf("%f\n", 5.0 / 2); // double / int > double
	printf("%f\n", 5 / 2.0); // int / double > double
	printf("%f\n", (double)5 / 2); // double / int > double
	printf("%f\n", (double)x/ 2); // double / int > double
	printf("%f\n", x / (double)2); // int / double > double
	printf("%f\n", (double)(x/2)); // double

	return 0;
}
