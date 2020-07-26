#include "stdafx.h"
#include <cstdlib>
#include <ctime>

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "Grand class" << endl; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h){}
	void Speak() const { cout << "Superb class" << endl; }
	virtual void Say() const { cout << "내가 가지고 있는 Superb 값은 " << Value() << "이다." << endl; }
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const { cout << "Magnificent class" << endl; }
	void Say() const { cout << "내가 가지고 있는 문자는 " << ch << "이고, 정수는 " << Value() << "이다." << endl; }
};

Grand * GetOne();

int main()
{
	Grand * pg;
	Superb * ps;
	for (size_t i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb *>(pg))
			ps->Say();
	}
	return 0;

	return 0;
}

Grand * GetOne()
{
	Grand *p;
	switch (randomInt(0, 2))
	{
	case 0: p = new Grand(randomInt(0, 99));
		break;
	case 1: p = new Superb(randomInt(0, 99));
		break;
	case 2: p = new Magnificent(randomInt(0, 99), 'A' + randomInt(0,25));
		break;
	}
	return p;
}
