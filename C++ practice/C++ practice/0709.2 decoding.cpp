#include "stdafx.h"
#include <fstream>
#include <random>

void ifOpen(ifstream & fin, string src);
void decoding(char * buffer, ifstream & fin);
void fsave(char * buffer, string tar, size_t bufSize);

int main()
{
	string srcName = "file/리코짱빔encode.mp4";
	string tarName = "file/리코짱빔decode.mp4";

	ifstream fin;
	ifOpen(fin, srcName);
	size_t fsize = getFileSize(fin);

	char * buff = new char[fsize];

	decoding(buff, fin);
	fsave(buff, tarName, fsize);

	fin.close();
	delete[] buff;

	return 0;
}

void ifOpen(ifstream & fin, string src)
{
	fin.open(src, ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << src << " 파일을 열지 못했습니다. 경로를 확인해주세요." << endl;
		exit(EXIT_FAILURE);
	}
}

void decoding(char * buffer, ifstream & fin)
{
	size_t fsize = getFileSize(fin);
	fin.read(buffer, fsize);


	for (size_t i = 0; i < fsize; i++)
		buffer[i] -= 5;
}

void fsave(char * buffer, string tar, size_t bufSize)
{
	ofstream fout(tar, ios_base::out | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << tar << " 파일을 열지 못했습니다. 경로와 용량을 확인해주세요." << endl;
		exit(EXIT_FAILURE);
	}
	fout.write(buffer, bufSize);
	fout.close();
}
