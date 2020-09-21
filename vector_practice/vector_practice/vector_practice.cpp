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
	//��
	//����
	//����
	//����
	//

	cVector3 v1, v2, v3;
	

	cout << "v1 ����. ���� ���� �Է� : ";
	cin >> v1;

	cout << "v2 ����. ���� ���� �Է� : ";
	cin >> v2;

	cout << "v3 ����. ���� ���� �Է� : ";
	cin >> v3;

	cout << "��" << endl;
	cout << "v1 == v2 : " << (v1 == v2) << endl;
	cout << "v1 != v2 : " << (v1 != v2) << endl;
	cout << endl;

	cout << "����" << endl;
	cout << "v1 + v2 : " << (v1 + v2) << endl;
	cout << "3v1 + 2v2 : " << (v1 * 3 + v2 * 2) << endl;
	cout << "v1 -2v2 : " << (v1 + v2 * -2) << endl;
	cout << "����" << endl;
	cout << "v1 - v2 : " << (v1 - v2) << endl;
	cout << "����" << endl;
	cout << "v1 * 5 : " << (v1 * 5) << endl;
	cout << "������" << endl;
	cout << "v1 / 5 : " << (v1 / 5) << endl;
	cout << endl;

	cout << "����" << endl;
	cout << "v1 dot v2 : " << cVector3::dot(v1, v2) << endl;
	cout << endl;
	
	cout << "����" << endl;
	cout << "v1 cross v2 : " << cVector3::cross(v1, v2) << endl;
	cout << "v2 cross v1 : " << cVector3::cross(v2, v1) << endl;
	cout << endl;

	cout << "Normalize" << endl;
	cout << "v2 ����ȭ : " << v2.normalize() << endl;
	cout << endl;

	cout << "����" << endl;
	cout << "�� : " << cVector3::angle(v1, v2, 1) << endl;
	cout << "����(90�̸� ����) : " << cVector3::angle(cVector3::cross(v1, v2), v1, 1) << endl;
	
	cout << "�ﰢ���� ������ ����" << endl;
	cout << cVector3::cross((v2 - v1), (v3 - v1)) << endl;
    return 0;
}

