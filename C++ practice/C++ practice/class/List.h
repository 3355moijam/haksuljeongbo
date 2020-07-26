#pragma once
#include "../stdafx.h"

class List
{
private:
	class node
	{
	public:
		node(int no, string name);
		node();
		int no;
		string name;
		node* pNext;
		node* pPrev;
	};
	int length;
	node* head;
	void push_index(node* newNode, node* next);
public:
	List();
	List(int num, string name);
	~List();

	node* get(int index);
	node* find(int num);
	int size() { return length; }
	void push(int num, string name);
	void pop(int num);
	void print();
	void printNode(node* node);
};

