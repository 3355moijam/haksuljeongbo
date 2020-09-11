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
#include <vector>
#include <string>
using std::vector;
using std::wstring;
using std::string;
#define Tile 16

#define __SLASH(x) /##x
#define __DOUBLE_SLASH __SLASH(/)
#ifdef _DEBUG
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
#include <iostream>
using std::cout;
using std::endl;
#define _D
#define _R __DOUBLE_SLASH
#else
#define _D __DOUBLE_SLASH
#define _R
#endif

#include "Point.h"
#include "FunctionLibrary.h"
#include "interface.h"
//#include "cLoader.h"
//#include "cAnimation.h"
//#include "cCharacter.h"
//#include "cMap.h"
//#include "cUI.h"
//#include "cGameManager.h"

// TODO: reference additional headers your program requires here
