#pragma once

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

#include "FunctionLibrary.h"
#include "omok_dll.h"