#pragma once
#include "../stdafx.h"
class AVL
{
private:
	class node
	{
	public:
		node(int no, string name = "") : no(no), name(name), left(nullptr), right(nullptr), parent(nullptr) {}
		node() : no(1), name(""), left(nullptr), right(nullptr), parent(nullptr) {}
		int no;
		string name;
		node* left;
		node* right;
		node* parent;
		void copy(node* target)
		{
			no = target->no;
			name = target->name;
			left = target->left;
			right = target->right;
			parent = target->parent;
		}
		void swap(node* target);
	};
	int length;
	node* root;
	void left_rotate(node* target);
	void right_rotate(node* target);
public:
	AVL() : length(0), root(nullptr) {}
	~AVL();
	void push(int no, string name = "");
	void pop(int no);
	void pop(node* target);
	node* find(int no);
	void print();
	void print(node* target);
	void printTree();
	void printTree(node* target);
	int get_height(node* target);
	int get_depth(node* target);
	int get_bias(node* target);
	void rebalance(node* target);
};

