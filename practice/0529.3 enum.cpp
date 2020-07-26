#include "stdafx.h"

enum Action {Move, Jump, Attack, Die =999, Death};
// Move = 0, Jump = 1, Attack = 2, Die = 999, Death = 1000
// enum은 상수를 한꺼번에, 순차적으로 선언한 것. 열거형 상수라고 함.
enum {Idle, Run};
// 이름을 안 쓸수도 있음.

int main(int argc, char* argv[])
{

	printf("%d\n", Move);
	char szName[Action::Jump];

	

	return 0;
}