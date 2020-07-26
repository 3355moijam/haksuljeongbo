#include "stdafx.h"

typedef struct USERDATA
{
	int nAge;
	char szName[32];
	char szPhone[32];
} USERDATA;	// 구조체의 선언과 재선언을 동시에 한 것
			// 예전엔 이렇게 안하면 변수 쓸때 struct USERDATA udata 이렇게 해야했음.
			// 지금은 그렇게 안해도 struct를 생략 가능.

typedef int myInt;	// int를 myInt로 재선언


void Method1();
void Method2();
void Struct1();

int main(int argc, char* argv[])
{
	// union 공용체.
	// 단점이 많아서 잘 쓰지 않음. 대신 struct를 쓴다
	// union은 내부 요소 중 가장 큰 용량을 사용하는 메모리에 맞춰서 할당됨.
	// int랑 double이 내포된 union이면 4+8byte가 아니라 8byte만 할당된다.
	// 그래서 자료를 덮어쓰기 쉬움. 자원을 아껴야 하는 시스템을 만들때 썼음.


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

	printf("%d살, %s, %s\n", user.nAge, user.szName, user.szPhone);
}

void Method1()
{
	
}