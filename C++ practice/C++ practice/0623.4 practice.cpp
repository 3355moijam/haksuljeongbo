#include "stdafx.h"

struct prob
{
	int A, B, C, D, E, F, G, H, I, J, K;
};
enum { A, B, C, D, E, F, G, H, I, J, K };
prob probability = { 1,3,3,5,5,5,10,10,10,10,38 };

void makeBox(vector<int>*);
void gacha(vector<int> & box, int nInput, prob & item);
void Print(prob *item);

int main()
{
	vector<int> box;
	makeBox(&box);
	prob item = {};

	int nInput;
	cout << "몇 번 뽑을까요? : ";
	cin >> nInput;

	gacha(box, nInput, item);
	
	Print(&item);


	return 0;
}

void makeBox(vector<int> *box)
{	
	for (int i = 0; i < probability.A; i++)
		box->push_back(A);
	for (int i = 0; i < probability.B; i++)
		box->push_back(B);
	for (int i = 0; i < probability.C; i++)
		box->push_back(C);
	for (int i = 0; i < probability.D; i++)
		box->push_back(D);
	for (int i = 0; i < probability.E; i++)
		box->push_back(E);
	for (int i = 0; i < probability.F; i++)
		box->push_back(F);
	for (int i = 0; i < probability.G; i++)
		box->push_back(G);
	for (int i = 0; i < probability.H; i++)
		box->push_back(H);
	for (int i = 0; i < probability.I; i++)
		box->push_back(I);
	for (int i = 0; i < probability.J; i++)
		box->push_back(J);
	for (int i = 0; i < probability.K; i++)
		box->push_back(K);
}
void gacha(vector<int> & box, int nInput, prob & item)
{
	srand(time(NULL));
	int getItem;
	for (int i = 0; i < nInput; i++)
	{
		getItem = rand() % box.size();
		switch (box[getItem])
		{
		case A: item.A++;
			break;
		case B: item.B++;
			break;
		case C: item.C++;
			break;
		case D: item.D++;
			break;
		case E: item.E++;
			break;
		case F: item.F++;
			break;
		case G: item.G++;
			break;
		case H: item.H++;
			break;
		case I: item.I++;
			break;
		case J: item.J++;
			break;
		case K: item.K++;
			break;
		default:
			break;
		}

		box.erase(box.begin() + getItem);
		if (!box.size())
			makeBox(&box);
	}
}
void Print(prob *item)
{
	cout << "A : " << item->A << "개" << endl;
	cout << "B : " << item->B << "개" << endl;
	cout << "C : " << item->C << "개" << endl;
	cout << "D : " << item->D << "개" << endl;
	cout << "E : " << item->E << "개" << endl;
	cout << "F : " << item->F << "개" << endl;
	cout << "G : " << item->G << "개" << endl;
	cout << "H : " << item->H << "개" << endl;
	cout << "I : " << item->I << "개" << endl;
	cout << "J : " << item->J << "개" << endl;
	cout << "K : " << item->K << "개" << endl;
}