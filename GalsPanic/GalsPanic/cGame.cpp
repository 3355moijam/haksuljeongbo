#include "cGame.h"
#include <algorithm>
#pragma comment(lib, "msimg32.lib")

extern RECT view;


cArea::cArea() :vertex(4), MaskRegion(NULL)
{
	vertex[0] = { 100, 100 };
	vertex[1] = { 400, 100 };
	vertex[2] = { 400, 400 };
	vertex[3] = { 100, 400 };

	region = CreatePolyVectorRgn(vertex);
	
	img = (HBITMAP)LoadImage(NULL, TEXT("src/img1.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(img, sizeof(BITMAP), &imgData);
	
	OriginRegion = CreateRectRgn(0, 0, imgData.bmWidth, imgData.bmHeight);
	MaskRegion = CreateRectRgn(0, 0, 1, 1);
	CombineRgn(MaskRegion, OriginRegion, region, RGN_DIFF);
}

cArea::~cArea()
{
	DeleteObject(region);
	DeleteObject(OriginRegion);
	DeleteObject(MaskRegion);
	DeleteObject(img);
}

void cArea::show(HDC hdc)
{
	HDC hImgMemDC = CreateCompatibleDC(hdc);
	
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hImgMemDC, img);
	int bx = imgData.bmWidth;
	int by = imgData.bmHeight;
	BitBlt(hdc, 0, 0, bx, by, hImgMemDC, 0, 0, SRCCOPY);
	SelectObject(hImgMemDC, hOldBitmap);


	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	FillRgn(hdc, MaskRegion, hBrush);
	PaintRgn(hdc, MaskRegion);
	//FrameRgn 테두리 칠하기


	DeleteObject(SelectObject(hdc, hOldBrush));

}

void cArea::update()
{
	//DeleteObject(region);

	//region = CreatePolyVectorRgn(vertex);
}

double cArea::PtOnArea(POINT & target)
{
	double position = -1;
	int length = vertex.size();
	for (int i = 0; i < length; i++)
	{
		int temp = i + 1;
		if (temp == length)
			temp = 0;

		if (target == vertex[i])
		{
			position = i;
			break;
		}
		else if (IsBetweenPt(target, vertex[i], vertex[temp], 1))
		{
			position = i + 0.5;
			break;
		}
	}
	return position;
}

void cArea::set_new_area(vector<POINT>& path, double start, double end)
{
	vector<POINT> vecTemp1(path);
	vector<POINT> vecTemp2(path);
	POINT tempBack = path.back();
	//(start, end]
	int length = vertex.size();
	int tempEnd = static_cast<int> (end + 1) % length;
	int tempStart = static_cast<int> (start + 1) % length;
	if ((tempEnd == tempStart) && (PtDistance(path.back(), vertex[tempEnd]) < PtDistance(path[0], vertex[tempEnd])))
	{
		std::reverse(vecTemp1.begin(), vecTemp1.end());
		std::reverse(vecTemp2.begin(), vecTemp2.end());
		tempBack = vecTemp1.back();
	}
	while (tempEnd != tempStart)
	{
		//if (vertex[tempEnd] != tempBack)
			vecTemp1.push_back(vertex[tempEnd]);
		tempEnd++;
		if (tempEnd >= length)
			tempEnd %= length;
	} 

	tempEnd = (static_cast<int> (end - 0.5) + length) % length;
	while (tempEnd != tempStart)
	{
		if (vertex[tempEnd] != tempBack)
			vecTemp2.push_back(vertex[tempEnd]);
		tempEnd--;
		if (tempEnd < 0)
		{
			tempEnd += length;
			tempEnd %= length;
		}
	} 
	if(vecTemp2[0] != vertex[tempEnd])
		vecTemp2.push_back(vertex[tempEnd]);

	// 넓이 비교
	HRGN tempRgn1 = CreatePolyVectorRgn(vecTemp1);
	bool isInner = true;
	for (int i = 0; i < vecTemp2.size(); i++)
	{
		if (!PtInRegion(tempRgn1, vecTemp2[i]) && !PtOnPoly(vecTemp1, vecTemp2[i]))
		{
			isInner = false;
			break;
		}
	}
	
	DeleteObject(region);
	//DeleteObject(DrawingRegion);
	DeleteObject(tempRgn1);
	vertex.clear();
	if (isInner) // temp1이 큼
		vertex.assign(vecTemp1.begin(), vecTemp1.end());
	
	else // temp2가 큼
		vertex.assign(vecTemp2.begin(), vecTemp2.end());
	
	region = CreatePolyVectorRgn(vertex);
	//DrawingRegion = CreateRectRgn(0, 0, imgData.bmWidth, imgData.bmHeight);
	CombineRgn(MaskRegion, OriginRegion, region, RGN_DIFF);
	
}

bool cPlayer::check_comeback(cArea & area)
{
	double start, end;
	if ((end = area.PtOnArea(center)) != -1)
	{
		start = area.PtOnArea(path[0]);
		to = -1;
		area.set_new_area(path, start, end);
		if (path[0] != area.vertex[0])
			from = 0;
		else
			from = path.size() - 1;

		path.clear();
		return true;
	}
	else
		return false;
}

cPlayer::cPlayer() :radius(10), speed(10), from(0), to(-1), path(), before_direct(0), current_direct(0)
{
	center.x = 100;
	center.y = 100;
}

cPlayer::cPlayer(int _x, int _y) :radius(10), speed(10), from(0), to(-1), path(), before_direct(0), current_direct(0)
{
	center.x = _x;
	center.y = _y;
}

void cPlayer::show(HDC hdc)
{
	int length = path.size();
	if (length)
	{
		MoveToEx(hdc, path[0]);
		for (size_t i = 1; i < length; i++)
		{
			LineTo(hdc, path[i]);
		}
	}

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	DrawCircle(hdc, center, radius);
	DeleteObject(SelectObject(hdc, hOldBrush));
}

bool cPlayer::move(WPARAM wParam, cArea & area)
{
	POINT temp = center;
	switch (wParam)
	{
	case VK_LEFT:
		temp.x -= speed;
		break;
	case VK_UP:
		temp.y -= speed;
		break;
	case VK_RIGHT:
		temp.x += speed;
		break;
	case VK_DOWN:
		temp.y += speed;
		break;
	default:
		return false;
	}
	if (before_direct == 0)
	{
		before_direct = wParam;
	}
	else
		before_direct = current_direct;
	current_direct = wParam;
	

	int ntemp1, ntemp2;
	ntemp1 = from == 0 ? area.vertex.size() - 1 : from - 1;
	ntemp2 = (from + 1) == area.vertex.size() ? 0 : from + 1;
	

	// >> 선위에 있을 때
	if (path.size() == 0)
	{
		// >>> 선따라 움직이기
		if (to != -1)
		{
			if (IsBetweenPt(temp, area.vertex[from], area.vertex[to]))
			{
				center = temp;

				if (temp == area.vertex[from])
					to = -1;
				else if (temp == area.vertex[to])
				{
					from = to;
					to = -1;
				}
				return false;
			}
		}
		else // to == -1
		{
			if (IsBetweenPt(temp, area.vertex[from], area.vertex[ntemp1]))
			{
				center = temp;
				if (temp == area.vertex[ntemp1])
					from = ntemp1;
				else
					to = ntemp1;
				return false;
			}
			else if (IsBetweenPt(temp, area.vertex[from], area.vertex[ntemp2]))
			{
				center = temp;
				if (temp == area.vertex[ntemp2])
					from = ntemp2;
				else
					to = ntemp2;
				return false;
			}
		}
		// <<<

		// >>> 선 밖으로 나가기
		if (!PtInRegion(area.get_region(), temp.x, temp.y))
		{
			if (GetKeyState('A') & 0x8000)
			{
				path.push_back(center);
				center = temp;
				path.push_back(center);

				check_comeback(area);
			}
		}

		// <<<
	}
	// <<
	
	else
	{
		// >> 이동 부분
		if (GetKeyState('A') & 0x8000)
		{
			if (PtOnPath(temp) && !IsBetweenPt(temp, path.back(), path[path.size()-2]))
				return false;

			if (before_direct == current_direct) // || IsBetweenPt(temp, path.back(), path[path.size() - 2]))
			{
				path.pop_back();
				center = temp;
				path.push_back(center);
			}
			else
			{
				if (IsBetweenPt(temp, path.back(), path[path.size() - 2]))
				{
					path_rewind();
				}
				else
				{
					center = temp;
					path.push_back(center);
				}
			}

		}
		else
		{
			path_rewind();
		}
		// <<

		// >> 다시 도형으로 돌아왔는가
		check_comeback(area);
		// <<
	}
	
	
	return false;
}


void cPlayer::path_rewind()
{
}

bool cPlayer::PtOnPath(POINT & target)
{
	int length = path.size();
	for (int i = 0; i < length - 1; i++)
	{
		if (IsBetweenPt(target, path[i], path[i + 1]))
			return true;
	}
	return false;
}




cGame::cGame() :area(), player()
{

}

cGame::~cGame()
{
}

void cGame::show(HDC hdc)
{
	DrawGrid(hdc, 0, 0, view.right, view.left, 10);
	area.show(hdc);
	player.show(hdc);
}

void cGame::move(WPARAM wParam)
{
	if(player.move(wParam, area))
		area.update();
}