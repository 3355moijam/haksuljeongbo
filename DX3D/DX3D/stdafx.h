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


// TODO: reference additional headers your program requires here
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <map>
using std::map;
#include <set>
using std::set;
#include <list>
using std::list;
#include <assert.h>

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;
#define SafeRelease(p) { if(p) p->Release(); p = NULL; }

#define SafeDelete(p) { if(p) delete p; p = NULL; }

#define Singletone(class_name) \
	private : \
		class_name(void); \
		~class_name(void); \
	public : \
		static class_name& getInstance() \
		{ \
			static class_name instance; \
			return instance; \
		} 

#define ELIPSE 0.000001f

struct ST_PC_VERTEX
{
	D3DXVECTOR3	p;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
	ST_PC_VERTEX() : p(), c(0) {}
	//ST_PC_VERTEX(float _x, float _y, float _z) : p(_x, _y, _x), c(0) {}
	ST_PC_VERTEX(float _x, float _y, float _z, D3DCOLOR _c = 0) : p(_x, _y, _z), c(_c) {}
};

#include "cDeviceManager.h"