#include "stdafx.h"

template<typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;


struct job
{
	char name[40];
	double salary;
	int floor;
};
//template<> void Swap<job>(job &j1, job &j2);
void Swap<job>(job &j1, job &j2);
void Show(job &j);


int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i , j = " << i << ", " << j << "." << endl;
	cout << "컴파일러가 생성한 int형 교환기를 사용하면" << endl;
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << "." << endl;

	int d1[Lim] = { 0,7,0,4,1,7,7,6 };
	int d2[Lim] = { 0,6,2,0,1,9,6,9 };
	cout << "원본 배열:" << endl;
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "교환된 배열:" << endl;
	Show(d1);
	Show(d2);

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "job 교환 전:" << endl;
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	cout << "job 교환 후:" << endl;
	Show(sue);
	Show(sidney);
	return 0;
}

template<typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void Swap(T *a, T *b, int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}

//template<> void Swap<job>(job &j1, job &j2)
//{
//	double t1;
//	int t2;
//	t1 = j1.salary;
//	j1.salary = j2.salary;
//	j2.salary = t1;
//	t2 = j1.floor;
//	j1.floor = j2.floor;
//	j2.floor = t2;
//}

void Swap<job>(job &j1, job &j2)
{
		double t1;
		int t2;
		t1 = j1.salary;
		j1.salary = j2.salary;
		j2.salary = t1;
		t2 = j1.floor;
		j1.floor = j2.floor;
		j2.floor = t2;
}
void Show(job &j)
{
	cout << j.name << ": (" << j.floor << "층에 거주) "
		<< "$" << j.salary << endl;
}