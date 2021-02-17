#pragma once
#include "Framework.h"
#pragma comment(lib, "Framework.lib")




inline Matrix* D3DXMatrixTranslation(Matrix* pOut, Vector3 position)
{
	return D3DXMatrixTranslation(pOut, position.x, position.y, position.z);
}