#include "stdafx.h"

int main(void)
{
	// do while. ���� �ݵ�� �ѹ��� ������ �ؾ��� ��. �޴������.
	char ch = 0;

	do
	{
		ch = getchar();
		putchar(ch);
	} while (ch != '\n'); // do while�� ���ǽ� �������� �ݵ�� ;�� ���� �Ϳ� ����

	return 0;
}
