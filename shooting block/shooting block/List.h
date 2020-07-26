#pragma once
#include "stdafx.h"

class List
{
private:
	class node
	{
	public:
		node(int no, wstring name);
		node(int no, TCHAR name[]);
		node();
		int no;
		wstring name;
		node* pNext;
		node* pPrev;
	};
	int length;
	node* head;
	void push_index(node* newNode, node* next);
public:
	List();
	List(int num, wstring name);
	~List();

	node* get(int index);
	node* find(int num);
	int size() { return length; }
	void push(int num, wstring name);
	void pop(int num);
	void pop(node* srch);
	void print(wstring & output);
	void print_5(wstring & output);
	void printNode(node* node, wstring & output);

	void read_file();
	void write_file();
};

