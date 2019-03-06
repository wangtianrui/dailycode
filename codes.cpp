//合并两有序数组
#include "pch.h"
#include <iostream>

void showArray(int as[], int length);

int getMid(int * a, int *b, int length)
{
	////时间复杂度为O(N)
	//int indexA = 0, indexB = 0, mid = 0;
	//while (indexA + indexB < length)
	//{
	//	if (a[indexA] < b[indexB])
	//	{
	//		mid = a[indexA];
	//		indexA++;
	//	}
	//	else
	//	{
	//		mid = a[indexB];
	//		indexB++;
	//	}
	//}
	//return mid;

	int indexAStar = 0, indexBStar = 0, indexAEnd = length - 1, indexBEnd = length - 1;
	int aMid = 0, bMid = 0;

	while (indexAEnd != indexAStar || indexBEnd != indexBStar)
	{
		printf("a:%d,%d ; b:%d,%d\n", indexAStar, indexAEnd, indexBStar, indexBEnd);
		aMid = (indexAStar + indexAEnd) / 2;
		bMid = (indexBStar + indexBEnd) / 2;
		if (a[aMid] == b[bMid])
		{
			return a[aMid];
		}
		else if (a[aMid] > b[bMid])
		{
			if (indexAEnd != indexAStar)
			{
				indexAEnd = aMid - 1;
			}
			if (indexBEnd != indexBStar)
			{
				indexBStar = bMid + 1;
			}
		}
		else
		{
			if (indexAEnd != indexAStar)
			{
				indexAStar = aMid + 1;
			}
			if (indexBEnd != indexBStar)
			{
				indexBEnd = bMid - 1;
			}


		}
	}
	if (a[aMid] < b[bMid])
	{
		return a[aMid];
	}
	else
	{
		return b[bMid];
	}
}
int main()
{
	int a[9] = { 0,0,0,0,0,0,0,0,0 };
	int b[9] = { 2,4,6,8,10,12,14,16,18 };
	printf("%d\n", getMid(a, b, 9));
}

void showArray(int as[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);
	}
}