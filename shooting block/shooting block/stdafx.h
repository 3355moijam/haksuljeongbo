// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string>	
#include <tchar.h>
#include <vector>

using std::wstring;
using std::to_wstring;
using std::vector;
using std::wifstream;
using std::wofstream;
using std::ios_base;


#include "FunctionLibrary.h"
#include "List.h"
#include "cGame.h"
#include "cUI.h"
// TODO: reference additional headers your program requires here
