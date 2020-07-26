#include "stdafx.h"
#include <fstream>
#include <memory>

void getInput(string & filename, int count);
void ofOpen(ofstream & out, string name);
size_t ifOpen(ifstream & in, string name);
void fCombine(ofstream & fout, int count, string location);
size_t getFileSize(ifstream &f);

size_t g_unit = 1024 * 1024 * 1;

int main()
{
	string fName = "file/리코짱빔.zip";
	int count = 6;
	//getInput(fName, count);

	ofstream fout;
	ofOpen(fout, fName);

	fCombine(fout, count, fName);

	fout.close();

	return 0;
}

void getInput(string & filename, int count)
{
	cout << "원본 파일명: ";
	cin >> filename;
	cout << "파일 개수: ";
	cin >> count;
}

size_t getFileSize(ifstream &f)
{
	size_t temp;
	f.seekg(0, f.end);
	temp = f.tellg();
	f.seekg(0);

	return temp;
}

void ofOpen(ofstream & out, string name)
{
	out.open(name, ios_base::out | ios_base::binary | ios_base::ate);

	if (!out.is_open())
	{
		cerr << "파일을 열 수 없습니다. 경로를 확인해주세요." << endl;
		exit(EXIT_FAILURE);
	}

	return;
}

void fCombine(ofstream & fout, int count, string location)
{
	ifstream fin;
	string sTemp;

	for (size_t i = 1; i <= count; i++)
	{
		sTemp = location + "." + to_string(i);
		size_t size = ifOpen(fin, sTemp);
		unique_ptr<char[]> buf(new char[size]());

		fin.read(buf.get(), size);
		fout.write(buf.get(), size);
		fin.close();
	}
}

size_t ifOpen(ifstream & in, string name)
{
	in.open(name, ios_base::in | ios_base::binary);

	if (!in.is_open())
	{
		cerr << "파일을 열 수 없습니다. 경로를 확인해주세요." << endl;
		exit(EXIT_FAILURE);
	}

	return getFileSize(in);
}