#include "stdafx.h"
#include <fstream>
#include <memory>
#include <random>

void encoding(ifstream &fin, char * buffer);
void fsave(char * buffer, string target, size_t bufSize);

int main()
{
	string srcName = "file/����¯��.mp4";
	string tarName = "file/����¯��encode.mp4";

	ifstream fin(srcName, ios_base::in | ios_base::binary);
	size_t finSize = getFileSize(fin);
	char * buff = new char[finSize];
	
	encoding(fin, buff);
	fsave(buff, tarName, finSize);

	fin.close();

	delete[] buff;
	return 0;
}


void ifOpen(ifstream &fin, string src)
{
	fin.open(src, ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "������ ���� ���߽��ϴ�. ��θ� Ȯ�����ּ���" << endl;
		exit(EXIT_FAILURE);
	}
}

void encoding(ifstream & fin, char * buffer)
{
	size_t finSize = getFileSize(fin);
	fin.read(buffer, finSize);

	for (size_t i = 0; i < finSize; i++)
		buffer[i] += 5;

}

void fsave(char * buffer, string target, size_t bufSize)
{
	ofstream fout(target, ios_base::out | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "������ ���� ���߽��ϴ�. ��ο� ��ũ�뷮�� Ȯ�����ּ���." << endl;
		exit(EXIT_FAILURE);
	}
	fout.write(buffer, bufSize);
	fout.close();
}

