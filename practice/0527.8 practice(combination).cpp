#include "stdafx.h"
//
//const int itemNum = 6;
//
//struct Item
//{
//	char name[16];
//	int importance;
//	int weight;
//
//};
//
//void SelSort(Item *iList);
//void Swap(Item *a, Item *b);
//
//
//int main(int argc, char* argv[])
//{
//	/*
//	�� ���� 10���� ���� �� �ִ� �κ��丮�� �ִ�.
//	�����۸��� �߿䵵�� �ְ� ���԰� �ٸ���
//	�߿䵵�� ���� ���� ���� ���⸦ ���� �� �ֵ��� �ۼ�
//	�̸�			�߿䵵		����
//	kar98k		7			4
//	�Ķ�����		10			2
//	������		7			4
//	�ҹ��		6			6
//	������		2			10
//	����			3			5
//
//	��� > �߿䵵 ������ ����� �� �ֵ��� �� ��.
//	�߿䵵 1���� : 24
//	kar98		7			4
//	�Ķ�����		10			4
//	������		7			4
//	*/
//	Item *iList = (Item*)calloc(itemNum, sizeof(Item));
//	iList[0] = { "kar98k"	,7	, 4 };
//	iList[1] = { "�Ķ�����"	,10	, 2 };
//	iList[2] = { "������"	,7	, 4 };
//	iList[3] = { "�ҹ��"	,6	, 6 };
//	iList[4] = { "������"	,2	, 10 };
//	iList[5] = { "����"		,3	, 5 };
//	
//	SelSort(iList);
//	for (int i = 0; i < itemNum; i++)	// ������ 1���� ���~6�� �� ���
//	{
//		if(iList[i].weight <= 10)
//			printf("%s\t%d\n\n", iList[i].name, iList[i].weight);
//
//		for (int j = i + 1; j < itemNum; j++)
//		{
//			if (iList[i].weight + iList[j].weight <= 10)
//			{
//				printf("%s\t%d\n", iList[i].name, iList[i].weight);
//				printf("%s\t%d\n\n", iList[j].name, iList[j].weight);
//			}
//			
//			for (int k = j + 1; k < itemNum; k++)
//			{
//				if (iList[i].weight + iList[j].weight + iList[k].weight <= 10)
//				{
//					printf("%s\t%d\n", iList[i].name, iList[i].weight);
//					printf("%s\t%d\n", iList[j].name, iList[j].weight);
//					printf("%s\t%d\n\n", iList[k].name, iList[k].weight);
//				}
//			}
//		}
//		printf("\n\n");
//	}
//
//	free(iList);
//
//	return 0;
//}
//
//void SelSort(Item *iList)
//{
//	int index = 0;
//	for (int i = 0; i < itemNum-1; i++)
//	{
//		index = i;
//		for (int j = i + 1; j < itemNum; j++)
//		{
//			if (((float)iList[index].importance / iList[index].weight) < ((float)iList[j].importance / iList[j].weight))
//			{
//				index = j;
//			}
//		}
//		Swap(&iList[index], &iList[i]);
//	}
//}
//
//void Swap(Item *a, Item *b)
//{
//	Item *tmp = (Item*)calloc(1, sizeof(Item));
//	memcpy(tmp, a, sizeof(Item));
//	memcpy(a, b, sizeof(Item));
//	memcpy(b, tmp, sizeof(Item));
//
//	free(tmp);
//}