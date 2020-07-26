#include "stdafx.h"
#include <fstream>
#include <cstdlib>

const int lim = 20;

struct planet
{
	char name[lim];
	double population;
	double g;
};

const char * file = "planets.dat";
inline void eatline() { while (cin.get() != '\n') continue; }

int main()
{
	planet pl;
	cout << fixed;

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		cout << file << " 파일의 현재 내용은 다음과 같습니다:" << endl;
		while (finout.read((char *)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(lim) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << file << " 파일을 읽다가 에러 발생." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 읽다가 에러 발생. 종료." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "수정할 레코드 번호를 입력하십시오: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 레코드 번호입니다. 종료." << endl;
		exit(EXIT_FAILURE);
	}

	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "레코드를 찾다가 에러 발생. " << endl;
		exit(EXIT_FAILURE);
	}
	finout.read((char *)& pl, sizeof pl);
	cout << "현재 레코드의 내용 : " << endl;
	cout << rec << ": " << setw(lim) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "행성의 이름을 입력하십시오: ";
	cin.get(pl.name, lim);
	eatline();
	cout << "행성의 인구를 입력하십시오: ";
	cin >> pl.population;
	cout << "행성의 중력가속도를 입력하십시오: ";
	cin >> pl.g;
	finout.seekp(place);
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "쓰다가 에러 발생. " << endl;
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << " 파일의 개정된 내용은 다음과 같습니다:" << endl;
	while (finout.read((char *)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(lim) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}