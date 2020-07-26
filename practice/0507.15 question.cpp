#include "stdafx.h"

int main(void)
{
	float a = 0;
	float b = 0;
	
	printf("µÎ ¼ö¸¦ ÀÔ·ÂÇØ ÁÖ¼¼¿ä : ");
	scanf("%f%f", &a, &b);

	printf("ÀÔ·Â¹ÞÀº ¼ö : %f %f\n", a, b);
	printf("µ¡¼À : %.2f\n", a+b);
	printf("»¬¼À : %.2f\n", a-b);
	printf("°ö¼À : %.2f\n", a*b);
	printf("³ª´°¼À : %.2f\n", a/b);
	printf("Æò±Õ : %.2f\n", (a+b)/2);

	return 0;
}
