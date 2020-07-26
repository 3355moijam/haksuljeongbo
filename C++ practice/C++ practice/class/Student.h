#pragma once
#include "../stdafx.h"
#include <valarray>

class Student : private string, private valarray<double>
{
private:
	typedef valarray<double> ArrayDb;
	//string string;
	//ArrayDb ArrayDb;
	ostream & arr_out(ostream & os) const;
public:
	Student() :string("Null Student"), ArrayDb() {}
	explicit Student(const string & s) : string(s), ArrayDb() {}
	explicit Student(int n) : string("Nully"), ArrayDb(n) {}
	Student(const string & s, int n) : string(s), ArrayDb(n) {}
	Student(const string & s, const ArrayDb & a) : string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n) : string(str), ArrayDb(pd, n) {}
	~Student() {}
	double Average() const;
	const string & Name() const;
	double & operator[](int i);
	//double operaotr[](int i) const;
	
	friend istream & operator>>(istream &is, Student & stu);
	friend istream & getline(istream & is, Student & stu);
	friend ostream & operator<<(ostream & os, const Student & stu);
};

