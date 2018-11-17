

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
//    				printf("小锟节ｏ拷%d,%d\n",index1,index2);
    				result = (nums1[index1] + nums1[index1 + 1] ) / 2.0 ;  	
    			}
    			else if(index1 == nums1Size)
    			{
//    				printf("锟斤拷锟节ｏ拷%d,%d\n",index1,index2);
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
#include<string.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    double result = 0 ;
	int index1 = 0 , index2 = 0 , mid1 = 0 , mid2 = 0 ; 
	int wholeCount = nums1Size + nums2Size ;
	
	while(index1 + index2 + 1 < (wholeCount + 1) / 2)
	{
		if(index1 == nums1Size)
		{
			index2 ++ ;
		}
		else if( index2 == nums2Size )
		{
			index1 ++ ;
		}
		else if (nums1[index1]<nums2[index2])
		{
			index1 ++ ;
		}
		else if (nums1[index1]>=nums2[index2])
		{
			index2 ++;
		}
		printf("%d,%d\n",index1,index2);
	}
	if(wholeCount % 2 == 0)
	{
		if(index1 == nums1Size)
		{
			result = (nums2[index2]+nums2[index2+1])/2.0;
			return result ;
		}
		else if (index2 == nums2Size)
		{
			result = (nums1[index1]+nums1[index1+1])/2.0;
			return result ;
		}
		else if (nums1[index1]<nums2[index2])
		{
			mid1 = nums1[index1];
			index1 ++ ;
		}
		else if (nums1[index1]>=nums2[index2])
		{
			mid1 = nums2[index2];
			index2 ++ ;
		}
		/*------------------------*/
		if(index1 == nums1Size)
		{
			result = (nums2[index2]+mid1)/2.0;
			return result ;
		}
		else if (index2 == nums2Size)
		{
			result = (nums1[index1]+mid1)/2.0;
			return result ;
		}
		else if (nums1[index1]<nums2[index2])
		{
			mid2 = nums1[index1];
		}
		else if (nums1[index1]>=nums2[index2])
		{
			mid2 = nums2[index2];
		}
		result = (mid1 + mid2) / 2.0 ;
	}
	else
	{
		if(index1 == nums1Size)
		{
			result = nums2[index2];
			return result ;
		}
		else if (index2 == nums2Size)
		{
			result = nums1[index1];
			return result ;
		}
		else if (nums1[index1]<nums2[index2])
		{
			result = nums1[index1];
		}
		else if (nums1[index1]>=nums2[index2])
		{
			result = nums2[index2];
		}
	}
	return result ;
}

/*
检查是否是回文
s: "avbd"
length : 4
*/
int checkIsHuiWen(char *s , int indexFirst , int indexSecond)
{
	while(indexFirst <= indexSecond)
	{
		printf("%d:%c,%d:%c\n",indexFirst,s[indexFirst],indexSecond,s[indexSecond]);
		if(s[indexFirst]!=s[indexSecond])
		{
			return 0;
		}
		indexSecond--;
		indexFirst ++ ;
	}
	return 1 ;
}

/*
字符串裁剪
string:123456
star:1
end:4
return:2345 
*/
char* clipStr(char* string , int star , int length)
{
	int i;
	char * returnString = (char *)malloc((sizeof(char))*(length+1));
	for(i = 0; i < length ; star++)
	{
		returnString[i] = string[star];
		i++;
	}
	returnString[i]='\0';  // 记住加\0 ，如果不写的话，会自动填充一个随机地址 
	return returnString ;
} 
/*
字符串保存：用初始位置和长度来保存，以免开辟新空间来存！ 
*/
char* longestPalindrome(char* s) {
	
 	int indexFirst = 0 , indexSecond = 0;
	int length = 0 ;   
	int maxSize = 0 ;
	int maxStart = 0 ; 
	char * maxClip = NULL ;
	length = strlen(s);
	if(length <= 1)
	{
		return s;
	}
	for(; indexFirst <= length - maxSize ; indexFirst ++)
	{
		indexSecond = length - 1;
		while(indexSecond >= indexFirst)
		{
			if(s[indexSecond]==s[indexFirst])
			{
				printf("indexF:%d,indexS:%d,length:%d\n",indexFirst,indexSecond,length);
				if(checkIsHuiWen(s,indexFirst,indexSecond))
				{
					if(maxSize < indexSecond - indexFirst + 1)
					{
						maxSize = indexSecond - indexFirst + 1;
						maxClip = clipStr(s,indexFirst,maxSize) ;
					}
				}
			}
			indexSecond --;
		}	
	}
	return maxClip ;
}

 


int main()
{
	char test1 [5] = "babad";
//	char test2 [4] = "caba";
	printf("%s\n",longestPalindrome(test1));
//	printf("%s",longestPalindrome(test2));
	return 0;
}
