#include "stdafx.h"

int main(void)
{

	// realloc(�ּ�, ���Ҵ��� ũ��). ���� ���ɼ��� �����Ƿ� if�� üũ���ٰ�.
	// sprintf ȭ���� �ƴ϶� �޸𸮿� ���. �޸𸮿� ������ ��
	// ���ȹ����� sprintf_s�� ����.
	// sprintf_s(Ÿ���ּ�, �޸𸮻�����(_msize, ��������), "����� �޽���", ����);

	char *pszBuffer = NULL, *pszNewBuffer = NULL;

	pszBuffer = (char*)malloc(12);
	sprintf(pszBuffer, "%s", "TestString");
	printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);

	pszNewBuffer = (char*)realloc(pszBuffer, 32);	// pszBuffer�� ������ Ȯ���ؼ� pszNewBuffer�� �Ҵ�. ���� ���� ���� �ּҸ� ����.
	if (pszNewBuffer == NULL)	// ���� �Ҵ翡 �������� ���
		free(pszBuffer);
	
	sprintf(pszNewBuffer, "%s", "TestStringData");
	printf("[%p] %d %s\n", pszNewBuffer, _msize(pszNewBuffer), pszNewBuffer);

	free(pszNewBuffer);



	return 0;
}