#include "stdafx.h"

int main(void)
{
	// ����(OR) ||
	// ����(AND) &&

	//int nInput = 0, bResult = 0;

	//scanf("%d", &nInput);
	//bResult = nInput < 4 || nInput >= 60;
	//printf("Result : %d (1:True, 0:False)\n", bResult);
	////////////////////////////////

	//int nInput = 0, bResult = 0;

	//scanf("%d", &nInput);
	//bResult = nInput > 3 && nInput < 20;
	//printf("Result : %d (1:True, 0:False)\n", bResult);
	////////////////////////////////////

	//int nInput = 0, bResult = 0;

	//scanf("%d", &nInput);
	//bResult = 3 < nInput < 20;  // 3 < nInput�� 0,1�̱� ������ 0,1 < 20�� ������ 1�� ���´�. ����ϸ� �� ��.
	//printf("Result : %d (1:True, 0:False)\n", bResult);
	/////////////////////////////////////////////////////////
	
	// !(����) 0�� 1��, 0�� �ƴѰ� 0����

	int nInput = 0, bResult = 0; 

	scanf("%d", &nInput);
	bResult = !nInput;
	printf("Result : %d (1:True, 0:False)\n", bResult);

	return 0;
}
