//在顺序表中查找某值，若没找到就插入
#include "pch.h"
#include <iostream>

void showArray(int as[], int length);

void function(int *a, int target, int length)
{
	int star = 0, end = length - 1, index = 0;
	while (star <= end)
	{
		index = (star + end) / 2;
		if (a[index] == target)
		{
			if (index != length-1)
			{
				a[index] = a[index] + a[index + 1];
				a[index + 1] = a[index] - a[index + 1];
				a[index] = a[index] - a[index + 1];
			}
			break;
		}
		else if (a[index] > target)
		{
			end = index - 1;
		}
		else
		{
			star = index + 1;
		}
	}
	printf("%d,%d\n", star, end);
	if (star > end)
	{
		/*int i = 0;
		for (i = length - 1; i > end; i--)
		{
			a[i + 1] = a[i];
		}
		a[i + 1] = target;*/
	}

}
int main()
{
	int a[9] = { 1,2,4,5,6,7,8,9,10 };
	function(a, -1, 9);
	showArray(a, 9);
}

void showArray(int as[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);
	}
}


