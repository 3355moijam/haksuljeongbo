#include "stdafx.h"
#include <vector>
#include <array>


int main()
{

	string a;
	char str[16];

	//cin.getline(str, 16); // ���๮�ڴ� �о�ͼ� ����
	//cin >> str;
	cin.get(str, 16).get(); // get�� ���๮�ڸ� ť�� ���ܵ�. �׷��� �ڿ� get�� �ѹ� �� ����
	cout << str << endl;
	cin.get(str, 16);
	cout << str << endl;

	

	return 0;
}
