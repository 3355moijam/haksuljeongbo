#pragma once

template <typename T>
class cSingleton
{
private:
	cSingleton() {};
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
	cSingleton(T const&) = delete;
	cSingleton(T&&) = delete;
	cSingleton& operator=(T const&) = delete;
	cSingleton& operator=(T &&) = delete;
};


class asdf : public cSingleton<asdf>
{
public:
};



