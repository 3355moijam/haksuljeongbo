#include "Student.h"

ostream & Student::arr_out(ostream & os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for ( i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;

		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " ºó ¹è¿­ ";
			
	return os;
}

double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0.0;
}

const string & Student::Name() const
{
	return (const string &) *this;
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

istream & operator >> (istream & is, Student & stu)
{
	is >> (string &)stu;
	return is;
}

istream & getline(istream & is, Student & stu)
{
	getline(is, (string &)stu);
	return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
	os << "Scores for " << (const string &)stu << ":" << endl;
	stu.arr_out(os);
	return os;
}
