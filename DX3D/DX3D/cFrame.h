#pragma once
#include "cMtlTex.h"

class cFrame : public cObject
{
public:
	cFrame();
	~cFrame();
private:
	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matLocalTM, LocalTM);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matWorldTM, WorldTM);

	Synthesize_Add_Ref(cMtlTex*, m_pMtlTex, MtlTex);
	//Synthesize_Pass_by_Ref(vector<cMtlTex*>, m_vecMtlTex, vecMtlTex);
	vector<cFrame*> m_vecChild;


	Synthesize_Pass_by_Ref(vector<ST_POS_SAMPLE>, m_vecPosTrack, PosTrack);
	Synthesize_Pass_by_Ref(vector<ST_ROT_SAMPLE>, m_vecRotTrack, RotTrack);

	DWORD m_dwTicksPerFrame;
	DWORD m_dwFirstFrame;
	DWORD m_dwLastFrame;
	DWORD m_dwFrameSpeed;
public:
	void update(int nKeyFrame, D3DXMATRIXA16* pmatParent);
	void render();
	void AddChild(cFrame* pChild);
	void Destroy();
	void CalcOriginLocalTM(D3DXMATRIXA16* pmatParent);

	int	GetKeyFrame();
	void CalcLocalT(IN int nKeyFrame, OUT D3DXMATRIXA16& matT);
	void CalcLocalR(IN int nKeyFrame, OUT D3DXMATRIXA16& matR);

private:
	int							m_nNumTri;
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9		m_pIB;
	int							m_nAttrID;
	Synthesize(LPD3DXMESH, m_pMesh, Mesh);
public:
	void BuildVB(vector<ST_PNT_VERTEX>& vecVertex);
	void BuildIB(vector<ST_PNT_VERTEX>& vecVertex);
	
};
