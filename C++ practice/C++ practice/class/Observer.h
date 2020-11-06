#pragma once
#include "../stdafx.h"

template<typename T> class Subject;

template<typename T>
class Observer
{
public:
	virtual ~Observer() = default;
	virtual void Update(Subject<T>* theChangedSubject) = 0;
protected:
	Observer() = default;
};
