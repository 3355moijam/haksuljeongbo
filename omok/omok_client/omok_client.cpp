// omok_client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "omok_client.h"


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
RECT g_view;
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
    LoadStringW(hInstance, IDC_OMOK_CLIENT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OMOK_CLIENT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OMOK_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OMOK_CLIENT);
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
vector<wstring>chatLog;
wstring inputmsg;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR msg[BUFSIZ];
    // 타이핑
    static TCHAR str[BUFSIZ];
    static SOCKADDR_IN addr = { 0 }, c_addr;
    int size, msgLen;
    char buffer[BUFSIZ];
    cGame_omok& omok = cGame_omok::GetInstance();
    switch (message)
    {
	case WM_CREATE:
		GetClientRect(hWnd, &g_view);

        WSAStartup(MAKEWORD(2, 2), &wsadata);
        s = socket(AF_INET, SOCK_STREAM, 0);
        if (s == INVALID_SOCKET)
        {
            MessageBox(NULL, _T("socket failed"), _T("Error"), MB_OK);
            return 0;
        }


        addr.sin_family = AF_INET;
        addr.sin_port = 20;
        addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_READ);
        connect(s, (LPSOCKADDR)&addr, sizeof(addr)); // 비동기일 경우엔 체크안해도 됨.

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
		BackBit = CreateCompatibleBitmap(hdc, g_view.right, g_view.bottom);
		OldBit = (HBITMAP)SelectObject(hMemDC, BackBit);
		PatBlt(hMemDC, 0, 0, g_view.right, g_view.bottom, WHITENESS);


		cGame_omok::GetInstance().show(hMemDC);


		BitBlt(hdc, 0, 0, g_view.right, g_view.bottom, hMemDC, 0, 0, SRCCOPY);
		DeleteObject(SelectObject(hMemDC, OldBit));
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);
        }
        break;
	case WM_SIZE:
		GetClientRect(hWnd, &g_view);
		break;
    case WM_LBUTTONDOWN:
        if (omok.PutStone(LOWORD(lParam), HIWORD(lParam), omok.getType()))
        {
            if (s == INVALID_SOCKET)
                return 0;
            else
            {
                omok_playlog playlog = omok.getPlayLog(LOWORD(lParam), HIWORD(lParam));
                // 서버에 메시지 보내기
                memset(buffer, 0, BUFSIZ);
                memcpy_s(buffer, BUFSIZ, "1\0", 2);
                memcpy_s(buffer + 2, BUFSIZ - 2, (char*)&playlog, sizeof(playlog));
                send(s, (LPSTR)buffer, BUFSIZ, 0);
            }
            InvalidateRect(hWnd, NULL, false);
        }
        break;
    case WM_ASYNC:
        switch (lParam)
        {
        case FD_READ:
        {
            msgLen = recv(wParam, buffer, BUFSIZ, 0);
            //buffer[msgLen] = NULL;
#ifdef _UNICODE
            msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
            MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
            msg[msgLen] = NULL;
#else
            strcpy_s(msg, buffer);
#endif
            if (buffer[0] == '0')
            {
                omok_initialize init;
                memcpy(&init, buffer + 2, sizeof(omok_initialize));
                omok.setInit(init);
            }
            else if (buffer[0] == '1')
            {
                omok_playlog playlog;
                memcpy(&playlog, buffer + 2, sizeof(omok_playlog));
                omok.setPlayLog(playlog);
            }
            else if (buffer[0] == '2')
            {

            }
            else if (buffer[0] == '3')
            {
                omok_gameend end;
                memcpy(&end, buffer + 2, sizeof(omok_gameend));
                omok.PutStone(end.index, end.winner);
                if (omok.GameOver(end.winner) == IDOK)
                    DestroyWindow(hWnd);
            }
        }
        InvalidateRect(hWnd, NULL, false);
            break;
        default:
            break;
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
