#pragma once
#include "cMtlTex.h"

class cGroup : public cObject
{
public:
	cGroup();
	~cGroup();
private:
	Synthesize_Pass_by_Ref(vector<ST_PNT_VERTEX>, m_vecVertex, Vertex);
	Synthesize_Add_Ref(cMtlTex*, m_pMtlTex, MtlTex);
public:
	virtual void render();
	
};
