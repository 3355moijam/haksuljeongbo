#include "stdafx.h"

enum Action {Move, Jump, Attack, Die =999, Death};
// Move = 0, Jump = 1, Attack = 2, Die = 999, Death = 1000
// enum�� ����� �Ѳ�����, ���������� ������ ��. ������ ������ ��.
enum {Idle, Run};
// �̸��� �� ������ ����.

int main(int argc, char* argv[])
{

	printf("%d\n", Move);
	char szName[Action::Jump];

	

	return 0;
}