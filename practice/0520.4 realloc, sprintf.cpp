#include "stdafx.h"

int main(void)
{

	// realloc(주소, 재할당할 크기). 실패 가능성이 있으므로 if로 체크해줄것.
	// sprintf 화면이 아니라 메모리에 출력. 메모리에 저장해 줌
	// 보안문제로 sprintf_s를 쓴다.
	// sprintf_s(타겟주소, 메모리사이즈(_msize, 생략가능), "출력할 메시지", 인자);

	char *pszBuffer = NULL, *pszNewBuffer = NULL;

	pszBuffer = (char*)malloc(12);
	sprintf(pszBuffer, "%s", "TestString");
	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char*)realloc(pszBuffer, 32);	// pszBuffer의 공간을 확장해서 pszNewBuffer에 할당. 둘은 이제 같은 주소를 가짐.
	if (pszNewBuffer == NULL)	// 공간 할당에 실패했을 경우
		free(pszBuffer);
	
	sprintf(pszNewBuffer, "%s", "TestStringData");
	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);

	free(pszNewBuffer);



	return 0;
}