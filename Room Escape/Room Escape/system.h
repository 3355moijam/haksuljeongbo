#pragma once

extern wchar_t **g_arrImg;
extern wchar_t *g_szTxt;
extern wchar_t *g_szMenu;

extern int g_state;


void InitScreen(void);
void PrintScreen(void);

void PrintImg(void);
void PrintTxt(void);
void PrintMenu(void);

int getInput(void);
int checkState(int input);

void setMenu(void);
void setTxt(wchar_t *txt);
void addTxt(wchar_t *txt);

void gotoXY(short x, short y);
void gotoXY(COORD pos);

//void DoubleFree(wchar_t **arr, int len);

void gameExit(void);