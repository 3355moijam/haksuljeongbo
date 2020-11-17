// shooting block.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "shooting block.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
HWND hWnd;
RECT view;
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

extern vector<vector<cGame*>> objectList;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_SHOOTINGBLOCK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SHOOTINGBLOCK));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHOOTINGBLOCK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCEW(IDC_SHOOTINGBLOCK);
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
   wcscpy_s(szTitle, _T("Pong Like"));
   //wcscpy(szWindowClass, _T("Pong Like"));
   hWnd = CreateWindowW(szWindowClass, szTitle, /*WS_CAPTION | WS_SYSMENU*/WS_OVERLAPPEDWINDOW,
      750, 200, 416, 659, nullptr, nullptr, hInstance, nullptr);

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
cUI ui;
cChar* chara;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		GetClientRect(hWnd, &view);
		CreateCaret(hWnd, NULL, 5, 12);
		ShowCaret(hWnd);
		
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
    case WM_PAINT:
        {
			HDC hdc, hMemDC;
			HBITMAP BackBit, OldBit;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd, &ps);
			hMemDC = CreateCompatibleDC(hdc);
			BackBit = CreateCompatibleBitmap(hMemDC, view.right, view.bottom);
			OldBit = (HBITMAP)SelectObject(hMemDC, BackBit);
			PatBlt(hMemDC, 0, 0, view.right, view.bottom, WHITENESS);

			if (ui.get_mode() == mode::game)
				cGame::draw(hMemDC);
			ui.draw(hMemDC);
			
			BitBlt(hdc, 0, 0, view.right, view.bottom, hMemDC, 0, 0, SRCCOPY);
			SelectObject(hMemDC, OldBit);
			DeleteDC(hMemDC);
			EndPaint(hWnd, &ps);
			
        }
        break;
	case WM_MOUSEMOVE:
	{
		if (cGame::is_start())
		{
			chara->set_direct(LOWORD(lParam), HIWORD(lParam));
		}
	}
		break;
	case WM_LBUTTONDOWN:
	{
		if (cGame::is_start())
		{
			chara->shoot();
		}
		else if (ui.get_mode() == mode::gameover)
			ui.click(lParam);
	}
		break;
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			if (ui.get_counter()->count_down() < 0)
			{
				delete ui.get_counter();
				cGame::set_start();
			}
			InvalidateRect(hWnd, NULL, false);

		}
			break;
		case 2:
		{
			cGame::update();
			InvalidateRect(hWnd, NULL, false);
		}
			break;
		default:
			break;
		}
	}
		break;
	case WM_CHAR:
	{
		if (ui.get_mode() == mode::main)
		{
			if (wParam == VK_RETURN || wParam == VK_BACK)
			{
				if (ui.get_input(wParam))
					ui.set_mode(mode::game);
			}
			else if(wParam != VK_TAB && wParam != VK_ESCAPE)
				ui.get_input(wParam);
			
			InvalidateRect(hWnd, NULL, false);
		}
	}
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
