#include "mytime0.h"
#include <iostream>
using std::ostream;


Time::Time() : hours(0), minutes(0)
{
}

Time::Time(int h, int m) : hours(h), minutes(m)
{

}

Time::~Time()
{
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
//Time Time::Sum(const Time & t) const
//{
//	Time sum;
//	sum.minutes = minutes + t.minutes;
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//	return sum;
//}
Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator-(const Time & t) const
{
	Time sum;
	sum.minutes = minutes - t.minutes;
	sum.hours = hours - t.hours - sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time Time::operator*(int t) const
{
	Time sum;
	sum.minutes = minutes * t;
	sum.hours = hours * t + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time operator*=(const Time & t, int x)
{
	return t * x;
}
void Time::Show() const
{
	std::cout << hours << "시간, " << minutes << "분";
}

ostream & operator<<(ostream & os, const Time & t)
{
	os << t.hours << "시간 " << t.minutes << "분";
	return os;
}