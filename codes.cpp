// codes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void showArray(int as[],int length);

int * merge(int a1[], int a2[], int length1,int length2)
{
	int * result = (int *)malloc((length1 + length2) * sizeof(int));
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
	/*int as[15] = { 1,2,3,2,4,6,3,2,2,5,3,5,6,1,7 };*/
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
