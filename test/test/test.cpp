// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CDailyEffect.h"
#include "CEventPublisher.h"
#include "CObserver.h"
#include "CTestSingleton.h"

int main()
{
	CDailyEffect e1;
	//CDayState* p = new CMonday;
	cout << e1.GetCurrentState().use_count() << endl;
	e1.SetState(std::make_shared<CMonday>());
	cout << e1.GetCurrentState().use_count() << endl;
	e1.SetState(std::make_shared<CMonday>());
	cout << e1.GetCurrentState().use_count() << endl;
	{
		CDailyEffect e2;
		e2.SetState(e1.GetCurrentState());
		cout << e1.GetCurrentState().use_count() << endl;
	}
	cout << e1.GetCurrentState().use_count() << endl;
	return 0;
}

