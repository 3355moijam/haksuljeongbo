// C++ practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// zzzz
//aasd
int main()
{
	printf("C++ World!\n");
	std::cout << "C++ World! ";
	std::cout << std::endl;	// endl == ����
	// std Ŭ�������� cout, endl�� ���� ��. 
	// �̰� �Ź� ���� �������� ���� �� ������ ���

	using namespace std;  // �̰͵� �������� ���� ���������� ������.
	cout << "C++ World! " << "C++ World!";
	cout << endl;
	

	float c = 2.145f;
	

	cout << c;
	cout << endl;

	int carrots = 25;

	cout << "���� ����� " << carrots << "�� ������ �ִ�." << endl;
	cout << "�ƻ�ƻ�" << endl;
	cout << "���� ���� ����� " << --carrots << "�� ������ �ִ�." << endl;

	int n = 9;
	int a = 4;

	cin >> carrots;
	cout << "���� ����� " << carrots << "�� ������ �ִ�." << endl;
	cout << "�ƻ�ƻ�" << endl;
	cout << "���� ���� ����� " << ----carrots << "�� ������ �ִ�." << endl;
    return 0;
}

