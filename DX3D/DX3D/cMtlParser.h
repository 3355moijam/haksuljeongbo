#pragma once

class cMtlParser
{
private:
	vector<string> m_mtlName;
	vector<string> m_textureAddr;
	vector<D3DMATERIAL9> m_mtlList;
	vector<string> oFile;

	string m_sRoot;
public:
	cMtlParser();
	cMtlParser(string file);
	~cMtlParser();

	int open(string file);
	void setRoot(string root) { m_sRoot = root; }
	void mtlParse();
	D3DMATERIAL9 createMtl(string name, OUT LPDIRECT3DTEXTURE9& texture);
	
};
