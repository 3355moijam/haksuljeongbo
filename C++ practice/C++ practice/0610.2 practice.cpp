#include "stdafx.h"

using namespace std;
float CtoF(float C);
float MtoKm(float M);

int main()
{
	cout << "�� ���� ����������?" << endl;
	int n = 0;
	cin >> n;
	cout << "����� " << CtoF(n) << "km ���������ϴ�." << endl << endl;

	cout << "���� �?" << endl;
	int k = 0;
	cin >> k;
	cout << "���� " << k << "���� ȭ���� " << MtoKm(k) << "�� �Դϴ�." << endl;


	return 0;
}

float CtoF(float C)
{
	return C*1.60934;
}

float MtoKm(float M)
{
	return M * 1.8 + 32.0;
}