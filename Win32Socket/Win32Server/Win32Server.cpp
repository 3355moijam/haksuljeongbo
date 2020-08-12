// Win32Server.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "Win32Server.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define WM_ASYNC	WM_USER+2

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

void addLog(TCHAR **chatLog, TCHAR *chat);
int WinServer(WSADATA &wsadata, SOCKET &s, SOCKET &cs, TCHAR *message, SOCKADDR_IN &addr, SOCKADDR_IN &c_addr);

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
    LoadStringW(hInstance, IDC_WIN32SERVER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32SERVER));

	//return WinServer();
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



int WinServer()
{
	//WSADATA wsadata;
	//SOCKET s, cs;
	//TCHAR message[100];
	//SOCKADDR_IN addr = { 0 }, c_addr;
	
		
	
	//closesocket(s);
	//WSACleanup();
	return 1;

	//return 0;
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32SERVER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32SERVER);
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
	static WSADATA wsadata;
	static SOCKET s, cs;
	static TCHAR msg[100];
	// 타이핑
	static TCHAR str[100];
	static SOCKADDR_IN addr = { 0 }, c_addr;
	static int count;// , cur_line = 0;
	int size, msgLen;
	char buffer[100];
	static RECT typeWrite = { 0, 600, 200, 620 };
	static TCHAR **chatLog;
	static TCHAR inputmsg[100];
    switch (message)
    {
	case WM_CREATE:
		//WinServer(wsadata, s, cs, msg, addr, c_addr);
		chatLog = new TCHAR*[10];
		for (size_t i = 0; i < 10; i++)
		{
			chatLog[i] = new TCHAR[100]();
		}
		WSAStartup(MAKEWORD(2, 2), &wsadata);
		s = socket(AF_INET, SOCK_STREAM, 0);
		addr.sin_family = AF_INET;
		addr.sin_port = 20;
		addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		//bind(s, (LPSOCKADDR)&addr, sizeof(addr));
		if (bind(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
		{
			MessageBox(NULL, _T("binding failed"), _T("Error"), MB_OK);
			return 0;
		}
		else
		{
			MessageBox(NULL, _T("binding success"), _T("Success"), MB_OK);
		}
		WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_ACCEPT);
		if (listen(s, 5) == SOCKET_ERROR)
		{
			MessageBox(NULL, _T("listen failed"), _T("Error"), MB_OK);
			return 0;
		}
		else
		{
			MessageBox(NULL, _T("listen success"), _T("Success"), MB_OK);
		}
		break;
	case WM_ASYNC:
		switch (lParam)
		{
		case FD_ACCEPT:
			size = sizeof(c_addr);
			//MessageBox(NULL, _T("fdread ready"), _T("fdread"), MB_OK);
			cs = accept(s, (LPSOCKADDR)& c_addr, &size);
			WSAAsyncSelect(cs, hWnd, WM_ASYNC, FD_READ);
			break;
		case FD_READ:
			msgLen = recv(cs, buffer, 100, 0);
			buffer[msgLen] = NULL;

#ifdef _UNICODE
			//TCHAR wbuffer[200];
			msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
			MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
			msg[msgLen] = NULL;
			//_stprintf_s(message, _T("클라이언트 메시지: %s, 서버를 종료하시겠습니까?"), wbuffer);
#else
			//sprintf_s(message, _T("클라이언트 메시지: %s, 서버를 종료하시겠습니까?"), buffer);
			strcpy_s(msg, buffer);
#endif
			InvalidateRect(hWnd, NULL, true);
			break;
		default:
			break;
		}
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
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			
            // TODO: Add any drawing code that uses hdc here...
			if (_tcscmp(msg, _T("")))
			{
				addLog(chatLog, msg);
				//TextOut(hdc, 0, cur_line, msg, (int)_tcslen(msg));
				//cur_line += 30;
				memset(msg, 0, _tcslen(msg));
			}
			if (_tcscmp(inputmsg, _T("")))
			{
				addLog(chatLog, inputmsg);
				//TextOut(hdc, 0, cur_line, inputmsg, (int)_tcslen(inputmsg));
				//cur_line += 30;
				memset(inputmsg, 0, _tcslen(inputmsg));
			}
			//TextOut(hdc, 0, 600, str, _tcslen(str));
			for (int i = 0, cur_line = 0 ; i < 10; i++, cur_line += 30)
			{
				TextOut(hdc, 0, cur_line, chatLog[i], (int)_tcslen(chatLog[i]));
			}
			DrawText(hdc, str, _tcslen(str), &typeWrite, DT_LEFT);
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CHAR:
		if (wParam == VK_RETURN)
		{	if (cs == INVALID_SOCKET)
				return 0;
			else
			{
#ifdef _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy_s(buffer, str);
#endif
				send(cs, (LPSTR)buffer, strlen(buffer) + 1, 0);
				count = 0;
				//return 0;

				memcpy(inputmsg, str, sizeof(TCHAR) * 100);
			}
			str[0] = NULL;
		}
		else 
		{
			str[count++] = wParam;
			str[count] = NULL;
		}
			InvalidateRect(hWnd, NULL, true);
		break;
    case WM_DESTROY:
		closesocket(s);
		WSACleanup();
		for (size_t i = 0; i < 10; i++)
		{
			delete[] chatLog[i];
		}
		delete[] chatLog;
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

void addLog(TCHAR **chatLog, TCHAR *chat)
{
	for (size_t i = 1; i < 10; i++)
	{
		memcpy(chatLog[i - 1], chatLog[i], sizeof(TCHAR) * 100);
	}
	memcpy(chatLog[9], chat, sizeof(TCHAR) * 100);
}