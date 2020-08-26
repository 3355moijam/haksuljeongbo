#pragma once
#include "stdafx.h"
#include "interface.h"

enum class enumUIState
{
	None = 0,
	OpenMenu = 1,
	Speak = 2,
	Battle = 10
};

class cUI : public iActorBase
{
private:
	static HFONT hFont;
protected:
	bool isActivate;
	HBITMAP hUIImg;
	BITMAP ImgData;
	static vector<cUI*> activated;
	wstring message;
	int menuIndex;
	int maxMenu;
public:
	cUI();
	virtual ~cUI();
	virtual void show(HDC hdc) = 0;
	virtual void update() = 0;
	
	
};

class cUIMenu : public cUI
{
public:
	cUIMenu();
	~cUIMenu();
	void show(HDC hdc);
	void update();

};

class cUITalk : public cUI
{
private:
	iSpeakActor* binded;
	wstring dialog;
	unsigned int dialogLineIndex = 0; // dialogLineIndex ���� \n����. ��� �� \n�� ����dialogLineIndex�� ��.
public:
	cUITalk();
	~cUITalk();
	void show(HDC hdc);
	void update();
	bool getYesNo(bool b);
	/*
	
	1. z�� ������.
	2. ispeaker��ü�� Ȯ���Ѵ�.
	3. ispeaker�� ui�� ����� dialog�� ������.
	4. uistate�� �ٲ��.
	5. ui�� �׸���.

	1. z�� ������.
	2. ui�� ���̾�α׸� �׸�.
		2-1. ���̾�α� ��.
			2-1-1 �ڽ� ����
				- binded���� y/n ó�� ����� ����. ����� ���� �޽����� root�� �ٲ�.
			2-1-2. �ڽ� ����
				- y/n�� �����ϰ� state����
				- y/n ��� ���������� ���.  >>> dialog�� json�� �̿��� Ʈ�������� �����.
				- y/n�� ���� Ʈ�� �̵�.
		2-2. ������ ����
			- ���� �޽����� index �̵�.
	*/
};

class cUIYesNo : public cUI
{
private:
	cUITalk* parrentUI;
public:
	void show(HDC hdc);
	void update();
	bool getInput();
	/*
	talkui���� y/n ���� ����� �ѱ�� ������ ����.
	uistate�� ����
	*/
};