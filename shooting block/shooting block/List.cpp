#include "stdafx.h"
#include "List.h"
#include <fstream>
wstring locale = _wsetlocale(LC_ALL, L"");

List::node::node(int no, wstring name) : no(no), name(name), pNext(nullptr), pPrev(nullptr)
{
}

List::node::node(int no, TCHAR name[]) : no(no), name(name), pNext(nullptr), pPrev(nullptr)
{
}

List::node::node() : pNext(nullptr), pPrev(nullptr)
{
}

List::List() : length(0), head(nullptr)
{
}

List::List(int num, wstring name) : length(1)
{
	head = new node(num, name);
}


List::~List()
{
	for(int i = 0; i < length; i++)
	{
		node* temp = head;
		head = head->pNext;
		delete temp;
	}
}

void List::push_index(node * newNode, node* next)
{
	next->pPrev->pNext = newNode;
	newNode->pNext = next;
	newNode->pPrev = next->pPrev;
	next->pPrev = newNode;
	if(next == head && newNode->no <= next->no)
		head = newNode;

	length++;
}

List::node * List::get(int index)
{
	if (length <= index)
		return nullptr;

	List::node* temp = head;
	for (size_t i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}
	return temp;
}

List::node * List::find(int num)
{
	List::node* temp = head;
	int index = length / 2;
	while (index > 0)
	{
		if (temp->no < num)
			for (int i = 0; i < index; i++)
				temp = temp->pNext;
		else if (temp->no > num)
			for (int i = 0; i < index; i++)
				temp = temp->pPrev;
		else
			return temp;

		index /= 2;
	}
	if (temp->no == num)
		return temp;
	else
		return nullptr;


}



void List::push(int num, wstring name)
{
	List::node* newNode = new node(num, name);
	
	List::node* temp = head;
	
	if (temp == nullptr)
	{
		head = newNode;
		newNode->pPrev = newNode;
		newNode->pNext = newNode;
		length++;
	}
	else
	{
		do
		{
			if (temp->no >= num)
			{
				push_index(newNode, temp);
				return;
			}
			temp = temp->pNext;
		}while (temp != head);
		push_index(newNode, temp);
	}
	return;
}

void List::pop(int num)
{
	if (length == 0)
	{
		//cerr << "리스트가 비어있습니다." << endl;
		return;
	}
	List::node* srch = find(num);

	if (srch == nullptr)
	{
		//cerr << "노드를 발견하지 못했습니다." << endl;
		return;
	}
	if (srch == head)
		head = srch->pNext;

	List::node* prev = srch->pPrev;
	prev->pNext = srch->pNext;
	srch->pNext->pPrev = prev;
	delete srch;
	length--;
	if (!length)
		head = nullptr;
}

void List::pop(node* srch)
{
	if (length == 0)
	{
		//cerr << "리스트가 비어있습니다." << endl;
		return;
	}

	if (srch == nullptr)
	{
		//cerr << "노드를 발견하지 못했습니다." << endl;
		return;
	}

	if (srch == head)
		head = srch->pNext;

	List::node* prev = srch->pPrev;
	prev->pNext = srch->pNext;
	srch->pNext->pPrev = prev;
	delete srch;
	length--;
	if (!length)
		head = nullptr;
}

void List::print(wstring & output)
{
	List::node* temp = head;
	for (int i = 0; i < length; i++)
	{
		//cout << "번호: " << temp->no << "\t" << "이름: " << temp->name << endl;
		output += _T("ID : ") + temp->name + _T("  Score :") + to_wstring(temp->no) + _T("\r\n");
		temp = temp->pNext;
	}
}

void List::print_5(wstring & output)
{
	List::node* temp = head->pPrev;
	for (int i = 0; i < (length < 5 ? length : 5); i++)
	{
		//cout << "번호: " << temp->no << "\t" << "이름: " << temp->name << endl;
		output += _T("ID : ") + temp->name + _T("  Score :") + to_wstring(temp->no) + _T("\r\n");
		temp = temp->pPrev;
	}
}

void List::printNode(node * node, wstring & output)
{
	if (node == nullptr)
	{
		//cerr << "노드를 발견하지 못했습니다." << endl;
		return;
	}
	//cout << "번호: " << node->no << "\t" << "이름: " << node->name << endl;
	output += _T("ID : ") + node->name + _T("  Score :") + to_wstring(node->no) + _T("\r\n");
}


void List::read_file()
{
	using std::ifstream;
	ifstream fin("ranking", ios_base::in | ios_base::binary);
	int get = 0;
	TCHAR sget[9];
	while (fin.read(reinterpret_cast<char*> (&get), sizeof(int)))
	{
		fin.read(reinterpret_cast<char*> (sget), 18);
		this->push(get, sget);
	}
	
	fin.clear();
	fin.close();
}

void List::write_file()
{
	using std::ofstream;
	ofstream fout("ranking", ios_base::out | ios_base::trunc | ios_base::binary);
	node* output = head->pPrev;
	for (int i = 0; i < (length < 5 ? length : 5); i++)
	{
		fout.write(reinterpret_cast<char*> (&output->no), sizeof(int));
		fout.write((char*) (output->name.c_str()), 18);
		output = output->pPrev;
	}
	fout.close();
}


