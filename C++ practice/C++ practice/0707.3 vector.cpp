#include "stdafx.h"
const int NUM = 5;

int main()
{
	vector<int>	ratings(NUM);
	vector<string> titles(NUM);
	cout << NUM << "���� å ����� å ���(0-10)�� �Է��Ͻʽÿ�." << endl;
	for (int i = 0; i < NUM; i++)
	{
		cout << i + 1 << "�� å�� ������ �Է��Ͻʽÿ�: ";
		getline(cin, titles[i]);
		cout << i + 1 << "�� å�� ���(0-10)�� �Է��Ͻʽÿ�: ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "�����մϴ�. ����� ������ ���� �Է����̽��ϴ�: " << endl;
	cout << "���\t����\n";
	for (int i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}

	return 0;
}
