#include "stdafx.h"

int main(void)
{
	// 논리합(OR) ||
	// 논리곱(AND) &&

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
	//bResult = 3 < nInput < 20;  // 3 < nInput이 0,1이기 때문에 0,1 < 20은 무조건 1이 나온다. 사용하면 안 됨.
	//printf("Result : %d (1:True, 0:False)\n", bResult);
	/////////////////////////////////////////////////////////
	
	// !(부정) 0은 1로, 0이 아닌건 0으로

	int nInput = 0, bResult = 0; 

	scanf("%d", &nInput);
	bResult = !nInput;
	printf("Result : %d (1:True, 0:False)\n", bResult);

	return 0;
}
