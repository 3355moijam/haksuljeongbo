#pragma once
#include "Observable.h"
//#include "Observer.h"
//
//template <typename T>
//void Observable<T>::notify(T& source, const string& name)
//{
//	for (auto* observer : observers)
//	{
//		observer->field_changed(source, name);
//	}
//}
//
//template <typename T>
//void Observable<T>::subscribe(Observer<T>* f)
//{
//	this->observers.push_back(f);
//}
//
//template <typename T>
//void Observable<T>::unsubscribe(Observer<T>* f)
//{
//	observers.erase(find(observers.begin(), observers.end(), f));
//}