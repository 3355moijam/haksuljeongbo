#include "biTree.h"
#include <fstream>



void biTree::push(int no, wstring name)
{
	node* newNode = new node(no, name);
	node* temp = root;
	length++;
	if (root == nullptr)
	{
		root = newNode;
		return;
	}
	while (1)
	{
		if (no >= temp->no)
		{
			if (temp->left == nullptr)
			{
				temp->left = newNode;
				return;
			}
			else
			{
				temp = temp->left;
			}
		}
		else
		{
			if (temp->right == nullptr)
			{
				temp->right = newNode;
				return;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
}

void biTree::pop(int no)
{
	node* target;
	if ((target = find(no)) == nullptr)
		return;
	node* parent = find_parent(target);
	
	if (target->left == nullptr && target->right == nullptr)
	{
		// 자식이 없음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				parent->left = nullptr;
				delete target;
			}
			else
			{
				parent->right = nullptr;
				delete target;
			}
		}
		else
		{
			delete target;
			root = nullptr;
		}
	}
	else if (target->left != nullptr && target->right != nullptr)
	{
		// 자식이 양쪽 다 있음.
		node* temp = target->left;
		while (temp->right != nullptr)
			temp = temp->right;

		node* tempParent = find_parent(temp);

		if (tempParent == target)
		{
			temp->right = target->right;
			if(parent == nullptr)
				root = temp;
			else
				parent->left = temp;

			delete target;
		}
		else
		{
			tempParent->right = temp->left;
			temp->left = nullptr;

			if (parent != nullptr)
			{
				if (parent->left == target)
					parent->left = temp;
				else
					parent->right = temp;
			}
			else
			{
				root = temp;
			}

			temp->left = target->left;
			temp->right = target->right;

			delete target;
		}
	}
	else
	{
		// 자식이 한쪽만 있음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				if (target->left != nullptr)
					parent->left = target->left;
				else
					parent->left = target->right;
				delete target;
			}
			else
			{
				if (target->left != nullptr)
					parent->right = target->left;
				else
					parent->right = target->right;
				delete target;
			}
		}
		else
		{
			if (target->left != nullptr)
				root = target->left;
			else
				root = target->right;
			delete target;
		}
	}
	length--;
}

void biTree::pop(node * target)
{
	if (target == nullptr)
		return;
	node* parent = find_parent(target);

	if (target->left == nullptr && target->right == nullptr)
	{
		// 자식이 없음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				parent->left = nullptr;
				delete target;
			}
			else
			{
				parent->right = nullptr;
				delete target;
			}
		}
		else
		{
			delete target;
			root = nullptr;
		}
	}
	else if (target->left != nullptr && target->right != nullptr)
	{
		// 자식이 양쪽 다 있음.
		node* temp = target->left;
		while (temp->right != nullptr)
			temp = temp->right;

		node* tempParent = find_parent(temp);

		if (tempParent == target)
		{
			temp->right = target->right;
			if (parent == nullptr)
				root = temp;
			else
				parent->left = temp;

			delete target;
		}
		else
		{
			tempParent->right = temp->left;
			temp->left = nullptr;

			if (parent != nullptr)
			{
				if (parent->left == target)
					parent->left = temp;
				else
					parent->right = temp;
			}
			else
			{
				root = temp;
			}

			temp->left = target->left;
			temp->right = target->right;

			delete target;
		}
	}
	else
	{
		// 자식이 한쪽만 있음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				if (target->left != nullptr)
					parent->left = target->left;
				else
					parent->left = target->right;
				delete target;
			}
			else
			{
				if (target->left != nullptr)
					parent->right = target->left;
				else
					parent->right = target->right;
				delete target;
			}
		}
		else
		{
			if (target->left != nullptr)
				root = target->left;
			else
				root = target->right;
			delete target;
		}
	}
	length--;
}

biTree::node * biTree::find(int no)
{
	node* temp = root;
	while (temp != nullptr)
	{
		if (temp->no == no)
			return temp;
		else
		{
			if (no > temp->no)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return nullptr;
}

biTree::node * biTree::find_parent(int no)
{
	node* temp = root;
	node* parent = nullptr;
	while (temp != nullptr)
	{
		if (temp->no == no)
			return parent;
		else
		{
			if (no > temp->no)
			{
				parent = temp;
				temp = temp->left;
			}
			else
			{
				parent = temp;
				temp = temp->right;
			}
		}
	}
	return nullptr;

}

biTree::node * biTree::find_parent(node* target)
{
	node* temp = root;
	node* parent = nullptr;
	while (temp != nullptr)
	{
		if (temp == target)
			return parent;
		else
		{
			if (target->no >= temp->no)
			{
				parent = temp;
				temp = temp->left;
			}
			else
			{
				parent = temp;
				temp = temp->right;
			}
		}
	}
	return nullptr;

}

void biTree::print(wstring & output)
{
	print(root, output);
}

void biTree::print(node * target, wstring & output)
{
	if (target == nullptr)
	{
		output += _T("트리가 비어있습니다.\r\n");
		return;
	}

	if(target->left != nullptr)
		print(target->left, output);

	output += _T("ID : ") + target->name + _T("\tScore :") + to_wstring(target->no) + _T("\r\n");

	if (target->right != nullptr)
		print(target->right, output);

}

biTree::node * biTree::find_most_left()
{
	node* temp = root;
	if (root == nullptr)
		return nullptr;

	while (temp->left != nullptr)
		temp = temp->left;
	
	return temp;
}

biTree::node * biTree::find_most_right()
{
	node* temp = root;
	if (root == nullptr)
		return nullptr;

	while (temp->right != nullptr)
		temp = temp->right;

	return temp;
}

void biTree::read_file()
{
	wifstream fin(_T("ranking.txt"), ios_base::in);
	node input;
	for (int i = 0; i < 5; i++)
	{
		if (fin.badbit)
			break;
		fin.read((wchar_t*)&input, sizeof(node));
		this->push(input.no, input.name);
	}
	fin.close();
}

void biTree::write_file()
{
	wofstream fout(_T("ranking.txt"));
	node* output;
	for (int i = 0; i < 5; i++)
	{
		if (root == nullptr)
			break;
		output = find_most_left();
		fout.write((wchar_t*)output, sizeof(node));
		pop(output);
	}
	fout.close();
}


biTree::~biTree()
{
	while (length)
		pop(root->no);
}
