#include "stdafx.h"
#include <time.h>

int main(int argc, char* argv[])
{
	int i = 0;
	srand((unsigned)time(NULL));
	//srand(1);	// �õ尪�� �����̸� �������� ������ ����
	// ������ Ȯ������ �ٸ��� ����Ƚ�� ��í�� ����Ǹ� �ݵ�� �ѹ��� ������ ���α׷��� ����� �Ѵ�.
	// �ڽ���íó�� �������.
	for (i = 0; i < 10; i++)
		printf("%6d\n", rand());

	for (i = 0; i < 10; i++)
		printf("%6d\n", rand() % 10);

	return 0;
}