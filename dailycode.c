

//int * twoSum(int *nums,int numsSize,int target)
//{
//	int i , j ;
//	int big ;
//	int * result = (int *)malloc(sizeof(int)*2);
//	
//	for(i = 0 ; i < numsSize ; i++)
//	{
//		for(j = i + 1  ; j < numsSize ; j++)
//		{	
//			if(nums[i] + nums[j] == target)
//			{ 
//				result[0] = i ;
//				result[1] = j ;
//				return result;
//			}
//			
//		}
//	}
//	return result;
//}
//
//struct ListNode
//{
//	int val;
//	struct ListNode *next ;
//};
//
//
//struct ListNode * createNode(int val , struct ListNode * head)
//{
//	struct ListNode * temp  = (struct ListNode *)malloc(sizeof(struct ListNode));
//	temp->val = val;
//	temp->next = NULL;
//	if(head==NULL)
//	{
//		head = temp;
//	}
//	else
//	{
//		struct ListNode * p ;
//		p = head ;
//		while(p->next)
//		{
//			p = p->next ;
//		}
//		p->next = temp;
//	}
//	return head;
//}
//
//void show(struct ListNode * head)
//{
//	while(head)
//	{
//		printf("%d->",head->val);
//		head = head->next ;
//	}
//	printf("\n");
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
//{
//	struct ListNode * pre = NULL ;
//	struct ListNode * next = NULL ;
//	struct ListNode * result = NULL ;
//	
//	int ten = 0;
//	while(l1||l2||ten)
//	{
//		struct ListNode * temp = (struct ListNode*)malloc(sizeof(struct ListNode));
//		temp->val = 0 ;
//		temp->next = NULL ;
//		int sum = 0;
//		if(l1 && l2)
//		{
//			sum = l1->val + l2->val + ten;
//			l1 = l1->next ;
//			l2 = l2->next ;
//		}
//		else if(l1)
//		{
//			sum = l1->val + ten ;
//			l1 = l1->next ;
//		}
//		else if(l2)
//		{
//			sum = l2->val + ten ;
//			l2 = l2->next ;
//		}
//		else if(ten)
//		{
//			sum = ten ;
//		}
//		ten = 0;
//		if(sum >= 10)
//		{
//			temp->val += (sum - 10);
//			ten = 1 ;
//		}
//		else
//		{
//			temp->val += sum ;
//		}
//		if(result == NULL)
//		{
//			result = temp;
//		}
//		else
//		{
//			struct ListNode * p = result;
//			while(p->next)
//			{
//				p = p->next;
//			}
//			p->next = temp ;
//		}
//	}
//	return result ;
//}
//void showString(char * s, int size)
//{
//	int index = 0;
//	for(; index < size ; index++)
//	{
//		printf("%c",s[index]);
//	}
//	printf("\n");
//}
//
//int lengthOfLongestSubstring(char* s)
//{
//	int i , j ;
//	int index = 0 ;
//	int length = 0 ;
//	int elementSize = 0 ;
//	char * elements = NULL ;
//	char * temps = NULL ;
//	int max = 0;
//	int location ;
//	while(s[index]!='\0')
//	{
//		int content = 0;
//		for( i = 0 ; i < elementSize ; i ++)
//		{
//			if(elements[i]==s[index])
//			{
//				location = i ;
//				content = 1 ;
//				break ;
//			}
//		}
//		if(content==0)
//		{
//			elementSize += 1 ;
//			if(elements)
//			{
//				temps = (char *)malloc(sizeof(char)*elementSize);
//				for(i = 0 ; i < (elementSize - 1) ; i++)
//				{
//					temps[i] = elements[i];
//				}
//				elements = temps ;
//			}
//			else
//			{
//				elements = (char *)malloc(sizeof(char)*elementSize);
//			}
//			elements[elementSize - 1] = s[index];
//		}
//		else
//		{
//			int newSize = elementSize - i ;
//			char * temps = (char *)malloc(sizeof(char)*(newSize));
//			j = 0;
//			for(i = location + 1  ; i < location + newSize ; i++ )
//			{				
//				temps[j] = elements[i];
//				j++;
//			}
//			temps[j] = s[index];
//			elementSize = newSize ; 
//			elements = temps ;			
//		}
//		index ++;
//		if(max < elementSize)
//		{
//			max = elementSize ;
//		}
//	}
//	return max ;
//}
//
//char* longestPalindrome(char* s) 
//{
//    int head , tail , index , t ;
//    index = 0 ;
//    int size = 0 ;
//    char * result = NULL ; 
//	while(s[index]!='\0')
//	{
//		size++;
//	} 
//	tail = size ;
//	while(head <= size / 2)
//	{
//		t = tail ; 
//		if(s[head]!=s[t])
//		{
//			t--;
//		}
//		else
//		{
//			
//		}
//		
//		if(tail == head + 1)
//		{
//			head ++ ;
//			tail -- ;
//		}
//	}
//}
//


/*
int targetIndex = 0 , resultIndex = 0 , isSequ = 0 , lastIsArr1 = 0;
    int index1 = 0 , index2 = 0 ;
    double result = 0;
    
    if((nums1Size + nums2Size) % 2 == 0)
    {
    	targetIndex = (nums1Size + nums2Size) / 2  ;
    	if(nums1Size == 0)
    	{
    		return (nums2[targetIndex]+nums2[targetIndex+1]) / 2.0 ;
    	}
    	else if(nums2Size == 0)
    	{
    		return (nums1[targetIndex]+nums1[targetIndex+1]) / 2.0 ;
    	}
    	while(index1 + index2 + 1 <= targetIndex )
    	{
    		if(nums1[index1] < nums2[index2])
    		{
    			index1 ++ ;
    			if(lastIsArr1)
    			{
    				isSequ = 1 ;
    			}
    			lastIsArr1 = 1 ;	
    		}
    		else
    		{
    			index2 ++ ;
				if(!lastIsArr1)
    			{
    				isSequ = 1 ;
    			}
    			lastIsArr1 = 0 ;		
    		}
    	}
    	if(isSequ)
    	{
//    		printf("issequ\n");
    		if(lastIsArr1)
    		{
//    			printf("arr1\n");
    			if(index1 < nums1Size)
    			{
//    				printf("С�ڣ�%d,%d\n",index1,index2);
    				result = (nums1[index1] + nums1[index1 + 1] ) / 2.0 ;  	
    			}
    			else if(index1 == nums1Size)
    			{
//    				printf("���ڣ�%d,%d\n",index1,index2);
    				result = (nums1[index1] + nums2[index2]) / 2.0 ;  
    			}
    		}
    		else
    		{
//    			printf("arr2\n");
    			result = (nums2[index2] + nums2[index2 + 1]) / 2.0 ;  
    		}
    	}
    	else
		{
//			printf("nosequ\n");
			result = (nums1[index1] + nums2[index2]) / 2.0 ;  
    	}	
    }
    else
    {
    	targetIndex = (nums1Size + nums2Size) / 2  ;
    	if(nums1Size == 0)
    	{
    		return (nums2[targetIndex]) ;
    	}
    	else if(nums2Size == 0)
    	{
    		return (nums1[targetIndex])  ;
    	}
    	targetIndex = (nums1Size + nums2Size) / 2 ;
    	while((index1 + index2) < targetIndex)
    	{
    		if(nums1[index1] < nums2[index2])
    		{
    			index1 ++ ;
    			if(nums1[index1] < nums2[index2])
    			{
    				lastIsArr1 = 1 ;
    			}
				else
				{
					lastIsArr1 = 0 ;
				}
    		}
    		else
			{
				index2 ++ ;
				if(nums1[index1] < nums2[index2])
    			{
    				lastIsArr1 = 1 ;
    			}
				else
				{
					lastIsArr1 = 0 ;
				}
    		}
    	}
    	if(lastIsArr1)
    	{
    		result = nums1[index1] ;
    	}
    	else
    	{
    		result =  nums2[index2];
    	}
//    	printf("%d,%d,%d\n",index1,index2,targetIndex);
    }
    return result ;
*/

#include<stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int wholeCount = 0 ;
    wholeCount = nums1Size + nums2Size ;
    int cast = (wholeCount + 1) / 2 ;    //��ż�м���index��ȡ��
	int index1 = 0 , index2 = 0 , flag = 0 , mid1 = 0 , mid2 = 0 ;
	double result = 0.0 ;
	if(nums1Size == 0)
	{
		if(wholeCount % 2 == 0)
		{
			return (nums2[cast] + nums2[cast - 1]) / 2.0 ;
		}
		else
		{
			return nums2[cast-1];
		}
	}
	else if(nums2Size == 0)
	{
		if(wholeCount % 2 == 0)
		{
			return (nums1[cast] + nums1[cast -1]) / 2.0 ;
		}
		else
		{
			return nums1[cast-1];
		}
	}
	while(flag < cast - 1)
	{
		if(nums1[index1]<nums2[index2])
		{
//			printf("1++\n");
			index1 ++ ;
			if(!checkIndex(index1,nums1Size))
			{
				index2 ++ ;
			}
		}
		else
		{
//			printf("2++\n");
			index2 ++ ;
			if(!checkIndex(index2,nums2Size))
			{
				index1 ++ ;
			}
		}
		flag ++ ;
	}
	
	
	if(wholeCount % 2 == 0)
	{
		printf("%d,%d,\n",index1,index2);
		if(nums1[index1] < nums2[index2])
		{
			mid1 = nums1[index1];	
			index1 += 1 ;
			if(!checkIndex(index1,nums1Size))
			{
				index2 ++ ;
			}
		}
		else
		{
			mid1 = nums2[index2];
			index2 += 1;
			if(!checkIndex(index2,nums2Size))
			{
				index1 ++ ;
			}
		}
		printf("%d,%d,\n",index1,index2);
		if(nums1[index1] < nums2[index2])
		{
			mid2 = nums1[index1];
		}
		else
		{
			mid2 = nums2[index2];
		}
		printf("%d,%d\n",mid1,mid2);
		result = (mid1+mid2) / 2.0 ;
	}
	else
	{
//		printf("%d,%d,nums2:%d\n",index1,index2,nums2[0]);
		if(nums1[index1] < nums2[index2])
		{
			result = nums1[index1];
//			printf("1\n");
		}
		else
		{
			result = nums2[index2];
//			printf("2,index2:%d\n",nums2[index2]);
		}
	}
	return result ;
}

int checkIndex(int index,int size)
{
	if(index>=size)
	{
		return 0;
	}
	else
	{
		return 1 ;
	}
}
int main()
{
	int i ;
	int  arr1[2] = {1,2};
	int arr2[2] = {3,4};
	
	int size1 = 2 ;
	int size2 = 2 ;	
	
//	int size1 = 0 ;
//	int size2 = 2 ;
//	int arr1[0] = {};
//	int arr2 [2] = {2,3};
	printf("%lf",findMedianSortedArrays(arr1,size1,arr2,size2));
//	printf("hello");
	return 0;
}
