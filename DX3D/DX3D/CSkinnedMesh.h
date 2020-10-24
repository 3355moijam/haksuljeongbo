#pragma once

class CSkinnedMesh
{
public:
	CSkinnedMesh();
	~CSkinnedMesh();
protected:
	LPD3DXFRAME		m_pRoot;
	LPD3DXANIMATIONCONTROLLER		m_pAnimController;

	float			m_fBlendTime;
	float			m_fPassedBlendTime;
	bool			m_isAnimBlend;
	double			m_dAnimPeriod;
	float			m_fAnimTime;
	bool			m_isInputOn;

	enum AnimSet { ATK01, ATK02, ATK03, RUN, IDLE };
public:
	void setup(char* szFolder, char* szFile);
	void update();
	void update(LPD3DXFRAME pFrame, LPD3DXFRAME pParent);
	void render(LPD3DXFRAME pFrame);
	void SetupBoneMatrixPtrs(LPD3DXFRAME pFrame);
	void UpdateSkinnedMesh(LPD3DXFRAME pFrame);

	void SetAnimationIndex(int nIndex);
	void SetAnimationIndexBlend(int nIndex);
};
