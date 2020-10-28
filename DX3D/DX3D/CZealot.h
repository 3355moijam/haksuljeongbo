#pragma once
#include "cCharacter.h"

class CSkinnedMesh;
class COBB;

class CZealot
{
public:
	CZealot();
	virtual ~CZealot();

private:
	CSkinnedMesh*	m_pSkinnedMesh;
	COBB*			m_pOBB;
	Synthesize_Add_Ref(cCharacter*, m_pCharacterController, CharacterController);

public:
	void Setup();
	void Update(iMap* pMap);
	void Render(D3DXCOLOR c = D3DCOLOR_XRGB(255, 255, 255));

	COBB* GetOBB();
	
};
