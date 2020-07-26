// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
// TODO: reference additional headers your program requires here

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>


#include "item.h"
#include "system.h"
#include "print.h"

#define _HEIGHT 30
#define _WIDTH 128

enum { FAIL, SUCCESS, CLEAR, BREAK };
enum { HOME, MENU, INVEN, ROOMSCAN, OBJ, PUZZLE, OBJ_ITEM, EXIT = 100 };  //, EXIT = 100, EXIT_ITEM 

extern int nLoop;


