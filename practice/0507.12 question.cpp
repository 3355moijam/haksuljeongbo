#include "stdafx.h"

int main(void)
{
	int age = 0;
	char name[10] = { 0 };

	printf("나이를 입력하세요. : ");
	scanf("%d%*C", &age); // %*C는 버퍼를 지워주는 것. 안지우면 엔터 치는 순간 남아서 뒤에 있는 gets에 영향을 미친다.
						  // scanf("Data : %d",~~) 처럼 쓰면 안됨. %d만 써야한다.
	printf("이름을 입력하세요. : ");
	gets_s(name);

	printf("당신의 나이는 %d살이고 이름은 \'%s\'입니다.\n", age, name);

	return 0;
}
