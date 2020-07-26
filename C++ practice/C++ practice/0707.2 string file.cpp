#include "stdafx.h"
#include <fstream>
#include <cstdlib>


int main()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		if (item[0] == '\n')
		{
			getline(fin, item, ':');
			continue;
		}
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "프로그램을 종료합니다. \n";
	fin.close();

	return 0;
}
