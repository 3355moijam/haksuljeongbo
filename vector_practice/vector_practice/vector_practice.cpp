// vector_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "cVector3.h"

int main()
{
	//비교
	//덧셈
	//내적
	//외적
	//

	cVector3 v1, v2, v3;
	

	cout << "v1 생성. 숫자 세개 입력 : ";
	cin >> v1;

	cout << "v2 생성. 숫자 세개 입력 : ";
	cin >> v2;

	cout << "v3 생성. 숫자 세개 입력 : ";
	cin >> v3;

	cout << "비교" << endl;
	cout << "v1 == v2 : " << (v1 == v2) << endl;
	cout << "v1 != v2 : " << (v1 != v2) << endl;
	cout << endl;

	cout << "덧셈" << endl;
	cout << "v1 + v2 : " << (v1 + v2) << endl;
	cout << "3v1 + 2v2 : " << (v1 * 3 + v2 * 2) << endl;
	cout << "v1 -2v2 : " << (v1 + v2 * -2) << endl;
	cout << "뺄셈" << endl;
	cout << "v1 - v2 : " << (v1 - v2) << endl;
	cout << "곱셈" << endl;
	cout << "v1 * 5 : " << (v1 * 5) << endl;
	cout << "나눗셈" << endl;
	cout << "v1 / 5 : " << (v1 / 5) << endl;
	cout << endl;

	cout << "내적" << endl;
	cout << "v1 dot v2 : " << cVector3::dot(v1, v2) << endl;
	cout << endl;
	
	cout << "외적" << endl;
	cout << "v1 cross v2 : " << cVector3::cross(v1, v2) << endl;
	cout << "v2 cross v1 : " << cVector3::cross(v2, v1) << endl;
	cout << endl;

	cout << "Normalize" << endl;
	cout << "v2 정규화 : " << v2.normalize() << endl;
	cout << endl;

	cout << "각도" << endl;
	cout << "각 : " << cVector3::angle(v1, v2, 1) << endl;
	cout << "검증(90이면 정상) : " << cVector3::angle(cVector3::cross(v1, v2), v1, 1) << endl;
	
	cout << "삼각형에 수직인 벡터" << endl;
	cout << cVector3::cross((v2 - v1), (v3 - v1)) << endl;
    return 0;
}

