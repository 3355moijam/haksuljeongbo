#include "stdafx.h"
#include <string>


int main()
{
	//char charr1[20];
	//char charr2[20] = "jaguar";

	//string str1;
	//string str2 = "panther";

	//cout << "����̰� ���� �� �� �Է�:";
	//cin >> charr1;
	//cout << "�ϳ� ��:";
	//cin >> str1;
	//cout << "������ ��� ����̰� �Դϴ�.";
	//cout << charr1 << " " << charr2 << " ";
	//cout << str1 << " " << str2 << " ";
	//cout << endl;

	//cout << charr2 << "�� �� ��° ���� :" << charr2[2] << endl;
	//cout << str2 << "�� �� ��° ���� :" << str2[2] << endl;
	/////////
	string str1 = "���� LA�� ������ �̾߱��Դϴ�. �ƴѰ� �𸣰ڴ� �ٽ� ���ƿñ��? �׷����ϳ�.. �ƴ� �𸣰ڴµ� ��°������ ��������������...";
	string str2 = "zz", str3;
	str3 = str1 + str2;
	cout << sizeof str1 << endl;
	cout << str1.size() << endl;
	cout << sizeof str3 << endl;
	cout << str3.size() << endl;
	return 0;
}
