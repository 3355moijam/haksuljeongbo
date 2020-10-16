#pragma once

class cMtlTex;
class cGroup;

class cObjectLoader
{
public:
	cObjectLoader();
	virtual ~cObjectLoader();
protected:
	std::map<string, cMtlTex*> m_mapMtlTex;
public:
	virtual void Load(OUT vector<cGroup*> & vecGroup, IN char* szFolder, IN char* szFile);
	virtual void LoadMtlLib(char* szFolder, char* szFile);

	virtual void LoadSurface(OUT vector<D3DXVECTOR3>& vecSurface, IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat = nullptr);

	LPD3DXMESH LoadMesh(OUT vector<cMtlTex*> & vecMtlTex, IN char* szFolder, IN char* szFile);
};
