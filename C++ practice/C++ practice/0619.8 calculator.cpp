#include "stdafx.h"
#include "StringQueue.h"
#include "StringStack.h"

void inFile(string filename, vector<string> *vec);
void InputSplit(StringQueue*, string);
int OpPrior(string Op);
void InToPost(StringQueue *In, StringQueue *Post, StringStack *Op);
double calculate(StringQueue *Post, StringStack *Op);

int main()
{
	vector<string> sInput;
	string filename = "";
	cout << "파일명 : ";
	getline(cin, filename);
	inFile(filename, &sInput);
	
	StringQueue InputQ; Initialize(&InputQ, 64);
	StringQueue PostQ; Initialize(&PostQ, 64);
	StringStack OpStk; Initialize(&OpStk, 64);

	for (int i = 0; i < sInput.size(); i++)
	{
		InputSplit(&InputQ, sInput[i]);
		//Print(&InputQ);
		//cout << endl;

		InToPost(&InputQ, &PostQ, &OpStk);
		//Print(&PostQ);
		//cout << endl;
		double answer = calculate(&PostQ, &OpStk);
		cout << answer << endl;
		Clear(&InputQ);
		Clear(&PostQ);
		Clear(&OpStk);
	}

	Terminate(&InputQ);
	Terminate(&PostQ);
	Terminate(&OpStk);
	return 0;
}

void InputSplit(StringQueue *In, string input)
{
	string num = "";
	string op = "";
	bool flag = false;

	for (int i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			if (!flag)
				flag = true;
			num.push_back(input[i]);
		}
		else
		{
			if (input[i] == ' ')
				continue;
			else if (input[i] == '.')
			{
				num.push_back(input[i]);
				continue;
			}
			else if (!flag && input[i] == '-')
			{
				string temp = " ";
				Tail(In, &temp);
				if (!(isdigit(temp.back()) || temp == ")"))  // - 앞이 숫자거나, )면 연산기호, 그 외엔 부호
				{
					num.push_back(input[i]);
					continue;
				}
			}

			if (flag)
			{
				Enque(In, num);
				num = "";
				flag = false;
			}
			op.push_back(input[i]);
			Enque(In, op);
			op = "";
		}
	}

	if (flag)
	{
		Enque(In, num);
		num = "";
		flag = false;
	}

}

int OpPrior(string Op)
{
	if (strpbrk(Op.c_str(), "()") != NULL)
		return 1;
	else if (strpbrk(Op.c_str(), "+-") != NULL)
		return 2;
	else if (strpbrk(Op.c_str(), "*/") != NULL)
		return 3;
	else
		return 0;
}

void InToPost(StringQueue *In, StringQueue *Post, StringStack *Op)
{
	string input = " "; // isdigit에서 nullptr에러 때문에 공백문자로 초기화.
	while (!(IsEmpty(In) && IsEmpty(Op)))// q = 0 && stk = =0
	{
		if (!IsEmpty(In))
			Deque(In, &input);
		else
			input = " ";

		if (isdigit(input.back()))
		{
			Enque(Post, input);
		}
		else
		{
			if (input[0] == '(')
			{
				Push(Op, input);
			}
			else if (input[0] == ')')
			{
				string tmp = " ";
				Pop(Op, &tmp);
				while (tmp != "(")
				{
					Enque(Post, tmp);
					Pop(Op, &tmp);
				}
			}
			else
			{
				string tmp = " ";
				Peek(Op, &tmp);
				while (OpPrior(input) <= OpPrior(tmp) && tmp != " ")
				{
					Pop(Op, &tmp);
					Enque(Post, tmp);
					Peek(Op, &tmp);
				}
				if(input != " ")
					Push(Op, input);
			}
		}
	}

	Clear(Op);
}
double calculate(StringQueue *Post, StringStack *Op)
{
	string input = "";
	string tmp = "";
	double a = 0, b = 0, cal = 0;
	while (!IsEmpty(Post))
	{
		Deque(Post, &input);
		if (isdigit(input.back()))
		{
			Push(Op, input);
		}
		else
		{
			Pop(Op, &tmp);
			b = atof(tmp.c_str());
			Pop(Op, &tmp);
			a = atof(tmp.c_str());
			switch (input[0])
			{
			case '+':
				cal = a + b;
				break;
			case '-':
				cal = a - b;
				break;
			case '*':
				cal = a * b;
				break;
			case '/':
				if(b != 0)
					cal = a / b;
				else
				{
					cout << "Error: 0으로 나누기" << endl;
					exit(1);
				}
				break;
			default:
				break;
			}
			tmp = to_string(cal);
			Push(Op, tmp);
			cal = 0; tmp = "";
		}
	}
	Peek(Op, &tmp);
	cal = atof(tmp.c_str());
	return cal;
}


void inFile(string filename, vector<string> *vec)
{
	ifstream fp;
	fp.open(filename);
	if (!fp.is_open())
	{
		cout << filename << " 파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
		exit(EXIT_FAILURE);
	}
	string value = "";
	int count = 0;

	do
	{
		fp >> value;
		++count;
		(*vec).push_back(value);
	} while (fp.good());

	if (fp.eof())
	{//cout << "파일의 끝에 도달했습니다." << endl;
	}
	else if (fp.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다." << endl;
	else
		cout << "알 수 없는 이유로 입력이 종료되었습니다." << endl;

	if (count == 0)
		cout << "데이터가 없습니다." << endl;

	fp.close();
}