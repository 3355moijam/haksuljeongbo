#include "StringBad.h"
#include "../stdafx.h"


int MyString::num_strings = 0;
int MyString::HowMany()
{
	return num_strings;
}

MyString::MyString(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;
	//cout << num_strings << ": \"" << str
	//	<< "\" µðÆúÆ® °´Ã¼ »ý¼º\n";
}

MyString::MyString()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
	//cout << num_strings << ": \"" << str
	//	<< "\" µðÆúÆ® °´Ã¼ »ý¼º\n";
}

MyString::MyString(const MyString & st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	//cout << num_strings << ": \"" << str
	//	<< "\" µðÆúÆ® °´Ã¼ »ý¼º\n";
}


MyString::~MyString()
{
	//cout << "\"" << str << "\" °´Ã¼ ÆÄ±«, ";
	--num_strings;
	//cout << "³²Àº °´Ã¼ ¼ö: " << num_strings << "\n";
	delete[] str;
}

MyString & MyString::operator=(const MyString & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}
MyString & MyString::operator=(const char * s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}
char & MyString::operator[](int i)
{
	return str[i];
}

const char & MyString::operator[](int i) const
{
	return str[i];
}

bool operator<(const MyString & st1, const MyString & st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const MyString & st1, const MyString & st2)
{
	return st2 < st1;
}

bool operator==(const MyString & st1, const MyString & st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
ostream & operator<< (ostream & os, const MyString & st)
{
	os << st.str;
	return os;
}

istream & operator>> (istream & is, MyString & st)
{
	char temp[MyString::CINLIM];
	is.get(temp, MyString::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}