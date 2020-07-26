#include "stdafx.h"

int main(void)
{

	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);

	printf("%.1f\n", dData); // 소수점 2번째 자리에서 반올림하고 한자리까지 출력
	printf("%.2f\n", dData); // 3에서 반올림, 2자리 출력
	printf("%.3f\n", dData); // 4에서 반올림, 3자리 출력

	printf("%8d\n", 123); // 소수점 포함 12자리로 출력, 소수점 이하 4번째에서 반올림하고 3자리만 출력
	printf("%12.3f\n", dData);
	printf("%012.3f\n", dData);


	return 0;
}
