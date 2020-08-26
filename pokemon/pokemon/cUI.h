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
	unsigned int dialogLineIndex = 0; // dialogLineIndex 부터 \n까지. 출력 후 \n이 다음dialogLineIndex가 됨.
public:
	cUITalk();
	~cUITalk();
	void show(HDC hdc);
	void update();
	bool getYesNo(bool b);
	/*
	
	1. z를 누른다.
	2. ispeaker객체를 확인한다.
	3. ispeaker가 ui를 만들고 dialog를 보낸다.
	4. uistate가 바뀐다.
	5. ui를 그린다.

	1. z를 누른다.
	2. ui가 다이얼로그를 그림.
		2-1. 다이얼로그 끝.
			2-1-1 자식 없음
				- binded에게 y/n 처리 결과를 보냄. 결과에 따라 메시지의 root가 바뀜.
			2-1-2. 자식 있음
				- y/n을 생성하고 state변경
				- y/n 결과 받을때까지 대기.  >>> dialog를 json을 이용한 트리구조로 만들기.
				- y/n에 따른 트리 이동.
		2-2. 끝나지 않음
			- 다음 메시지로 index 이동.
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
	talkui에게 y/n 선택 결과를 넘기고 스스로 삭제.
	uistate를 변경
	*/
};