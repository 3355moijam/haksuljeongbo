#include "stdafx.h"


int main()
{
	string one("Lottery winner!");
	cout << one << endl;

	string two(20, '$');
	cout << two << endl;

	string three(one); // 복사한다.
	cout << three << endl;
	one += " Oops!";
	cout << one << endl;
	cout << three << endl;
	three[0] = 'P';
	cout << three << endl;

	two = "Sorry! That was ";
	cout << two << endl;

	string four;
	four = two + three;

	char alls[] = "all's well that ends well";
	string five(alls, 20);
	cout << five << endl;

	string six(alls + 6, alls + 10);
	cout << six << endl;
	string seven(&five[6], &five[10]);
	cout << seven << endl;

	string eight(five, 6, 4);
	cout << eight << endl;
	return 0;
}
