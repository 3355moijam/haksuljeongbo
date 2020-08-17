#pragma once
#include "omok_framework.h"
enum { BLACK = 1, WHITE, WATCH };


struct __declspec(dllexport) omok_initialize
{
	int player_type;
	int player_id;
	int player_turn;
};

struct __declspec(dllexport) omok_playlog
{
	int player_type;
	int player_turn;
	POINT index;
};

struct __declspec(dllexport) omok_chatlog
{
	int player_id;
	wstring message;
};

struct __declspec(dllexport) omok_gameend
{
	int winner;
	POINT index;
};

class __declspec(dllexport) cGame_omok
{
private:
	int field[19][19];
	int player_type;
	int player_turn;
	int player_id;

	HBITMAP omok_field;
	BITMAP fieldData;
	HBITMAP omok_black;
	BITMAP blackData;
	HBITMAP omok_white;
	BITMAP whiteData;
	POINT local_coord;
public:
	cGame_omok();
	~cGame_omok();
	static cGame_omok& GetInstance()
	{
		static cGame_omok omok;
		return omok;
	}
	void show(HDC hdc);
	bool PutStone(unsigned int mouse_x, unsigned int mouse_y, int color);
	bool PutStone(POINT index, int color) { field[index.y][index.x] = color; return true; }
	bool CheckPossible(unsigned int mouse_x, unsigned int mouse_y);
	POINT MouseToIndex(unsigned int mouse_x, unsigned int mouse_y);
	POINT IndexToCoord(unsigned int index_x, unsigned int index_y);
	omok_playlog getPlayLog(unsigned int mouse_x, unsigned int mouse_y) 
	{
		omok_playlog temp = { player_type, player_turn, MouseToIndex(mouse_x, mouse_y) }; 
		return temp; 
	}
	bool setPlayLog(omok_playlog &log);
	void setInit(omok_initialize& init)
	{
		player_type = init.player_type;
		player_id = init.player_id;
		player_turn = init.player_turn;
	}
	int getTurn() { return player_turn; }
	int getType() { return player_type; }
	bool CheckGameEnd(POINT index, int color);
	int GameOver(int winner);
};
