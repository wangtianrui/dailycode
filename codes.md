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

```c++
//交换[ab]为[ba]
#include "pch.h"
#include <iostream>

void showArray(int as[], int length);
void reverse(int *a, int star, int end)
{
	for (int i = star, j = end; i < j; i++, j--)
	{
		a[i] += a[j];
		a[j] = a[i] - a[j];
		a[i] = a[i] - a[j];
	}
}
void exchange(int *a, int m, int n, int length)
{

	reverse(a, 0, length - 1);
	reverse(a, 0, n - 1);
	reverse(a, n, length - 1);
}


int main()
{
	int a[15] = { 1,2,3,4,5,6,21,22 ,23,24,25,26,27,28,29 };
	int m = 6, n = 9;
	exchange(a, m, n, 15);
	showArray(a, 15);

	int b[8] = { 1,2,3,4,5,6,21,22 };
	m = 6, n = 2;
	exchange(b, m, n, 8);
	showArray(b, 8);

	int c[10] = { 1,2,3,4,5,6,21,22,23,24 };
	m = 6, n = 4;
	exchange(c, m, n, 10);
	showArray(c, 10);


}

void showArray(int as[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);

	}
	printf("\n");
}
```

```c++
//查找主数
#include "pch.h"
#include <iostream>

void showArray(int as[],int length);

int majority(int *a, int n)
{
	int i, c, count = 1;
	c = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] == c)
		{
			count++;
		}
		else
		{
			if (count > 0)
			{
				count--;
			}
			else
			{
				c = a[i];
				count = 1;
			}
			
		}
	}
	if (count > 0)
	{
		for (i = count = 0; i < n; i++)
		{
			if (a[i] == c)
			{
				count++;
			}
		}
	}
	if (count > n/2)
	{
		return c;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int a[8] = {0,5,5,3,2,7,5,5};
	printf("%d", majority(a, 8));
}

void showArray(int as[],int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", as[i]);
		
	}
	printf("\n");
}

```

