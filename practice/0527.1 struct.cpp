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
//};	// 세미콜론 필수
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
//	// union 공용체.
//	// 단점이 많아서 잘 쓰지 않음. 대신 struct를 쓴다
//	// union은 내부 요소 중 가장 큰 용량을 사용하는 메모리에 맞춰서 할당됨.
//	// int랑 double이 내포된 union이면 4+8byte가 아니라 8byte만 할당된다.
//	// 그래서 자료를 덮어쓰기 쉬움. 자원을 아껴야 하는 시스템을 만들때 썼음.
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
//	struct Group g1 = { 10, 2.333, s1 };	// a,b를 선언한 순서만 맞춰주면 됨. { 0 }로 초기화도 가능.
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
//	printf("%d살, %s, %s\n", user.nAge, user.szName, user.szPhone);
//}
//
//void Method2()
//{
//	USERDATA userList[4] = 
//	{
//		{ 10, "김어준", "1234"},
//		{ 11, "정봉주", "2345"},
//		{ 17, "주진우", "3456"},
//		{ 12, "김용민", "4567"}
//	};
//
//	int i = 0;
//
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d살\t%s\t%s\n", userList[i].nAge, userList[i].szName, userList[i].szPhone);
//	}
//}