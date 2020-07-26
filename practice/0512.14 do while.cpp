#include "stdafx.h"

int main(void)
{
	// do while. 뭔가 반드시 한번은 실행을 해야할 때. 메뉴라던지.
	char ch = 0;

	do
	{
		ch = getchar();
		putchar(ch);
	} while (ch != '\n'); // do while은 조건식 마지막에 반드시 ;가 들어가는 것에 주의

	return 0;
}
