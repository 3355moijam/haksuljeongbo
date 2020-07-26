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
		cout << file << " 파일의 현재 내용은 다음과 같습니다.:" << endl;
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "출력을 위해	" << file << " 파일을 열 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "새로운 손님 이름들을 입력하십시오(끝내려면 빈 줄 입력):" << endl;
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
		cout << file << " 파일의 개정된 내용은 다음과 같습니다.:" << endl;
		while (fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "프로그램을 종료합니다." << endl;



	return 0;
}
