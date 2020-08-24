#pragma once
#include <vector>
using std::vector;
class iActorBase
{
public:
	virtual void show(HDC hdc) = 0;
	virtual void update() = 0;
};

class cController
{
protected:
	bool _isBinding;
	static vector<cController*> vecController;
	static cController* focused;
public:
	cController();
	virtual ~cController();
	bool getBind() { return _isBinding; }
	bool setBind(bool b) { return _isBinding = b; }
	__declspec(property(get = getBind, put = setBind)) bool isBinding;
	static void focus(cController* con)
	{ 
		for (auto c : vecController)
		{
			if (con == c)
				con->isBinding = true;
			else
				con->isBinding = false;
		}
		focused = con;
	}

	virtual bool getInput() = 0;
};


// 대화가 가능한 객체에 대한 인터페이스