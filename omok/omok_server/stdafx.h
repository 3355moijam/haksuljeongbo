// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <WinSock2.h>
#include <vector>
using std::vector;
using std::wstring;
#pragma comment(lib, "ws2_32.lib")

#define WM_ASYNC WM_USER + 2

#include "cGame_omok_server.h"

// TODO: reference additional headers your program requires here
