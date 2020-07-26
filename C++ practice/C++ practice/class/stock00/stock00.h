#pragma once
#include "../../stdafx.h"

class stock00
{
private:
	string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	void acquire(const string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long nu, double price);
	void update(double price);
	void show() const;

	stock00();
	stock00(const string & co, long n = 0, double pr = 0.0);
	~stock00();
};

