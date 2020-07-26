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
//	총 무게 10까지 담을 수 있는 인벤토리가 있다.
//	아이템마다 중요도가 있고 무게가 다르다
//	중요도가 가장 높게 다음 무기를 담을 수 있도록 작성
//	이름			중요도		무게
//	kar98k		7			4
//	후라이팬		10			2
//	스코프		7			4
//	뚝배기		6			6
//	라이플		2			10
//	지도			3			5
//
//	출력 > 중요도 순으로 출력할 수 있도록 할 것.
//	중요도 1순위 : 24
//	kar98		7			4
//	후라이팬		10			4
//	스코프		7			4
//	*/
//	Item *iList = (Item*)calloc(itemNum, sizeof(Item));
//	iList[0] = { "kar98k"	,7	, 4 };
//	iList[1] = { "후라이팬"	,10	, 2 };
//	iList[2] = { "스코프"	,7	, 4 };
//	iList[3] = { "뚝배기"	,6	, 6 };
//	iList[4] = { "라이플"	,2	, 10 };
//	iList[5] = { "지도"		,3	, 5 };
//	
//	SelSort(iList);
//	for (int i = 0; i < itemNum; i++)	// 개수가 1개인 경우~6개 인 경우
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