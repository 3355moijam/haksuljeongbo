#include "stdafx.h"

int main(void)
{
	// 조건연산자(삼항연산자) C언어 유일의 삼항연산자.
	
	//int nInput = 0, nSelect = 0;
	//scanf("%d", &nInput);

	//nSelect = nInput <= 10 ? 10 : 20; // 조건이 참이면 10, 거짓이면 20
	//printf("%d\n", nSelect);
	/////////////////////////////////

	int nInput = 0, nSelect = 0;
	scanf("%d", &nInput);

	nInput <= 10 ? nSelect = 10 : nSelect = 20; // cpp에선 작동을 하지만 c에선 작동하지 않음. 그러나 괄호를 치는 편이 안전한다.
	printf("%d\n", nSelect);

	nInput <= 10 ? (nSelect = 10) : (nSelect = 20); // 올바른 코드. 이렇게 조건 결과에 코드블럭을 넣을 수도 있다. 괄호 꼭 치기
	printf("%d\n", nSelect);

	return 0;
}
