//#include "stdafx.h"
//
//
//struct Score
//{
//	double math;
//	double english;
//	double total;
//};
//
//struct Group
//{
//	int a; 
//	double b;
//	Score c;
//};	// �����ݷ� �ʼ�
//
//struct USERDATA
//{
//	int nAge;
//	char szName[32];
//	char szPhone[32];
//};
//
//void Method1();
//void Method2();
//void Struct1();
//
//int main(int argc, char* argv[])
//{
//	// union ����ü.
//	// ������ ���Ƽ� �� ���� ����. ��� struct�� ����
//	// union�� ���� ��� �� ���� ū �뷮�� ����ϴ� �޸𸮿� ���缭 �Ҵ��.
//	// int�� double�� ������ union�̸� 4+8byte�� �ƴ϶� 8byte�� �Ҵ�ȴ�.
//	// �׷��� �ڷḦ ����� ����. �ڿ��� �Ʋ��� �ϴ� �ý����� ���鶧 ����.
//
//
//	//Struct1();
//	Method1();
//	
//
//	return 0;
//}
//
//void Struct1()
//{
//	Score s1 = { 10, 10, 19 };
//	struct Group g1 = { 10, 2.333, s1 };	// a,b�� ������ ������ �����ָ� ��. { 0 }�� �ʱ�ȭ�� ����.
//	Group g2 = { 20, 3.33, s1 };
//	Group g3 = g2;
//	g1.a = 10;
//	g1.b = 1.235;
//
//	printf("%d %lf %lf\n", g1.a, g1.b, g1.c.english);
//}
//
//void Method1()
//{
//	struct USERDATA user = { 0, "", "" };
//	user.nAge = 10;
//	strcpy(user.szName, "Hoon");
//	strcpy(user.szPhone, "010-1234-1234");
//
//	printf("%d��, %s, %s\n", user.nAge, user.szName, user.szPhone);
//}
//
//void Method2()
//{
//	USERDATA userList[4] = 
//	{
//		{ 10, "�����", "1234"},
//		{ 11, "������", "2345"},
//		{ 17, "������", "3456"},
//		{ 12, "����", "4567"}
//	};
//
//	int i = 0;
//
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d��\t%s\t%s\n", userList[i].nAge, userList[i].szName, userList[i].szPhone);
//	}
//}