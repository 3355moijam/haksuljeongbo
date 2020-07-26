#include "stdafx.h"
const int SIZE = 11;
struct prob
{
	array<int, SIZE> item;


	void setBox(void)
	{
		item = { 1,3,3,5,5,5,10,10,10,10,38 };
	}

	int getInner(void)
	{
		return getScope(SIZE-1);
	}

	int getScope(int x)
	{
		int sum = 0;
		for (int i = 0; i <= x; i++)
			sum += item[i];
		return sum;
	}
};
enum { A, B, C, D, E, F, G, H, I, J, K };

void gacha(prob & box, int nInput, prob & get);
void Print(const prob & get);


int main()
{
	prob box; box.setBox();
	prob get = {};
	int nInput;
	cout << "�� �� �������? : ";
	cin >> nInput;

	gacha(box, nInput, get);

	Print(get);


	return 0;
}

void gacha(prob & get, int nInput)
{
	prob box;
	box.setBox();
	srand(time(NULL));
	int getItem;
	for (int i = 0; i < nInput; i++)
	{
		getItem = rand() % box.getInner();
		if (getItem < box.getScope(A))
		{
			box.item[A]--;
			get.item[A]++;
		}
		else if (getItem < box.getScope(B))
		{
			box.item[B]--;
			get.item[B]++;
		}
		else if (getItem < box.getScope(C))
		{
			box.item[C]--;
			get.item[C]++;
		}
		else if (getItem < box.getScope(D))
		{
			box.item[D]--;
			get.item[D]++;
		}
		else if (getItem < box.getScope(E))
		{
			box.item[E]--;
			get.item[E]++;
		}
		else if (getItem < box.getScope(F))
		{
			box.item[F]--;
			get.item[F]++;
		}
		else if (getItem < box.getScope(G))
		{
			box.item[G]--;
			get.item[G]++;
		}
		else if (getItem < box.getScope(H))
		{
			box.item[H]--;
			get.item[H]++;
		}
		else if (getItem < box.getScope(I))
		{
			box.item[I]--;
			get.item[I]++;
		}
		else if (getItem < box.getScope(J))
		{
			box.item[J]--;
			get.item[J]++;
		}
		else if (getItem < box.getScope(K))
		{
			box.item[K]--;
			get.item[K]++;
		}

		if (box.getInner() == 0)
			box.setBox();
	}
}
void Print(const prob & get)
{
	cout << "A : " << get.item[A] << "��" << endl;
	cout << "B : " << get.item[B] << "��" << endl;
	cout << "C : " << get.item[C] << "��" << endl;
	cout << "D : " << get.item[D] << "��" << endl;
	cout << "E : " << get.item[E] << "��" << endl;
	cout << "F : " << get.item[F] << "��" << endl;
	cout << "G : " << get.item[G] << "��" << endl;
	cout << "H : " << get.item[H] << "��" << endl;
	cout << "I : " << get.item[I] << "��" << endl;
	cout << "J : " << get.item[J] << "��" << endl;
	cout << "K : " << get.item[K] << "��" << endl;
}