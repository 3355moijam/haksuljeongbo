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
		cout << "갑사합니다. 당신은 다음과 같이 입력하셨습니다." << endl;
		cout << "등급\t제목" << endl;
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);

		cout << "한 번 더 출력한다: " << endl;
		cout << "등급\t제목" << endl;
		
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
		{
			ShowReview(*pr);
		}
		vector<Review> oldlist(books);

		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "삭제한 후: " << endl;
			// 원소 한개 삽입
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "삽입한 후 : " << endl;
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist와 books를 교환한 후: " << endl;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "입력한 것이 없어, 얻은 것이 없습니다." << endl;
	


	return 0;
}

bool FillReview(Review & rr)
{
	cout << "책 제목을 입력하십시오(끝내려면 quit을 입력): ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "책 등급(0-10)을 입력하십시오: ";
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
