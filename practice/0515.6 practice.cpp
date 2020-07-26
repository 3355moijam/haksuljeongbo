#include "stdafx.h"

int GetFee(int nAge, int nPrice);

int main(void)
{
	printf("%d\n",GetFee(19, 1000));


	return 0;
}

int GetFee(int nAge, int nPrice)
{
	int discount = nPrice;
	if (nAge <= 3)
	{
		discount *= 0;
	}
	else if (nAge <= 13)
	{
		discount *= 0.5;
	}
	else if (nAge <= 19)
	{
		discount *= 0.25;
	}
	
	return discount;
}