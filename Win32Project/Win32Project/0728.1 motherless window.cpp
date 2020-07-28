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
HWND hWnd;
TCHAR sKeyState[128];
int xStart = 0;
int yStart = 0;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



#define IDC_BTN_CHILD 100
#define IDC_BTN_CIRCLE 101
#define IDC_BTN_STAR 102
#define IDC_BTN_RECT 103
HWND childHwnd[3];
LRESULT CALLBACK ChildWndProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
int mode = 0;

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
	if (!InitInstance(hInstance, nCmdShow))
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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child1");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc2;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child2");
	RegisterClassExW(&wcex);

	wcex.lpfnWndProc = ChildWndProc3;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("Child3");
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	RegisterClassExW(&wcex);

	return true;
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

	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
		//SetTimer(hWnd, 100, 17, NULL);
		GetClientRect(hWnd, &view);

		childHwnd[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child1"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0 , 0, view.right - 500, view.bottom / 2 - 1,
			hWnd, NULL, hInst, NULL);

		childHwnd[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child2"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			0, view.bottom / 2 + 1, view.right - 500, view.bottom / 2 - 1,
			hWnd, NULL, hInst, NULL);
		childHwnd[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child3"),
			NULL,
			WS_CHILD | WS_VISIBLE,
			view.right - 500 + 1, 0, 500, view.bottom,
			hWnd, NULL, hInst, NULL);
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
		GetClientRect(hWnd, &view);

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		//DrawBitmap(hWnd, hdc);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_SIZE:
		break;
	case WM_RBUTTONDOWN:

		break;
	case WM_DESTROY:
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




LRESULT CALLBACK ChildWndProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (iMsg)
	{
	case WM_CREATE:
		
		break;
	case WM_COMMAND:
	{
		
	}
	break;
	case WM_LBUTTONDOWN:
	{
		POINT center = { LOWORD(lParam), HIWORD(lParam) };
		HDC hdc = GetDC(hDlg);
		//SendMessage(hWn)
		switch (mode)
		{
		case 0:
			TextOut(hdc, LOWORD(lParam), HIWORD(lParam), _T("에휴"), 2);
			break;
		case 1:
			DrawCircle(hdc, LOWORD(lParam), HIWORD(lParam), 50);
			break;
		case 2:
			Rectangle(hdc, center.x - 25, center.y - 25, center.x + 25, center.y + 25);
			break;
		case 3:
			DrawStar(hdc, &center, 50);
			break;
		default:
			break;
		}
		
		ReleaseDC(hDlg, hdc);
	}
		break;
	case WM_DESTROY:
		break;
	}
	//return LRESULT();
	return DefWindowProc(hDlg, iMsg, wParam, lParam);
}
LRESULT CALLBACK ChildWndProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static RECT child2_view;
	static POINT center;
	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hDlg, &child2_view);
		center.x = child2_view.right / 2;
		center.y = child2_view.bottom / 2;
		break;
	case WM_COMMAND:
		InvalidateRect(hDlg, NULL, true);
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		switch (mode)
		{
		case 0:
			TextOut(hdc, center.x, center.y, _T("에휴"), 2);
			break;
		case 1:
			DrawCircle(hdc, center.x, center.y, 100);
			break;
		case 2:
			Rectangle(hdc, center.x - 50, center.y - 50, center.x + 50, center.y + 50);
			break;
		case 3:
			DrawStar(hdc, &center, 100);
			break;
		default:
			break;
		}
		EndPaint(hDlg, &ps);
	}
		break;
	case WM_DESTROY:
		break;
	}
	//return LRESULT();
	return DefWindowProc(hDlg, iMsg, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc3(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hButton, hCircle, hRect, hStar;
	switch (iMsg)
	{
	case WM_CREATE:
		hButton = CreateWindow(_T("button"), _T("확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 10, 100, 25,
			hDlg, (HMENU)IDC_BTN_CHILD, hInst, NULL);
		hCircle = CreateWindow(_T("button"), _T("원"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 40, 100, 25,
			hDlg, (HMENU)IDC_BTN_CIRCLE, hInst, NULL);
		hRect = CreateWindow(_T("button"), _T("사각형"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 70, 100, 25,
			hDlg, (HMENU)IDC_BTN_RECT, hInst, NULL);
		hStar = CreateWindow(_T("button"), _T("별"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 100, 100, 25,
			hDlg, (HMENU)IDC_BTN_STAR, hInst, NULL);
		break;
	case WM_COMMAND:
	{	
		switch (LOWORD(wParam))
		{
		case IDC_BTN_CHILD:
			mode = 0;
			break;
		case IDC_BTN_CIRCLE:
			mode = 1;
		break;
		case IDC_BTN_RECT:
			mode = 2;
		break;
		case IDC_BTN_STAR:
			mode = 3;
		break;
		default:
			break;
		}
		SendMessage(childHwnd[1], WM_COMMAND, wParam, lParam);
	}
		break;
	case WM_DESTROY:
		break;
	}
	//return LRESULT();
	return DefWindowProc(hDlg, iMsg, wParam, lParam);
}
