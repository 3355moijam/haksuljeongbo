#include "stdafx.h"

#include <fstream>

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ�: ";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ�: ";
	cin >> year;
	cout << "���� ������ �Է��Ͻÿ�: ";
	cin >> a_price;
	d_price = 0.913 * a_price;


	cout << fixed; // �Ҽ����� �����ϰڴٴ� ��.
	cout.precision(2); // 2�ڸ��� ����;
	cout.setf(ios_base::showpoint); // �ε��Ҽ��� ������ ����
	cout << "����Ŀ�� ����: " << automobile << endl;
	cout << "����: " << year << endl;
	cout << "���԰���: " << a_price << endl;
	cout << "���簡��: " << d_price << endl;
	

	outFile << fixed; // �Ҽ����� �����ϰڴٴ� ��.
	outFile.precision(2); // 2�ڸ��� ����;
	outFile.setf(ios_base::showpoint); // �ε��Ҽ��� ������ ����
	outFile << "����Ŀ�� ����: " << automobile << endl;
	outFile << "����: " << year << endl;
	outFile << "���԰���: " << a_price << endl;
	outFile << "���簡��: " << d_price << endl;

	outFile.close();
	return 0;
}
