#pragma once

class cFieldMap : public iMap
{
public:
	cFieldMap();
	~cFieldMap() override;
	
	bool GetHeight(float x, float& y, float z) override;
private:
	int			m_nWidthSpace;
	int			m_nDepthSpace;
	int			m_nNumVertexWidth;
	int			m_nNumVertexDepth;
	int			m_nWidth;
	int			m_nDepth;
	
	vector<ST_PNT_VERTEX>		m_vecVertex;
	vector<DWORD>				m_vecIndex;
	IDirect3DVertexBuffer9*		m_pVertexBuffer;
	IDirect3DIndexBuffer9*		m_pIndexBuffer;
	LPD3DXMESH					m_pMesh;
	LPDIRECT3DTEXTURE9			m_pTexture;

	vector<vector<int>>			m_vecHeightMap;
	D3DMATERIAL9				m_stMtl;
public:
	void createMap(vector<int>& vecHeightMap, float fHeightMultiply, int nNumVertexWidth, int nNumVertexDepth, int nWidthSpace, int
	               nDepthSpace, LPDIRECT3DTEXTURE9 pTexture);
	void render();
};
