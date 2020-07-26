#include "stdafx.h"

int main(void)
{
	char szName[32] = { 0 };
	int nSize = sizeof(szName); 

	printf("szName size: %d\n", nSize); // szName 크기 출력.
	printf("이름을 입력하세요: ");

	gets_s(szName,nSize); // gets_s의 뒷부분에는 szName의 메모리 크기가 들어가야 한다.



	printf("당신의 이름은 ");
	puts(szName);
	puts("입니다."); // puts는 string 전용, printf는 다양한 포맷에 활용 가능.
	// 완성된 문장을 출력하는 것이면 puts를 쓰면 되지만 거기에 이것저것 더해서 출력하려면 printf가 유용.


	return 0;

}