#include "stdafx.h"	

#define ADD(a,b)	(a+b)
// �Լ��� �ƴ϶� ��ũ��. �Լ����� ����.
// ADD(a,b)�� ���� �κ��� (a+b)�� ��ü�ع���.
// (a+b)��ȣ�� �߿��ѵ� ���� ������ �ǵ��� ���� �ȳ��� �� �ִ�.

// ��ȣ�� ���ٸ�
// ADD(a,b)*c -> a+b*c�� �ȴ�. b*c�� ���� ����.

#define STRING(a)	#a		// #�� �ش� ���ڸ� ���ڷ� ���� ������ ���� ����ϱ⿡ ����.
#define PASTER(a,b)	a##b	// ##�� ���� �ΰ��� ���ļ� ���ڷ� ������ nD + ata -> nData

// DEBUG�� ���ǵǾ��ִٸ� MESSAGE�� TRUE, �ƴϸ� FALSE�� ��.

#ifdef _DEBUG	// properties���� Ȯ�� ����. ���� ������ ������Ҷ��� _DEBUG, �������Ҷ��� NDEBUG
	#define MESSAGE	"debug"
#elif NDEBUG
	#define MESSAGE	"release"
#endif // DEBUG

// Linux�� ���� �Ǿ��ִٸ� ������ �Լ�, �ƴϸ� ������ �Լ��� ���ǵ�.
//#define Linux

#ifdef Linux
	void Menu()
	{
		printf("������");
	}
#else
	void Menu()
	{
		printf("������");
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