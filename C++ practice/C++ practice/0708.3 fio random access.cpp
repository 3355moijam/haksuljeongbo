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
		cout << file << " ������ ���� ������ ������ �����ϴ�:" << endl;
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
			cerr << file << " ������ �дٰ� ���� �߻�." << endl;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " ������ �дٰ� ���� �߻�. ����." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "������ ���ڵ� ��ȣ�� �Է��Ͻʽÿ�: ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "�߸��� ���ڵ� ��ȣ�Դϴ�. ����." << endl;
		exit(EXIT_FAILURE);
	}

	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "���ڵ带 ã�ٰ� ���� �߻�. " << endl;
		exit(EXIT_FAILURE);
	}
	finout.read((char *)& pl, sizeof pl);
	cout << "���� ���ڵ��� ���� : " << endl;
	cout << rec << ": " << setw(lim) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "�༺�� �̸��� �Է��Ͻʽÿ�: ";
	cin.get(pl.name, lim);
	eatline();
	cout << "�༺�� �α��� �Է��Ͻʽÿ�: ";
	cin >> pl.population;
	cout << "�༺�� �߷°��ӵ��� �Է��Ͻʽÿ�: ";
	cin >> pl.g;
	finout.seekp(place);
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "���ٰ� ���� �߻�. " << endl;
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << " ������ ������ ������ ������ �����ϴ�:" << endl;
	while (finout.read((char *)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(lim) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}