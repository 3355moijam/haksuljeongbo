#include "stdafx.h"
#include <fstream>

const char * file = "guest.txt";

int main()
{
	char ch;

	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << file << " ������ ���� ������ ������ �����ϴ�.:" << endl;
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "����� ����	" << file << " ������ �� �� �����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "���ο� �մ� �̸����� �Է��Ͻʽÿ�(�������� �� �� �Է�):" << endl;
	string name;
	while (getline(cin,name) && name.size() > 0)
	{
		fout << name << endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << file << " ������ ������ ������ ������ �����ϴ�.:" << endl;
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "���α׷��� �����մϴ�." << endl;



	return 0;
}
