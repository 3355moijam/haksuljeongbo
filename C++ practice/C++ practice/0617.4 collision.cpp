#include "stdafx.h"

struct dot
{
	float x;
	float y;
};

struct rect
{
	dot center;
	float w;
	float h;
	dot a;
	dot b;
	dot c;
	dot d;
	
	void setDot()
	{
		a.x = center.x - w / 2;
		a.y = center.y + h / 2;
		b.x = center.x + w / 2;
		b.y = center.y + h / 2;
		c.x = center.x - w / 2;
		c.y = center.y - h / 2;
		d.x = center.x + w / 2;
		d.y = center.y - h / 2;
	}
};

struct line
{
	float slope;
	float y_inter;
	float scope1;
	float scope2;

	bool isOnLine(float scope)
	{
		if (scope >= scope1 && scope <= scope2)
			return true;
		else
			return false;
	}
};

struct circle
{
	dot center;
	float r;
};
void getCircle(circle *pCircle);
void getDot(dot *pDot);
float getDiameter(void);
bool isInCircle(dot *pDot, float r);
int isCollide(circle *target, circle *obj);

void getRec(rect *pRec);
bool isInRec(rect *pRec, dot *pDot);
void getLine(dot A, dot B, line *line);
bool getCross(line A, line B);
int isCollide(rect *target, rect *obj);


int main()
{
	circle cir1, cir2;
	getCircle(&cir1); getCircle(&cir2);

	switch (isCollide(&cir1, &cir2))
	{
	case 0: cout << "�� ���� ��ġ�� ����." << endl;
		break;
	case 1: cout << "�� ���� �Ϻ� ��ħ." << endl;
		break;
	case 2: cout << "�� ��° ���� ù ��° �� �ȿ� ����." << endl;
		break;
	default:
		break;
	}

	//rect rec1, rec2;
	//getRec(&rec1); getRec(&rec2);
	//switch (isCollide(&rec1, &rec2))
	//{
	//case 0: cout << "�� �簢���� ��ġ�� ����." << endl;
	//	break;
	//case 1: cout << "�� �簢���� �Ϻ� ��ħ." << endl;
	//	break;
	//case 2: cout << "�� ��° �簢���� ù ��° �簢�� �ȿ� ����." << endl;
	//	break;
	//case 3: cout << "ù ��° �簢���� �� ��° �簢�� �ȿ� ����." << endl;
	//	break;
	//default:
	//	break;
	//}



	return 0;
}
void getCircle(circle *pCircle)
{
	getDot(&pCircle->center);
	pCircle->r = getDiameter();
}
void getDot(dot *pDot)
{
	cout << "���� ��ǥ�� �Է����ּ���." << endl;
	cout << "X Y : ";
	cin >> pDot->x >> pDot->y;
}
float getDiameter(void)
{
	cout << "���� ������ �Է��� �ּ���." << endl;
	cout << "R : ";
	float tmp;
	cin >> tmp;

	return tmp;
}

//bool isInCircle(dot *pDot, float r)
//{
//	bool a = pDot->x*pDot->x + pDot->y*pDot->y <= r*r;
//	return a;
//}

void getRec(rect *pRec)
{
	cout << "�簢���� �߽����� ��, ���̸� �Է����ּ���." << endl;
	cout << "�߽��� X Y : ";
	cin >> pRec->center.x >> pRec->center.y;
	cout << "�� ���� : ";
	cin >> pRec->w >> pRec->h;

	pRec->setDot();
}

bool isInRec(rect *pRec, dot *pDot)
{
	bool x = pDot->x >= pRec->c.x && pDot->x <= pRec->b.x;
	bool y = pDot->y >= pRec->c.y && pDot->y <= pRec->b.y;
	return x && y;
}

// 0: �浹X, 1: ��ħ, 2: target �ȿ� obj 3: obj �ȿ� target
int isCollide(rect *target, rect *obj)
{
	bool a = isInRec(target, &obj->a);
	bool b = isInRec(target, &obj->b);
	bool c = isInRec(target, &obj->c);
	bool d = isInRec(target, &obj->d);

	if (a && b && c && d)
	{
		return 2;
	}
	else if (a || b || c || d)
	{
		return 1;
	}
	else
	{
		a = isInRec(obj, &target->a);
		b = isInRec(obj, &target->b);
		c = isInRec(obj, &target->c);
		d = isInRec(obj, &target->d);

		if (a && b && c && d)
		{
			return 3;
		}
		else if (a || b || c || d)
		{
			return 1;
		}
		else
		{
			line targetAD; getLine(target->a, target->d, &targetAD);
			line objAD; getLine(obj->a, obj->d, &objAD);

			if (getCross(targetAD, objAD))
				return 1;
			else
				return 0;
		}
	}
}
int isCollide(circle *target, circle *obj)
{
	float distance = sqrt(pow(target->center.x - obj->center.x, 2) + pow(target->center.y - obj->center.y, 2));
	
	if (distance > target->r + obj->r)
	{
		return 0;
	}
	else
	{
		if (distance + obj->r <= target->r)
			return 2;
		else
			return 1;
	}
}

void getLine(dot A, dot B, line *line)
{
	if (A.x == B.x && A.y == B.y)
	{
		cout << "Error: ���� �ٸ� ���� �־��ּ���." << endl;
		exit(1);
	}

	else if (A.x == B.x)
	{
		line->slope = 1;
		line->y_inter = A.x;
	}

	else
	{
		line->slope = (A.y - B.y) / (A.x - B.x);
		line->y_inter = A.y - A.x * line->slope;
	}

	if (A.x >= B.x)
	{
		line->scope1 = B.x;
		line->scope2 = A.x;
	}
	else
	{
		line->scope1 = A.x;
		line->scope2 = B.x;
	}

	//return line;
}
bool getCross(line A, line B)
{
	dot tmp = {};
	// ���� ���� ���� ����
	if (A.slope == B.slope && A.y_inter == B.y_inter)
	{
		if (A.isOnLine(B.scope1) || A.isOnLine(B.scope2))
		{
			//cout << "���� ���� ���� �ְ� ���� ����." << endl;
			return true;
		}
		else
		{
			//cout << "���� ���� ���� �ְ� ���� ������ ����." << endl;
			return false;
		}
	}

	else if (A.slope == B.slope)
	{
		//cout << "���� ������." << endl;
		return false;
	}

	else
	{
		tmp.x = -(A.y_inter - B.y_inter) / (A.slope - B.slope);
		tmp.y = A.slope * tmp.x + A.y_inter;
		if (!(A.isOnLine(tmp.x) && B.isOnLine(tmp.x)))
		{
			//cout << "�������� ���� �ٱ��� ����." << endl;
			return false;
		}
		else
		{
			//cout << "(" << tmp.x << ", " << tmp.y << ") ���� ����." << endl;
			return true;
		}
	}
	//return tmp;
}