#pragma once
#include "Observer.h"
#include "ClockTimer.h"
#include "../stdafx.h"

class ConsolePersonObserver : public Observer<ClockTimer>
{
public:
	void field_changed(ClockTimer& source, const string& field_name) override
	{
		std::cout << "ClockTimer's " << field_name << " has changed to " << source.get_age() << ".\n";
	}
};