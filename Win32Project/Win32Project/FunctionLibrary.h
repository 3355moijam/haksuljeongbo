#pragma once

int randomInt(int from, int to);

void DrawGrid(HDC hdc, int x1, int y1, int x2, int y2, int interval);

void DrawCircle(HDC hdc, int centerX, int centerY, int radius);

void DrawSunflower(HDC hdc, int centerX, int centerY, int centerR, int sonR);

void DrawMaze(HDC hdc, int x1, int y1, int size);

POINT PointRotate(int centerX, int centerY, int degree, const POINT * point);

POINT PointRotate(int centerX, int centerY, double rad, const POINT * point);

void PointRotate(int centerX, int centerY, int degree, POINT & point);

void OutFromFile(TCHAR filename[], HWND hWnd);

void DrawStar(HDC hdc, POINT * center, int radius);

//void CreateBitmap();
//
//void DrawBitmap(HWND hWnd, HDC hdc);
//
//void DeleteBitmap();
//
//void UpdateFrame(HWND hWnd);
//
//void DrawRectText(HDC hdc, int xPos);
//
//void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc);

void setStar(POINT *center, int radius, POINT *star);

void rotateStar(POINT * center, POINT * star, int degree);

#define SWAP(a, b, temp) {temp = a; a = b; b = temp;}

//extern HBITMAP hBackImage;
//extern BITMAP bitBack;