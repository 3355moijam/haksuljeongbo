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
	setSize();
	
	img = (HBITMAP)LoadImage(NULL, TEXT("src/img1.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(img, sizeof(BITMAP), &imgData);
	
	imgSize = (imgData.bmWidth - 20) * (imgData.bmHeight - 20);

	OriginRegion = CreateRectRgn(-10, -10, imgData.bmWidth + 10, imgData.bmHeight + 10);
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


	HBRUSH hBrush = CreateSolidBrush(RGB(0, 200, 200));
	HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush2);
	FillRgn(hdc, MaskRegion, hBrush2);

	SelectObject(hdc, hBrush);
	FrameRgn(hdc, MaskRegion, hBrush, 4, 4);
	//PaintRgn(hdc, MaskRegion);


	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);
	DeleteObject(hBrush2);
	DeleteDC(hImgMemDC);
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

void cArea::set_new_area(polygon& path, double start, double end)
{
	polygon vecTemp1(path);
	polygon vecTemp2(path);
	
	int length = vertex.size();
	
	int tempEnd = static_cast<int> (end + 1) % length;
	int tempStart = static_cast<int> (ceil(start)) % length;
	

	if (tempEnd == tempStart)
	{
		// 폴리곤 꼬이는 경우 경로뒤집기
		if (PtDistance(path.back(), vertex[tempEnd]) > PtDistance(path[0], vertex[tempEnd]))
		{
			std::reverse(vecTemp2.begin(), vecTemp2.end());

			double dtemp;
			SWAP(start, end, dtemp);
			tempEnd = static_cast<int> (end + 1) % length;
			tempStart = static_cast<int> (ceil(start)) % length;
		}
		
		do
		{
			vecTemp2.push_back(vertex[tempEnd]);
			tempEnd++;
			if (tempEnd >= length)
				tempEnd %= length;
		} while (tempEnd != tempStart);
	}
	else
	{
		while (tempEnd != tempStart)
		{
			vecTemp1.push_back(vertex[tempEnd]);
			tempEnd++;
			if (tempEnd >= length)
				tempEnd %= length;
		}

		tempEnd = static_cast<int> ((end - 0.5) + length) % length;
		tempStart = static_cast<int> (floor(start)) % length;

		while (tempEnd != tempStart)
		{
			vecTemp2.push_back(vertex[tempEnd]);
			tempEnd--;
			if (tempEnd < 0)
			{
				tempEnd += length;
				tempEnd %= length;
			}
		}
	}

	// 넓이 비교
	long t1 = getPolyArea(vecTemp1);
	long t2 = getPolyArea(vecTemp2);

	DeleteObject(region);
	vertex.clear();

	if (t1 > t2)	vertex.assign(vecTemp1.begin(), vecTemp1.end());
	else			vertex.assign(vecTemp2.begin(), vecTemp2.end());
	
	region = CreatePolyVectorRgn(vertex);
	setSize();
	CombineRgn(MaskRegion, OriginRegion, region, RGN_DIFF);
}

// 0:x+, 1:y+, 2:x-, 3:y-, -1:error
void cPlayer::setDirect(const POINT &temp)
{
	POINT back = path.back();
	POINT bfback = path[path.size() - 2];

	POINT tempDir = back - bfback;

	if (tempDir.x > 0)
		before_direct = 0;
	else if (tempDir.y > 0)
		before_direct = 1;
	else if (tempDir.x < 0)
		before_direct = 2;
	else if (tempDir.y < 0)
		before_direct = 3;
	else
		before_direct = -1;

	tempDir = temp - back;

	if (tempDir.x > 0)
		current_direct = 0;
	else if (tempDir.y > 0)
		current_direct = 1;
	else if (tempDir.x < 0)
		current_direct = 2;
	else if (tempDir.y < 0)
		current_direct = 3;
	else
		current_direct = -1;
}

void cPlayer::setDirect()
{
	if (path.size() < 2)
	{
		before_direct = -1;
		return;
	}
	POINT back = path.back();
	POINT bfback = path[path.size() - 2];

	POINT tempDir = back - bfback;

	if (tempDir.x > 0)
		before_direct = 0;
	else if (tempDir.y > 0)
		before_direct = 1;
	else if (tempDir.x < 0)
		before_direct = 2;
	else if (tempDir.y < 0)
		before_direct = 3;
	else
		before_direct = -1;
}

bool cPlayer::check_comeback(cArea & area)
{
	if (path.size() < 2)
	{
		path.clear();
		return true;
	}
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
	unsigned int length = path.size();
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
	DeleteObject(hBrush);
}

bool cPlayer::move(cArea & area)
{
	POINT temp = center;
	POINT temp2 = center;
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		temp.x -= speed;
		temp2.x -= 5;
	}
	else if (GetKeyState(VK_UP) & 0x8000)
	{
		temp.y -= speed;
		temp2.y -= 5;
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		temp.x += speed;
		temp2.x += 5;
	}
	else if (GetKeyState(VK_DOWN) & 0x8000)
	{
		temp.y += speed;
		temp2.y += 5;
	}
	else
		return false;

	if (temp.x <= 0 || temp.x >= view.right || temp.y <= 0 || temp.y >= view.bottom)
		return false;
	
	if (path.size())
		setDirect(temp);

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
		if (!PtInPoly(area.vertex, temp2))
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

			if (before_direct == current_direct)
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
					return true;
				}
				else
				{
					center = temp;
					path.push_back(center);
				}
			}

		}

		// >> 다시 도형으로 돌아왔는가
		check_comeback(area);
		// <<
	}
	
	
	return false;
}


void cPlayer::path_rewind()
{
	setDirect();
	POINT temp = center;
	switch (before_direct)
	{
	case 0:
		temp.x -= speed;
		break;
	case 1:
		temp.y -= speed;
		break;
	case 2:
		temp.x += speed;
		break;
	case 3:
		temp.y += speed;
		break;
	case -1:
		break;
	}
	path.pop_back();
	center = temp;
	if (path.back() != center)
		path.push_back(center);


	if (path.size() == 1)
		path.clear();
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

void cPlayer::update()
{
	if(path.size() && !(GetKeyState('A') & 0x8000))
		path_rewind();
}




cGame::cGame() :area(), player()
{

}

cGame::~cGame()
{
}

void cGame::show(HDC hdc)
{
	//DrawGrid(hdc, 0, 0, view.right, view.left, 10);
	area.show(hdc);
	player.show(hdc);
}

void cGame::move(WPARAM wParam)
{
	//player.move(wParam, area);
	//if(player.move(wParam, area))
		//area.update();
}

void cGame::update()
{
	player.move(area);
	player.update();
	//area.update();
}
