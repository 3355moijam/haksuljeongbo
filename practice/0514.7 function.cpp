#include "stdafx.h"

int getResult(void);
char getGrade(int nScore);

int main(void)
{
	// 함수. main 함수 앞에 정의하던지, 뒤에 정의하고 main 앞에서 선언해두던지
	int nResult = 0;

	nResult = getResult();
	printf("당신의 학점은 '%c'(%d)입니다.\n", getGrade(nResult), nResult);


	return 0;
}

int getResult(void) // 매개변수로 들어온 변수랑 같은 이름으로는 재선언이 불가능.
{
	int nResult = 0;  // 이 안에서 선언한 변수는 지역변수로, 이 밖을 빠져나가지 못한다.
	printf("성적(0~100)을 입력하세요. : ");
	scanf("%d%*C", &nResult);
	
	return nResult;
}

char getGrade(int nScore)
{
	if (nScore >= 90) return 'A';
	else if (nScore >= 80) return 'B';
	else if (nScore >= 70) return 'C';
	else if (nScore >= 60) return 'D';
	else return 'F';
}