#pragma once
#include "../stdafx.h"



class MyString
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	MyString(const char * s);
	MyString();
	MyString(const MyString & st); //���������
	~MyString();
	int length() const { return len; }
	//������ �����ε�
	MyString & operator=(const MyString & st);
	MyString & operator=(const char * s);
	char & operator[](int i);
	const char & operator[](int i)	const;
	// ������
	friend bool operator<(const MyString & st1, const MyString & st2);
	friend bool operator>(const MyString & st1, const MyString & st2);
	friend bool operator==(const MyString & st1, const MyString & st2);
	friend ostream & operator<<(ostream & os, const MyString & st);
	friend istream & operator>>(istream & is, MyString & st);

	static int HowMany();
};

