#include "stdafx.h"

int main(void)
{
	char szName[32] = { 0 };
	int nSize = sizeof(szName); 

	printf("szName size: %d\n", nSize); // szName ũ�� ���.
	printf("�̸��� �Է��ϼ���: ");

	gets_s(szName,nSize); // gets_s�� �޺κп��� szName�� �޸� ũ�Ⱑ ���� �Ѵ�.



	printf("����� �̸��� ");
	puts(szName);
	puts("�Դϴ�."); // puts�� string ����, printf�� �پ��� ���˿� Ȱ�� ����.
	// �ϼ��� ������ ����ϴ� ���̸� puts�� ���� ������ �ű⿡ �̰����� ���ؼ� ����Ϸ��� printf�� ����.


	return 0;

}