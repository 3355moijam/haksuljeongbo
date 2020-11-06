#pragma once
#include "../stdafx.h"
#include "Observer.h"

template<typename T>
class Subject
{
public:
	virtual ~Subject() = default;

	virtual void Attach(Observer<T>*);
	virtual void Detach(Observer<T>*);
	virtual void Notify();
protected:
	Subject() = default;
private:
	vector<Observer<T>*> m_vecObservers;

};

template <typename T>
void Subject<T>::Attach(Observer<T>* o)
{
	m_vecObservers.push_back(o);
}

template <typename T>
void Subject<T>::Detach(Observer<T>* o)
{
	m_vecObservers.erase(m_vecObservers.begin(), m_vecObservers.end(), o);
}

template <typename T>
void Subject<T>::Notify()
{
	for (auto * p : m_vecObservers)
	{
		p->Update(this);
	}
}
