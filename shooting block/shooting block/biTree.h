#pragma once
#include "stdafx.h"

class biTree
{
private:
	class node
	{
	public:
		node(int no, wstring name = _T("")) : no(no), name(name), left(nullptr), right(nullptr) {}
		node() : no(1), name(_T("")), left(nullptr), right(nullptr) {}
		int no;
		wstring name;
		node* left;
		node* right;
	};
	int length;
	node* root;
	node* find_parent(int no);
	node* find_parent(node* target);
public:
	biTree() : length(0), root(nullptr) {}
	~biTree();
	void push(int no, wstring name = _T(""));
	void pop(int no);
	void pop(node* target);
	node* find(int no);
	void print(wstring & output);
	void print(node* target, wstring & output);

	node* find_most_left();
	node* find_most_right();

	void read_file();
	void write_file();
};

