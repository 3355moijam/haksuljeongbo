#include "stdafx.h"
#include <list>
#include <algorithm>

void Show(int);
const int lim = 10;

int main()
{
	int ar[lim] = { 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + lim);
	list<int> lb(la);
	cout << "�������� ����Ʈ�� ����:\n\t";
	for_each(la.begin(), la.end(), Show);

	cout << endl;

	la.remove(4);
	cout << "remove() �޼���" << endl;
	cout << "la :\t";
	for_each(la.begin(), la.end(), Show);
	cout << "size : " << la.size() << la.max_size();
	cout << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "remove() �Լ�" << endl;
	cout << "lb :\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << "size : " << lb.size() << lb.max_size();
	cout << endl;

	lb.erase(last, lb.end());
	cout << "erase() �޼���" << endl;
	cout << "lb :\t";
	for_each(lb.begin(), lb.end(), Show);
	cout << "size : " << lb.size() << lb.max_size();
	cout << endl;
}
void Show(int v)
{
	cout << v << ' ';
}
