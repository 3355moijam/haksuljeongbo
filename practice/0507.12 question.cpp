#include "stdafx.h"

int main(void)
{
	int age = 0;
	char name[10] = { 0 };

	printf("���̸� �Է��ϼ���. : ");
	scanf("%d%*C", &age); // %*C�� ���۸� �����ִ� ��. ������� ���� ġ�� ���� ���Ƽ� �ڿ� �ִ� gets�� ������ ��ģ��.
						  // scanf("Data : %d",~~) ó�� ���� �ȵ�. %d�� ����Ѵ�.
	printf("�̸��� �Է��ϼ���. : ");
	gets_s(name);

	printf("����� ���̴� %d���̰� �̸��� \'%s\'�Դϴ�.\n", age, name);

	return 0;
}
