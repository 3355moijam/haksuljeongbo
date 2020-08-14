#pragma once
#include "stdafx.h"
enum { BLACK = 1, WHITE };
class cGame_omok_client
{
private:
	int field[19][19];
	HBITMAP omok_field;
	BITMAP fieldData;
	HBITMAP omok_black;
	BITMAP blackData;
	HBITMAP omok_white;
	BITMAP whiteData;
	POINT local_coord;
public:
	cGame_omok_client();
	~cGame_omok_client();
	static cGame_omok_client& GetInstance()
	{
		static cGame_omok_client omok;
		return omok;
	}
	void show(HDC hdc);
	bool PutStone(unsigned int x, unsigned int y, int color);
	bool CheckPossible(unsigned int x, unsigned int y);
	POINT MouseToIndex(unsigned int x, unsigned int y);
	POINT IndexToCoord(unsigned int x, unsigned int y);
};

