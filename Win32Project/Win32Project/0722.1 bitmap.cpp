// Win32Project.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project.h"
#pragma comment(lib, "msimg32.lib")

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
RECT view;
TCHAR sKeyState[128];
int xStart = 0;
int yStart = 0;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int xPos = 0;
    switch (message)
    {
	case WM_CREATE:
		CreateBitmap();
		SetTimer(hWnd, 100, 17, NULL);
		SetTimer(hWnd, 102, 100, KeyStateProc);
		GetClientRect(hWnd, &view);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_KEYDOWN:
		SetTimer(hWnd, 101, 30, AniProc);
		break;
	case WM_KEYUP:
		KillTimer(hWnd, 101);
		break;
	case WM_TIMER:
		//UpdateFrame(hWnd);
		switch (wParam)
		{
		case 100:
			xPos += 5;
			if (xPos > view.right) xPos = 0;
			InvalidateRect(hWnd, NULL, false);
			break;
		default:
			break;
		}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			//DrawBitmap(hWnd, hdc);
			DrawBitmapDoubleBuffering(hWnd, hdc);
			DrawRectText(hdc, xPos);
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_SIZE:
		break;
    case WM_DESTROY:
		DeleteBitmap();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
POINT pos = {};
VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (GetKeyState('A') & 0x8000)
		pos.x -= 5;
	else if (GetKeyState('D') & 0x8000)
		pos.x += 5;
	UpdateFrame(hWnd);
	InvalidateRect(hWnd, NULL, false);
	//return VOID();
}

VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if (GetKeyState('A') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("A-Key"));
	}
	else if (GetKeyState('W') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("W-Key"));
	}
	else if (GetKeyState('D') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("D-Key"));
	}
	else if (GetKeyState('S') & 0x8000)
	{
		wsprintf(sKeyState, TEXT("%s"), _T("S-Key"));
	}
	else
	{
		wsprintf(sKeyState, TEXT("%s"), _T(""));
	}
}

HBITMAP hBackImage;
BITMAP bitBack;

HBITMAP	hTransparentImage;
BITMAP bitTransparent;

HBITMAP	hAniImage;
BITMAP bitAni;
const int sprite_size_x = 57;
const int sprite_size_y = 52;
int run_right_frame_max = 0;
int run_right_frame_min = 0;
int cur_frame = run_right_frame_min;
int run_left_frame_max = 0;
int run_left_frame_min = 13;

void CreateBitmap()
{
	hBackImage = (HBITMAP)LoadImage(NULL, TEXT("file/mables.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hBackImage, sizeof(BITMAP), &bitBack);


	hTransparentImage = (HBITMAP)LoadImage(NULL, TEXT("file/sigong.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hTransparentImage, sizeof(BITMAP), &bitTransparent);


	hAniImage = (HBITMAP)LoadImage(NULL, TEXT("file/zero_run.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(hAniImage, sizeof(BITMAP), &bitAni);
	run_right_frame_max = bitAni.bmWidth / sprite_size_x - 1;
	run_right_frame_min = 2;
	cur_frame = 0;// run_right_frame_min;
}
//void DrawBitmap(HWND hWnd, HDC hdc)
//{
//	HDC hMemDC;//, hMemDC2;
//	HBITMAP hOldBitmap; // , hOldBitmap2;
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage);
//		int bx = bitBack.bmWidth;
//		int by = bitBack.bmHeight;
//		BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
//		SelectObject(hMemDC, hOldBitmap);
//
//	}
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransparentImage);
//		int bx = bitTransparent.bmWidth;
//		int by = bitTransparent.bmHeight;
//		BitBlt(hdc, 100, 100, bx, by, hMemDC, 0, 0, SRCCOPY);
//		TransparentBlt(hdc, 200, 100, bx, by, hMemDC, 0, 0, bx, by, RGB(255,0,255));
//		SelectObject(hMemDC, hOldBitmap);
//
//	}
//	{
//		hMemDC = CreateCompatibleDC(hdc);
//		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage);
//		int bx = bitAni.bmWidth / 16;
//		int by = bitAni.bmHeight / 2;
//		int xStart = cur_frame * bx;
//		int yStart = 0;
//		//BitBlt(hdc, 400, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
//		TransparentBlt(hdc, 400, 100, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));
//		SelectObject(hMemDC, hOldBitmap);
//	}
//	
//	DeleteDC(hMemDC);
//	//DeleteDC(hMemDC2);
//}
void DeleteBitmap()
{
	DeleteObject(hBackImage);
	DeleteObject(hTransparentImage);
}

void UpdateFrame(HWND hWnd)
{
	static bool isRight = true;
	if (GetKeyState('D') & 0x8000)
	{
		if (isRight == false)
		{
			isRight = true;
			cur_frame = run_right_frame_min;
		}
		cur_frame++;
		if (cur_frame > run_right_frame_max)
		{
			cur_frame = run_right_frame_min;
		}
	}
	else if (GetKeyState('A') & 0x8000)
	{
		if (isRight == true)
		{
			isRight = false;
			cur_frame = run_left_frame_min;
		}
		cur_frame--;
		if (cur_frame < run_left_frame_max)
		{
			cur_frame = run_left_frame_min;
		}
	}
	//cur_frame %= (run_frame_max - run_frame_min);
	//cur_frame += run_frame_min;
}

void DrawRectText(HDC hdc, int xPos)
{
	TCHAR strTest[] = _T("텍스트 출력");
	TextOut(hdc, xPos, 0, strTest, _tcslen(strTest));
	TextOut(hdc, 100, 20, sKeyState, _tcslen(sKeyState));
}

HBITMAP hDoubleBufferImage;

void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc)
{
	HDC hMemDC, hMemDC2;
	HBITMAP hOldBitmap, hOldBitmap2;
	int bx, by;

	hMemDC = CreateCompatibleDC(hdc);
	if (hDoubleBufferImage == NULL)
	{
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, view.right, view.bottom);
	}
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;
		BitBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, SRCCOPY);
		SelectObject(hMemDC2, hOldBitmap2);

	}
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hTransparentImage);
		bx = bitTransparent.bmWidth;
		by = bitTransparent.bmHeight;
		BitBlt(hMemDC, 100, 100, bx, by, hMemDC2, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, 200, 100, bx, by, hMemDC2, 0, 0, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC2, hOldBitmap2);

	}
	{
		hMemDC2 = CreateCompatibleDC(hMemDC);
		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hAniImage);
		bx = bitAni.bmWidth / 16;
		by = bitAni.bmHeight / 2;
		xStart = cur_frame * bx;
		if (GetKeyState('A') & 0x8000)
		{
			yStart = by;
		}
		else if (GetKeyState('D') & 0x8000)
		{
			yStart = 0;
			//xStart = cur_frame * bx;
		}
		//BitBlt(hdc, 400, 200, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, pos.x, 300, bx, by, hMemDC2, xStart, yStart, bx, by, RGB(255, 0, 255));
		SelectObject(hMemDC2, hOldBitmap2);
	}
	BitBlt(hdc, 0, 0, view.right, view.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hMemDC);
}