#include "stdafx.h"

int main(void)
{
	// ���ǿ�����(���׿�����) C��� ������ ���׿�����.
	
	//int nInput = 0, nSelect = 0;
	//scanf("%d", &nInput);

	//nSelect = nInput <= 10 ? 10 : 20; // ������ ���̸� 10, �����̸� 20
	//printf("%d\n", nSelect);
	/////////////////////////////////

	int nInput = 0, nSelect = 0;
	scanf("%d", &nInput);

	nInput <= 10 ? nSelect = 10 : nSelect = 20; // cpp���� �۵��� ������ c���� �۵����� ����. �׷��� ��ȣ�� ġ�� ���� �����Ѵ�.
	printf("%d\n", nSelect);

	nInput <= 10 ? (nSelect = 10) : (nSelect = 20); // �ùٸ� �ڵ�. �̷��� ���� ����� �ڵ���� ���� ���� �ִ�. ��ȣ �� ġ��
	printf("%d\n", nSelect);

	return 0;
}
