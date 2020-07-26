#include "stdafx.h"

int main(void)
{
	/*
	int nAge = 0;

	printf("나이를 입력하세요. : ");
	scanf("%d", &nAge); // scanf는 printf의 입력버전. %d(정수)값을 사용자가 입력하면 그 값을 nAge의 주소에 저장한다.
						// 잘못된 값을 입력하면 할당하지 않는다.


	printf("당신의 나이는 %d세 입니다.\n", nAge);
	*/
	/*
	int x = 0, y = 0;

	printf("두 정수를 입력하세요 : ");

	scanf("%d %d", &x, &y); // %d 사이에 공백이 있어도 동작 함.
	printf("두 수의 합은 %d 입니다.\n", x + y);
	*/
	/*
	char szBuffer[32] = { 0 };

	scanf("%s", szBuffer); // 문자열은 szBuffer만 써도 바로 주소로 연결이 된다. & 사용하지 말것.
	printf("%s\n", szBuffer);

	char szBufferLeft[32] = { 0 };
	char szBufferRight[32] = { 0 };

	scanf("%s%s", szBufferLeft, szBufferRight);
	printf("%s %s\n", szBufferLeft, szBufferRight); // 띄어쓰기를 넣어서 입력받고 싶으면 그냥 gets_s를 쓰는 게 낫다.
	*/
	
	char szName[32] = { 0 };
	int nAge = 0;

	printf("나이를 입력하세요. : ");
	scanf_s("%d", &nAge);

	printf("이름을 입력하세요. : ");
	// fflush(stdin); // 버퍼 안에 남은 것을 비우는 코드. 남아있던 개행문자를 제거함. fflush는 vs2015에선 지원을 중지했다.
	_fgetchar(); // 버퍼에 있는 것 하나를 가져오는 코드. \n을 가져오기 위해 사용된 것.
	gets_s(szName, sizeof(szName));

	printf("%d, %s\n", nAge, szName);
	
	return 0;
}
