#pragma once
#include "../stdafx.h"

class biTree
{
private:
	class node
	{
	public:
		node(int no, string name = "") : no(no), name(name), left(nullptr), right(nullptr) {}
		node() : no(1), name(""), left(nullptr), right(nullptr) {}
		int no;
		string name;
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
	void push(int no, string name = "");
	void pop(int no);
	node* find(int no);
	void print();
	void print(node* target);
	int get_height(node* target);
	int get_bias(node* target);
	void rebalance(node* target);
};

