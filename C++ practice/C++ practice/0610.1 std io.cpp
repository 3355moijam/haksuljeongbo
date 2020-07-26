// C++ practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// zzzz
//aasd
int main()
{
	printf("C++ World!\n");
	std::cout << "C++ World! ";
	std::cout << std::endl;	// endl == 개행
	// std 클래스에서 cout, endl을 쓰는 것. 
	// 이걸 매번 쓰기 귀찮으니 쓰는 게 다음의 방법

	using namespace std;  // 이것도 귀찮으니 보통 전역변수로 선언함.
	cout << "C++ World! " << "C++ World!";
	cout << endl;
	

	float c = 2.145f;
	

	cout << c;
	cout << endl;

	int carrots = 25;

	cout << "나는 당근을 " << carrots << "개 가지고 있다." << endl;
	cout << "아삭아삭" << endl;
	cout << "이제 나는 당근을 " << --carrots << "개 가지고 있다." << endl;

	int n = 9;
	int a = 4;

	cin >> carrots;
	cout << "나는 당근을 " << carrots << "개 가지고 있다." << endl;
	cout << "아삭아삭" << endl;
	cout << "이제 나는 당근을 " << ----carrots << "개 가지고 있다." << endl;
    return 0;
}

