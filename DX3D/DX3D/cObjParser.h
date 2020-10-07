#pragma once
using std::wstring;

class cObjParser
{
private:
	vector<string> oFile;
	vector<ST_PNT_VERTEX> m_vecVertex;

	D3DMATERIAL9 m_stMtl;
	LPDIRECT3DTEXTURE9 m_pTexture;

	string m_sGroupID	;
	string m_sRoot;
	
public:
	cObjParser();
	cObjParser(string file);
	~cObjParser();

	int open(string file);
	void setRoot(string root) { m_sRoot = root; }
	void objParse();
	void createObj(vector<ST_PNT_VERTEX>& vertex, D3DMATERIAL9* mtl, LPDIRECT3DTEXTURE9& texture);
};
	
