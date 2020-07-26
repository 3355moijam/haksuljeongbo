#include "stdafx.h"
#include <algorithm>
struct Review
{
	string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�." << endl;
		cout << "���\t����" << endl;
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);

		cout << "�� �� �� ����Ѵ�: " << endl;
		cout << "���\t����" << endl;
		
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
		{
			ShowReview(*pr);
		}
		vector<Review> oldlist(books);

		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "������ ��: " << endl;
			// ���� �Ѱ� ����
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "������ �� : " << endl;
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist�� books�� ��ȯ�� ��: " << endl;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "�Է��� ���� ����, ���� ���� �����ϴ�." << endl;
	


	return 0;
}

bool FillReview(Review & rr)
{
	cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "å ���(0-10)�� �Է��Ͻʽÿ�: ";
	cin >> rr.rating;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review & rr)
{
	cout << rr.rating << "\t" << rr.title << endl;
}
