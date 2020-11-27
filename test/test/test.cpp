// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CDailyEffect.h"
#include "CEventPublisher.h"
#include "CObserver.h"
#include "CTestSingleton.h"

int main()
{
	cout << CTestSingleton::GetInstance()->GetA() << endl;
	CTestSingleton::GetInstance()->SetA(10);
	cout << CTestSingleton::GetInstance()->GetA() << endl;

	CTestSingleton k;
	k.SetA(15);
	cout << CTestSingleton::GetInstance()->GetA() << endl;
	cout << k.GetA() << endl;

	return 0;
}

