#include "exc_mean.h"


inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "잘못된 매개변수: a = -b" << endl;
}

inline const char * bad_gmean::mesg()
{
	return "gmean() 매개변수들은 >= 0이어야 합니다.\n";
}
