#include "stdafx.h"

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;	// ����ü�� ����� �缱���� ���ÿ� �� ��
			// ������ �̷��� ���ϸ� ���� ���� struct USERDATA udata �̷��� �ؾ�����.
			// ������ �׷��� ���ص� struct�� ���� ����.

typedef int myInt;	// int�� myInt�� �缱��


void Method1();
void Method2();
void Struct1();

int main(int argc, char* argv[])
{
	// union ����ü.
	// ������ ���Ƽ� �� ���� ����. ��� struct�� ����
	// union�� ���� ��� �� ���� ū �뷮�� ����ϴ� �޸𸮿� ���缭 �Ҵ��.
	// int�� double�� ������ union�̸� 4+8byte�� �ƴ϶� 8byte�� �Ҵ�ȴ�.
	// �׷��� �ڷḦ ����� ����. �ڿ��� �Ʋ��� �ϴ� �ý����� ���鶧 ����.


	Struct1();
	//Method1();


	return 0;
}

void Struct1()
{
	USERDATA user = { 0, "", "" };
	user.nAge = 10;
	strcpy(user.szName, "Hoon");
	strcpy(user.szPhone, "010-1234-1234");

	printf("%d��, %s, %s\n", user.nAge, user.szName, user.szPhone);
}

void Method1()
{
	
}