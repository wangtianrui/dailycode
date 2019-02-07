//合并两有序数组
#include "pch.h"
#include <iostream>

void showArray(int as[], int length);

int deleteX(int *a, int x, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] == x)
		{
			count++;
		}
		else
		{
			a[i - count] = a[i];
		}
	}
	length -= count;
	return length;
}

int main()
{

	int a[10] = { 1,2,44,2,2,2,5,3,1,2 };
	int len = deleteX(a, 2, 10);
	showArray(a, len);
}

void showArray(int as[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);
	}
}