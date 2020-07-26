//#include "stdafx.h"
//#include <fstream>
//#include <memory>
//
//void getInput(string & filename);
//size_t ifOpen(ifstream & in, string name);
//void fSplit(ifstream & fin, size_t size, string location);
//
//size_t g_unit = 1024 * 1024 * 10;
//
//int main()
//{
//	string fName;
//	getInput(fName);
//
//	ifstream fin;
//	int fsize = ifOpen(fin, fName);
//
//	fSplit(fin, fsize, fName);
//	
//	fin.close();
//
//	return 0;
//}
//
//void getInput(string & filename)
//{
//	cout << "파일명: ";
//	cin >> filename;
//	cout << "나눌 크기: ";
//	cin >> g_unit;
//}
//
//size_t ifOpen(ifstream & in, string name)
//{
//	in.open(name, ios_base::in | ios_base::binary | ios_base::ate);
//
//	if (!in.is_open())
//	{
//		cerr << "파일을 열 수 없습니다. 경로를 확인해주세요." << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	size_t size = in.tellg();
//	in.seekg(0);
//
//	return size;
//}
//
//void fSplit(ifstream & fin, size_t size, string location)
//{
//	ofstream fout;
//	string sTemp;
//	unique_ptr<char[]> buf(new char[g_unit]());
//	size_t index = 1;
//
//	for (size_t i = 0; i < size; i += g_unit)
//	{
//		if (size - i < g_unit)
//			g_unit = size - i;
//		
//		sTemp = location + "." + to_string(index);
//		fin.read(buf.get(), g_unit);
//		fout.open(sTemp, ios_base::out | ios_base::binary);
//		fout.write(buf.get(), g_unit);
//		fout.close();
//		index++;
//	}
//
//}