#include "stdafx.h"

#include <fstream>

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "자동차 메이커와 차종을 입력하시오: ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오: ";
	cin >> year;
	cout << "구입 가격을 입력하시오: ";
	cin >> a_price;
	d_price = 0.913 * a_price;


	cout << fixed; // 소수점을 고정하겠다는 뜻.
	cout.precision(2); // 2자리로 고정;
	cout.setf(ios_base::showpoint); // 부동소수점 무조건 삽입
	cout << "메이커와 차종: " << automobile << endl;
	cout << "연식: " << year << endl;
	cout << "구입가격: " << a_price << endl;
	cout << "현재가격: " << d_price << endl;
	

	outFile << fixed; // 소수점을 고정하겠다는 뜻.
	outFile.precision(2); // 2자리로 고정;
	outFile.setf(ios_base::showpoint); // 부동소수점 무조건 삽입
	outFile << "메이커와 차종: " << automobile << endl;
	outFile << "연식: " << year << endl;
	outFile << "구입가격: " << a_price << endl;
	outFile << "현재가격: " << d_price << endl;

	outFile.close();
	return 0;
}
