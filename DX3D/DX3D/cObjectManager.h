#pragma once
//class cObject;

#define g_pObjectManager cObjectManager::getInstance()
class cObjectManager
{

	Singletone(cObjectManager);

	std::set<cObject*> m_setObject;
	
public:
	void AddObject(cObject* pObject);
	void RemoveObject(cObject* pObject);
	void Destroy();
	
};

