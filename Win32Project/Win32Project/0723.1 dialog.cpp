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

VOID CALLBACK AniProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);
BOOL CALLBACK Dlg6_1Proc(HWND, UINT, WPARAM, LPARAM);

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
		GetClientRect(hWnd, &view);

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
	case WM_RBUTTONDOWN:
		
		DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg6_1Proc);
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



BOOL CALLBACK Dlg6_1Proc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	RECT _view, __view; POINT _pos;
	TCHAR word[256];
	UNREFERENCED_PARAMETER(lParam);

	static int Check[3], Radio;
	TCHAR hobby[][30] = { _T("독서"), _T("음악감상"), _T("코딩") };
	TCHAR sex[][30] = { _T("남자"), _T("여자") };
	TCHAR output[200];

	static HWND hCombo;
	static int selection;
	TCHAR name[30];


	switch (iMsg)
	{
	case WM_INITDIALOG:
		GetWindowRect(hWnd, &_view);
		GetWindowRect(hDlg, &__view);
		_pos.x = _view.left + (_view.right - _view.left) / 2 - (__view.right - __view.left) / 2;// __view.right / 2;
		_pos.y = _view.top + (_view.bottom - _view.top) / 2 - (__view.bottom - __view.top) / 2;//__view.bottom / 2;
		//SetWindowPos(hDlg, HWND_TOP, _view.right, _view.bottom, 500, 350, NULL);
		SetWindowPos(hDlg, HWND_TOP, _pos.x, _pos.y, __view.right - __view.left, __view.bottom - __view.top, NULL);


		/*HWND hButton;
		hButton = GetDlgItem(hDlg, ID_BUTTON_PRINT);
		EnableWindow(hButton, FALSE);*/

		CheckRadioButton(hDlg, IDC_RADIO_MALE, IDC_RADIO_FEMALE, IDC_RADIO_MALE);

		hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);

		return (INT_PTR)TRUE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_COPY:
			GetDlgItemText(hDlg, IDC_EDIT_INPUT, word, 256);
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, word);
			break;
		case IDC_BUTTON_DELETE:
			SetDlgItemText(hDlg, IDC_EDIT_INPUT, _T(""));
			SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, _T(""));
			break;
		case ID_BUTTON_END:
			EndDialog(hDlg, 0);
			break;


		case IDC_CHECK_READING:
			Check[0] = 1 - Check[0];
			break;
		case IDC_CHECK_MUSIC:
			Check[1] = 1 - Check[1];
			break;
		case IDC_CHECK_CODING:
			Check[2] = 1 - Check[2];
			break;
		case IDC_RADIO_MALE:
			Radio = 0;
			break;
		case IDC_RADIO_FEMALE:
			Radio = 1;
			break;
		case IDC_BUTTON_OUTPUT:
			_stprintf_s(output, _T("선택한 취미는 %s %s %s 입니다.\r\n")
				_T("선택한 성별은 %s 입니다"),
				Check[0] ? hobby[0] : _T(""),
				Check[1] ? hobby[1] : _T(""),
				Check[2] ? hobby[2] : _T(""),
				sex[Radio]);
			SetDlgItemText(hDlg, IDC_EDIT_SAMPLE, output);
			break;

		case IDC_BUTTON_INSERT:
			GetDlgItemText(hDlg, IDC_EDIT_NAME, name, 30);
			if (_tcscmp(name, _T("")))
			{
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
				return 0;
			}
			break;
		case IDC_BUTTON_DELETE2:
			SendMessage(hCombo, CB_DELETESTRING, selection, 0);
			return 0;
			break;
		case IDC_COMBO_LIST:
			if (HIWORD(wParam) == CBN_SELCHANGE)
				selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			break;

		default:
			break;
		}
	}
		break;
	default:
		break;
	}
	return false;
}