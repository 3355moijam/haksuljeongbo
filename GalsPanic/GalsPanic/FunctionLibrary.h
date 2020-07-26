#pragma once

void DrawGrid(HDC hdc, int x1, int y1, int x2, int y2, int interval);

void DrawCircle(HDC hdc, int centerX, int centerY, int radius);

void DrawCircle(HDC hdc, POINT center, int radius);

BOOL MoveToEx(HDC hdc, POINT to);

BOOL LineTo(HDC hdc, POINT to);
