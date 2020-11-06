#include "stdafx.h"
#include "class/ConsolePersonObserver.h"
#include "class/Subject.h"
#include "class/Observer.h"
#include "class/ClockTimer.h"


int main()
{
	ClockTimer p(20);
	ConsolePersonObserver cpo;// = new ConsolePersonObserver;
	p.subscribe(&cpo);
	p.set_age(21);
	p.set_age(22);
	return 0;
}
