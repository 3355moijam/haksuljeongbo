#pragma once
#include "stdafx.h"

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
public:
	cGame_omok_client();
	~cGame_omok_client();
	static cGame_omok_client& GetInstance()
	{
		static cGame_omok_client omok;
		return omok;
	}
	void show(HDC hdc);
	bool CheckPossible(unsigned int x, unsigned int y);
	POINT MouseToIndex(unsigned int x, unsigned int y);
	POINT IndexToCoord(unsigned int x, unsigned int y);
};

