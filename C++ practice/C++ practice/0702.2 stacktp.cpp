#include "stdafx.h"
#include "class\stacktp.h"
#include <cctype>

int main()
{
	Stack<int> st;
	char ch;
	int po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
		<< "종료하려면 Q를 입력하십시오.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "추가할 주문서의 번호를 입력하십시오: ";
			cin >> po;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "스택이 비어있습니다.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " 주문서르르 처리했습니다.\n";
			}
			break;
		default:
			break;
		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
			<< "종료하려면 Q를 입력하십시오.\n";
	}
	cout << "프로그램을 종료합니다.\n";
}
