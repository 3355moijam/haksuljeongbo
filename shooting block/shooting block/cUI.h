#pragma once
#include "stdafx.h"

class cCountDown;
class button_close;
class button_retry;

extern HWND hWnd;
extern RECT view;

enum mode { main, game, gameover };
extern int score;
class cUI
{
private:
	wstring user_id;
	mode ui_mode;
	cCountDown* counter;
	button_retry* retry;
	button_close* close;
	List* ranking;
	wstring sRank;

	void draw_main(HDC hdc);
	void draw_game(HDC hdc);
	void draw_gameover(HDC hdc);
public:
	cUI();
	~cUI();
	mode get_mode() { return ui_mode; }
	void set_mode(mode nInput);
	void draw(HDC hdc);
	int get_input(WPARAM wParam);
	cCountDown* get_counter() { return counter; }
	int click(LPARAM lParam);
	void load_ranking();
};

class button
{
protected:
	wstring text;
	RECT rect;
	RECT letterBox;
public:
	button(wstring sInput, int x, int y, int width, int height) : text(sInput)
	{
		SetRect(&rect, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
		SetRect(&letterBox, x - width / 2 + 20, y - height / 2 + 20, x + width / 2 - 20, y + height / 2 - 20);
	}
	bool getClick(int mx, int my) { return PtInRect(&rect, { mx, my }); }
	virtual void show(HDC hdc, int align = DT_CENTER)
	{
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		DrawText(hdc, text.c_str(), text.size(), &letterBox, DT_SINGLELINE | DT_VCENTER | align);
	}
	virtual void on_event(cUI* ui) {};
	int get_letter_x() { return letterBox.left; }
	int get_letter_y() { return letterBox.top; }
};

class button_close : public button
{
public:
	button_close(int x, int y, int width, int height) : button(_T("종료하기"), x, y, width, height) {}
	void on_event(cUI* ui) { DestroyWindow(hWnd); }
};

class button_retry : public button
{
public:
	button_retry(int x, int y, int width, int height) : button(_T("다시하기"), x, y, width, height) {}
	void on_event(cUI* ui) { ui->set_mode(mode::game); }
};


class cCountDown
{
private:
	int count;
	RECT letter_box;
public:
	int get_count() { return count; }
	int count_down() {	return --count; }
	cCountDown();
	~cCountDown();
	void show(HDC hdc);
};