#include "stdafx.h"
#include <vector>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	// 다음 두 동적할당은 같다.
	int *pn1 = (int *)malloc(sizeof(int) * 4);
	//free(pn1);
	delete[] pn1;

	int *pn2 = new int[4];
	//delete[] pn2;	// 주의. new [] 이렇게 배열로 할당했으면 delete[]로 해제해야한다.
	free(pn2);

	_CrtDumpMemoryLeaks();


	return 0;
}
