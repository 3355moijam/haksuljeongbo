#pragma once

class cMtlParser
{
private:
	vector<string> m_mtlName;
	vector<string> m_textureAddr;
	vector<D3DMATERIAL9> m_mtlList;
	vector<string> oFile;
public:
	cMtlParser();
	cMtlParser(string file);
	~cMtlParser();

	int open(string file);
	void mtlParse();
	D3DMATERIAL9 createMtl(string name, OUT LPDIRECT3DTEXTURE9& texture);
	
};
