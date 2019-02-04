```c++
//合并两有序数组
#include "pch.h"
#include <iostream>

void showArray(int as[],int length);

int * merge(int a1[], int a2[], int length1,int length2)
{
	int * result = (int *)malloc((length1 + length2) * sizeof(int));
	//注意长度和索引对比的时候，长度应该-1
	int index1 = 0 , index2 = 0 , i = 0 ;
	for (i = 0; i < length1+length2; i++)
	{
		if (a1[index1] < a2[index2] || index2 >= length2)
		{
			result[i] = a1[index1++];
		}
		else if (a1[index1] >= a2[index2] || index1 >= length1)
		{
			result[i] = a2[index2++];
		}
	}
	return result;
}

int main()
{
	int a1[6] = { 1,6,8,9,55,90 };
	int a2[3] = { 1,33,44 };
	int * c = merge(a1, a2, 6, 3);
	showArray(c, 9);
}

void showArray(int as[],int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);
	}
}

```

