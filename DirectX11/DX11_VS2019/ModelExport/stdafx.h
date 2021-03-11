#pragma once
#include "Framework.h"
#pragma comment(lib, "Framework.lib")

#include "Assimp/Importer.hpp"
#include "Assimp/scene.h"
#include "Assimp/postprocess.h"
#pragma comment(lib, "Assimp/assimp-vc140-mt.lib")


inline Matrix* D3DXMatrixTranslation(Matrix* pOut, Vector3 position)
{
	return D3DXMatrixTranslation(pOut, position.x, position.y, position.z);
}