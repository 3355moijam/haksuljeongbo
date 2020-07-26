#include "stdafx.h"


void swapr(int &a, int &b);
void swapp(int *a, int *b);
void swapv(int a, int b);

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string &s2);
const string & version3(string & s1, const string &s2);

int main()
{
	//int rats = 101;
	//int & rodents = rats;

	//cout << "rats = " << rats << endl;
	//cout << "rodents = " << rodents << endl;
	//rodents++;

	//cout << "rats = " << rats << endl;
	//cout << "rodents = " << rodents << endl;

	//cout << "rats = " << &rats << endl;
	//cout << "rodents = " << &rodents << endl;


	//int wallet = 1000;
	//int wallet2 = 2000;

	//int & w1 = wallet;
	//int & w2 = wallet2;

	//cout << wallet << endl << wallet2 << endl << endl;

	//swapr(wallet, wallet2);
	//cout << wallet << endl << wallet2 << endl << endl;

	//swapp(&wallet, &wallet2);
	//cout << wallet << endl << wallet2 << endl << endl;

	//swapv(wallet, wallet2); // 안됨
	//cout << wallet << endl << wallet2 << endl << endl;

	//swapv(w1, w2);  // 안됨
	//cout << wallet << endl << wallet2 << endl << endl;

	string input = "yazawa nico";
	string copy = input;
	string result;

	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	input = copy;
	//result = version3(input, "@@@");
	result = "aaaa";
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	return 0;
}


void swapr(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapp(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

string version1(const string & s1, const string & s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string & version2(string & s1, const string &s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string & version3(string & s1, const string &s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}