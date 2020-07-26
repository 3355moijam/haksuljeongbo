#include "exc_mean.h"


inline void bad_hmean::mesg()
{
	cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "�߸��� �Ű�����: a = -b" << endl;
}

inline const char * bad_gmean::mesg()
{
	return "gmean() �Ű��������� >= 0�̾�� �մϴ�.\n";
}
