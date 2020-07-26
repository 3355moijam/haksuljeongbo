#pragma once
#include <iostream>
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	~Time();
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	//Time Sum(const Time & t) const;
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(int t) const;
	friend Time operator*(int m, const Time & t) { return t * m; }
	friend Time operator*=(const Time & t, int x);
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
	void Show() const;
};


