#pragma once

int randomInt(int from, int to);

void DrawGrid(HDC hdc, int x1, int y1, int x2, int y2, int interval);

void DrawCircle(HDC hdc, int centerX, int centerY, int radius);

BOOL DrawRectangle(HDC hdc, LPRECT rectangle);

POINT PointRotate(int centerX, int centerY, int degree, const POINT * point);

POINT PointRotate(int centerX, int centerY, double rad, const POINT * point);

void PointRotate(int centerX, int centerY, int degree, POINT & point);

#define SWAP(a, b, temp) {temp = a; a = b; b = temp;}