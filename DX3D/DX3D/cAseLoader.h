#pragma once


class cMtlTex;
class cGroupNode;

class cAseLoader
{
private:
	vector<cMtlTex*> m_vecMtlTex;
public:
	cAseLoader();
	~cAseLoader();
	void Load(vector<cGroupNode*>& vecGroupNode, char* szFolder, char* szFile);

};
