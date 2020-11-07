// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CDailyEffect.h"
#include "CEventPublisher.h"
#include "CObserver.h"

int main()
{
	CPerson a("Àç¿í", 27);
	CHappyBirthDay b;
	a.AddAge();
	a.AddAge();
	a.AddAge();

	return 0;
}

