#include "stdafx.h"	

#define ADD(a,b)	(a+b)
// 함수가 아니라 매크로. 함수보다 빠름.
// ADD(a,b)가 써진 부분을 (a+b)로 대체해버림.
// (a+b)괄호가 중요한데 저게 없으면 의도한 값이 안나올 수 있다.

// 괄호가 없다면
// ADD(a,b)*c -> a+b*c가 된다. b*c가 먼저 계산됨.

#define STRING(a)	#a		// #은 해당 글자를 문자로 만듦 변수명 등을 출력하기에 편함.
#define PASTER(a,b)	a##b	// ##은 문자 두개를 합쳐서 인자로 묶어줌 nD + ata -> nData

// DEBUG가 정의되어있다면 MESSAGE는 TRUE, 아니면 FALSE가 됨.

#ifdef _DEBUG	// properties에서 확인 가능. 현재 설정은 디버그할때는 _DEBUG, 릴리스할때는 NDEBUG
	#define MESSAGE	"debug"
#elif NDEBUG
	#define MESSAGE	"release"
#endif // DEBUG

// Linux가 정의 되어있다면 전자의 함수, 아니면 후자의 함수가 정의됨.
//#define Linux

#ifdef Linux
	void Menu()
	{
		printf("리눅스");
	}
#else
	void Menu()
	{
		printf("윈도우");
	}
#endif // 


//#define MYUNICODE

#ifdef MYUNICODE
	typedef wchar_t		TCHAR;
	#define _T(string)	L##string
	#define PRINT		wprintf
#else
	typedef char		TCHAR;
	#define _T(string)	string
	#define PRINT		printf
#endif // MYUNICODE


int main(int argc, char* argv[])
{
	TCHAR szData[16] = _T("Test string");
	PRINT(_T("%s\n"), szData);
	PRINT(_T("%d, %d\n"), sizeof(TCHAR), sizeof(szData));

	/*int nData = 10;
	printf("%d %s %s\n", nData, STRING(10), STRING(nData));
	printf("%s = %s\n", STRING(nData), nData);*/

	for (int i = 0; i < 10; i++)
	{
		const int b = i;
		int PASTER(a, i) = 10;
	}


	return 0;
}