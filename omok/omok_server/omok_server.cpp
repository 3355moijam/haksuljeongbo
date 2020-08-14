// omok_server.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "omok_server.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_OMOK_SERVER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OMOK_SERVER));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OMOK_SERVER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OMOK_SERVER);
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
WSADATA wsadata;
SOCKET s;
vector<SOCKET> cs;

vector<wstring>chatLog;
wstring inputmsg;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static TCHAR msg[BUFSIZ];
	// ≈∏¿Ã«Œ
	static TCHAR str[BUFSIZ];
	static SOCKADDR_IN addr = { 0 }, c_addr;
	static int count;// , cur_line = 0;
	int size, msgLen;
	char buffer[BUFSIZ];
	
    switch (message)
    {
	case WM_CREATE:
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
		
		WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_ACCEPT);
		if (listen(s, 5) == SOCKET_ERROR)
		{
			MessageBox(NULL, _T("listen failed"), _T("Error"), MB_OK);
			return 0;
		}

		break;
	case WM_ASYNC:
		switch (lParam)
		{
		case FD_ACCEPT:
			size = sizeof(c_addr);
			//MessageBox(NULL, _T("fdread ready"), _T("fdread"), MB_OK);
			cs.push_back(accept(s, (LPSOCKADDR)& c_addr, &size));
			WSAAsyncSelect(cs.back(), hWnd, WM_ASYNC, FD_READ);
			break;
		case FD_READ:
			msgLen = recv(wParam, buffer, BUFSIZ, 0);
			buffer[msgLen] = NULL;
#ifdef _UNICODE
			msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
			MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
			msg[msgLen] = NULL;
#else
			strcpy_s(msg, buffer);
#endif
			InvalidateRect(hWnd, NULL, true);
			break;
		case FD_CLOSE:
		{
			for (size_t i = 0; i < cs.size(); i++)
			{
				if (cs[i] == wParam)
				{
					cs.erase(cs.begin() + i);
					break;
				}
			}
		}
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
			/*
			// TODO: Add any drawing code that uses hdc here...
			if (_tcscmp(msg, _T("")))
			{
				wstring msgTemp = msg;
				addLog(chatLog, msgTemp);
				//TextOut(hdc, 0, cur_line, msg, (int)_tcslen(msg));
				//cur_line += 30;
				memset(msg, 0, _tcslen(msg));
			}
			if (inputmsg != _T(""))
			{
				addLog(chatLog, inputmsg);
				//TextOut(hdc, 0, cur_line, inputmsg, (int)_tcslen(inputmsg));
				//cur_line += 30;
				inputmsg = _T("");
			}
			//TextOut(hdc, 0, 600, str, _tcslen(str));
			for (int i = 0, cur_line = 0; i < chatLog.size(); i++, cur_line += 30)
			{
				TextOut(hdc, 0, cur_line, chatLog[i].c_str(), (int)_tcslen(chatLog[i].c_str()));
			}
			DrawText(hdc, str, _tcslen(str), &typeWrite, DT_LEFT);
			*/
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CHAR:
		/*
		if (wParam == VK_RETURN)
		{
			{
#ifdef _UNICODE
				msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
				WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
#else
				strcpy_s(buffer, str);
#endif
				for(int i = 0; i < cs.size(); i++)
					send(cs[i], (LPSTR)buffer, strlen(buffer) + 1, 0);
				
				count = 0;
				//return 0;

				inputmsg = str;
			}
			str[0] = NULL;
		}
		else
		{
			str[count++] = wParam;
			str[count] = NULL;
		}
		*/
	
		InvalidateRect(hWnd, NULL, true); 
		break;
    case WM_DESTROY:
		closesocket(s);
		WSACleanup();
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
