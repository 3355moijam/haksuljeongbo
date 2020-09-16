#pragma once
#include <vector>
using std::vector;
class iActorBase abstract
{
public:
	virtual ~iActorBase() {};
	virtual void show(HDC hdc) = 0;
	virtual void update() = 0;
};

//class iController abstract
//{
//protected:
//	bool _isBinding;
//	static vector<iController*> vecController;
//	static iController* focused;
//public:
//	iController();
//	virtual ~iController();
//	bool getBind() { return _isBinding; }
//	bool setBind(bool b) { return _isBinding = b; }
//	__declspec(property(get = getBind, put = setBind)) bool isBinding;
//	static void focus(iController* con)
//	{ 
//		for (auto c : vecController)
//		{
//			if (con == c)
//				con->isBinding = true;
//			else
//				con->isBinding = false;
//		}
//		focused = con;
//	}
//
//	virtual bool getInput() = 0;
//};


// 대화가 가능한 객체에 대한 인터페이스
class iSpeakActor abstract
{
protected:

public:
	virtual ~iSpeakActor() {};
	virtual void say() = 0;
	//virtual void addMeet();
};