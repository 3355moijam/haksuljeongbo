#include "stdafx.h"
#include "class\Student.h"

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = { Student(quizzes), Student(quizzes), Student(quizzes) };

	int i;
	for (i = 0; i < pupils; i++)
		set(ada[i], quizzes);

	cout << "\n�л� ����Ʈ:\n";
	for (i = 0; i < pupils; i++)
		cout << ada[i].Name() << endl;
	cout << "\n���� ���:\n";
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "���: " << ada[i].Average() << endl;
	}
	cout << "���α׷��� �����մϴ�. \n";
}

void set(Student & sa, int n)
{
	cout << "�л��� �̸��� �Է��Ͻʽÿ�: ";
	getline(cin, sa);
	cout << n << "ȸ�� ��ģ ���� ������ ��� �Է��Ͻʽÿ�: \n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
	{
		continue;
	}
}
