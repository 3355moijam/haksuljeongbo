#pragma once

#define g_pSkinnedMeshManager	CSkinnedMeshManager::getInstance()
class CSkinnedMesh;
class CSkinnedMeshManager
{
public:
	Singletone(CSkinnedMeshManager);
private:
	map<string, CSkinnedMesh*> m_mapSkinnedMesh;

public:
	CSkinnedMesh*		GetSkinnedMesh(char* szFolder, char* szFileName);
	void				Destroy();
	
};
