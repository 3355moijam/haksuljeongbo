#pragma once
#include "cGroup.h"

class cGroupNode : public cGroup
{
private:
	vector<cGroupNode*> children;
protected:
	float			m_fRotX;
	
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matWorldTM, WorldTM);
	Synthesize_Pass_by_Ref(D3DXMATRIXA16, m_matLocalTM, LocalTM);
	Synthesize_Pass_by_Ref(string, m_sName, Name);
	
	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltaX, RotDeltaX);
public:
	cGroupNode();
	void AddChild(cGroupNode* pChild) { children.push_back(pChild); }
	void render() override;
};
