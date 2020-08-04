#include "AVL.h"





void AVL::push(int no, string name)
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
		if (no <= temp->no)
		{
			if (temp->left == nullptr)
			{
				temp->left = newNode;
				newNode->parent = temp;
				break;
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
				newNode->parent = temp;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
	}

	rebalance(newNode->parent);
}

void AVL::pop(int no)
{
	node* target;
	if ((target = find(no)) == nullptr)
		return;
	node* parent = target->parent;

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
		
		target->swap(temp);
		pop(temp);
		return;

	}
	else
	{
		// 자식이 한쪽만 있음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				if (target->left != nullptr)
				{
					target->left->parent = parent;
					parent->left = target->left;
				}
				else
				{
					target->right->parent = parent;
					parent->left = target->right;
				}
				delete target;
			}
			else
			{
				if (target->left != nullptr)
				{
					target->left->parent = parent;
					parent->right = target->left;
				}
				else
				{
					target->right->parent = parent;
					parent->right = target->right;
				}
				delete target;
			}
		}
		else
		{
			if (target->left != nullptr)
			{
				root = target->left;
				target->left->parent = nullptr;
			}
			else
			{
				root = target->right;
				target->right->parent = nullptr;
			}
			delete target;
		}
	}
	length--;
	if (parent == nullptr)
		rebalance(root);
	else
		rebalance(parent);
}

void AVL::pop(node * target)
{
	node* parent = target->parent;

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

		target->swap(temp);
		pop(temp);
		return;

	}
	else
	{
		// 자식이 한쪽만 있음
		if (parent != nullptr)
		{
			if (parent->left == target)
			{
				if (target->left != nullptr)
				{
					target->left->parent = parent;
					parent->left = target->left;
				}
				else
				{
					target->right->parent = parent;
					parent->left = target->right;
				}
				delete target;
			}
			else
			{
				if (target->left != nullptr)
				{
					target->left->parent = parent;
					parent->right = target->left;
				}
				else
				{
					target->right->parent = parent;
					parent->right = target->right;
				}
				delete target;
			}
		}
		else
		{
			if (target->left != nullptr)
			{
				root = target->left;
				target->left->parent = nullptr;
			}
			else
			{
				root = target->right;
				target->right->parent = nullptr;
			}
			delete target;
		}
	}
	length--;
	if (length)
	{
		if (parent == nullptr)
			rebalance(root);
		else
			rebalance(parent);
	}
}

AVL::node * AVL::find(int no)
{
	node* temp = root;
	while (temp != nullptr)
	{
		if (temp->no == no)
			return temp;
		else
		{
			if (no < temp->no)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return nullptr;
}



void AVL::print()
{
	print(root);
	cout << endl;
}

void AVL::print(node * target)
{
	if (target == nullptr)
	{
		cout << "트리가 비어있습니다." << endl;
		return;
	}

	if (target->left != nullptr)
		print(target->left);

	cout << target->no << " ";

	if (target->right != nullptr)
		print(target->right);

}

int AVL::get_height(node * target)
{
	int height, left, right;

	if (target->left != nullptr)
		left = get_height(target->left);
	else
		left = 0;

	if (target->right != nullptr)
		right = get_height(target->right);
	else
		right = 0;

	height = left > right ? left : right;
	height += 1;
	return height;
}

int AVL::get_bias(node * target)
{
	int bias, left, right;
	left = target->left != nullptr ? get_height(target->left) : 0;
	right = target->right != nullptr ? get_height(target->right) : 0;
	bias = left - right;
	return bias;
}

void AVL::rebalance(node * target)
{
	node* temp = target;
	int bias;
	while (temp != nullptr)
	{
		bias = get_bias(temp);
		if (abs(bias) >= 2)
			break;
		temp = temp->parent;
	}
	if (bias == 2)
	{
		int LeftSonBias = get_bias(temp->left);
		if (LeftSonBias > 0)
		{
			right_rotate(temp);
		}
		else
		{
			left_rotate(temp->left);
			right_rotate(temp);
		}
	}
	else if (bias == -2)
	{
		int RightSonBias = get_bias(temp->right);
		if (RightSonBias < 0)
		{
			left_rotate(temp);
		}
		else
		{
			right_rotate(temp->right);
			left_rotate(temp);
		}
	}
	else
		return;
}


void AVL::left_rotate(node * target)
{
	node* right = target->right;
	if (target == root)
	{
		root = right;
		right->parent = nullptr;
	}
	else
	{
		right->parent = target->parent;
		if(target->parent->right == target)
			target->parent->right = right;
		else
			target->parent->left = right;
	}

	target->right = right->left;
	if(target->right != nullptr)
		target->right->parent = target;

	right->left = target;
	target->parent = right;
}

void AVL::right_rotate(node * target)
{
	node* left = target->left;
	if (target == root)
	{
		root = left;
		left->parent = nullptr;
	}
	else
	{
		left->parent = target->parent;
		if(target->parent->left == target)
			target->parent->left = left;
		else
			target->parent->right = left;
	}

	target->left = left->right;
	if(target->left != nullptr)
		target->left->parent = target;

	left->right = target;
	target->parent = left;
}
AVL::~AVL()
{
	while (length)
		pop(root);
}

void AVL::node::swap(node * target)
{
	int nTemp;
	string sTemp;
	SWAP(no, target->no, nTemp);
	SWAP(name, target->name, sTemp);
}
