#include "stdafx.h"
#pragma pack(push,1)
// 이 사이에 구조체를 넣으면 구조체 멤버맞춤이 꺼짐.
#pragma pack(pop)

struct data 
{
	unsigned char main : 1;
	unsigned char left : 2;		// 8바이트중에 몇바이트만 쓰겠다고 지정해준것
	unsigned char right : 3;	// 임베디드에서나 씀
	unsigned char top : 2;
};
int main(int argc, char* argv[])
{
	// 구조체 멤버 맞춤.
	// 연산속도를 위해 2의 배수로 구조체의 크기를 잘라주는것.
	// 연산속도에 이득이 있으나 용량을 조금 더 먹음.
	// 네트워크 전송시에는 이 기능을 꺼주는게 좋음.





	return 0;
}