#include "stdafx.h"
#include "cGame_omok_server.h"
#pragma comment(lib, "msimg32.lib")


cGame_omok_client::cGame_omok_client() : field(), omok_field(), omok_black(), omok_white()
{

	omok_field = (HBITMAP)LoadImage(NULL, TEXT("src/go_field.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_field, sizeof(BITMAP), &fieldData);

	omok_black = (HBITMAP)LoadImage(NULL, TEXT("src/go_black.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_black, sizeof(BITMAP), &blackData);

	omok_white = (HBITMAP)LoadImage(NULL, TEXT("src/go_white.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(omok_white, sizeof(BITMAP), &whiteData);
}


cGame_omok_client::~cGame_omok_client()
{
	DeleteObject(omok_field);
	DeleteObject(omok_black);
	DeleteObject(omok_white);
}

void cGame_omok_client::show(HDC hdc)
{
}

bool cGame_omok_client::CheckPossible(unsigned int x, unsigned int y)
{
	return false;
}

POINT cGame_omok_client::MouseToIndex(unsigned int x, unsigned int y)
{
	return POINT();
}

POINT cGame_omok_client::IndexToCoord(unsigned int x, unsigned int y)
{
	return POINT();
}


