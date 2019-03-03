* Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

  You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

  **Example:**

   ```text
  Given nums = [2, 7, 11, 15], target = 9,
  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
   ```

  **Solution:**

  ```c
  int * twoSum(int *nums,int numsSize,int target)
  {
  	int i , j ;
  	int * result = (int *)malloc(sizeof(int)*2);
  	for(i = 0 ; i < numsSize ; i++)
  	{
          //注意这里不要从0开始，减少次数
  		for(j = i + 1  ; j < numsSize ; j++)
  		{	
  			if(nums[i] + nums[j] == target)
  			{ 
  				result[0] = i ;
  				result[1] = j ;
  				return result;
  			}
  		}
  	}
  	return result;
  }
  ```

* You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  **Example:**

  ```
  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
  ```

  **Solution:**

  ```c
  //加法
  //难点：遇十进一的问题
  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
  {
  	struct ListNode * pre = NULL ;
  	struct ListNode * next = NULL ;
  	struct ListNode * result = NULL ;
  	int ten = 0;
  	while(l1||l2||ten)
  	{
  		struct ListNode * temp = (struct ListNode*)malloc(sizeof(struct ListNode));
  		temp->val = 0 ;
  		temp->next = NULL ;
  		int sum = 0;
  		if(l1 && l2)
  		{
  			sum = l1->val + l2->val + ten;
  			l1 = l1->next ;
  			l2 = l2->next ;
  		}
  		else if(l1)
  		{
  			sum = l1->val + ten ;
  			l1 = l1->next ;
  		}
  		else if(l2)
  		{
  			sum = l2->val + ten ;
  			l2 = l2->next ;
  		}
  		else if(ten)
  		{
  			sum = ten ;
  		}
  		ten = 0;
  		if(sum >= 10)
  		{
  			temp->val += (sum - 10);
  			ten = 1 ;
  		}
  		else
  		{
  			temp->val += sum ;
  		}
  		if(result == NULL)
  		{
  			result = temp;
  		}
  		else
  		{
  			struct ListNode * p = result;
  			while(p->next)
  			{
  				p = p->next;
  			}
  			p->next = temp ;
  		}
  	}
  	return result ;
  }
  ```

  * Given a string, find the length of the **longest substring** without repeating characters.

    **Example 1:**

    ```
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 
    ```

    **Example 2:**

    ```
    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    ```

    **Example 3:**

    ```
    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3. 
                 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
    ```

    **Solution:**

    ```c
    //字符串动态匹配的问题。
    //难点：C语言数组动态扩充
    int lengthOfLongestSubstring(char* s)
    {
    	int i , j ;
    	int index = 0 ;
    	int length = 0 ;
    	int elementSize = 0 ;
    	char * elements = NULL ;
    	char * temps = NULL ;
    	int max = 0;
    	int location ;
    	while(s[index]!='\0')
    	{
    		int content = 0;
    		for( i = 0 ; i < elementSize ; i ++)
    		{
    			if(elements[i]==s[index])
    			{
    				location = i ;
    				content = 1 ;
    				break ;
    			}
    		}
    		if(content==0)
    		{
    			elementSize += 1 ;
    			if(elements)
    			{
    				temps = (char *)malloc(sizeof(char)*elementSize);
    				for(i = 0 ; i < (elementSize - 1) ; i++)
    				{
    					temps[i] = elements[i];
    				}
    				elements = temps ;
    			}
    			else
    			{
    				elements = (char *)malloc(sizeof(char)*elementSize);
    			}
    			elements[elementSize - 1] = s[index];
    		}
    		else
    		{
    			int newSize = elementSize - i ;
    			char * temps = (char *)malloc(sizeof(char)*(newSize));
    			j = 0;
    			for(i = location + 1  ; i < location + newSize ; i++ )
    			{				
    				temps[j] = elements[i];
    				j++;
    			}
    			temps[j] = s[index];
    			elementSize = newSize ; 
    			elements = temps ;			
    		}
    		index ++;
    		if(max < elementSize)
    		{
    			max = elementSize ;
    		}
    	}
    	return max ;
    }
    ```

  * There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    You may assume **nums1** and **nums2** cannot be both empty.

    **Example 1:**

    ```
    nums1 = [1, 3]
    nums2 = [2]
    
    The median is 2.0
    ```

    **Example 2:**

    ```
    nums1 = [1, 2]
    nums2 = [3, 4]
    
    The median is (2 + 3)/2 = 2.5
    ```

    **Solution：**

    ```c
    #include<stdio.h>
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
    //总结：每次一定要仔细思考题目，把所有的可能性考虑周到后列出来，然后找其中的共同点等。不要拿着题就开始写，事倍功半。
    //解题思路总结：涉及到一个数数问题，数组下标和数数之间的关系！index++ 就数了一个。那么下次比的就是没有数过的（关键），然后就是C语言中的数组越界问题，他不会报错，会瞎鸡巴给随机数，所以一定要时刻index和size比较，比较后再操作！
    ```

  * Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

    **Example 1:**

    ```
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    ```

    **Example 2:**

    ```
    Input: "cbbd"
    Output: "bb"
    ```

    **Solution：**

    ```c
    /*
    检查是否是回文
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
    		while(indexSecond - indexFirst >= maxSize)
    		{
    			if(s[indexSecond]==s[indexFirst])
    			{
    				printf("indexF:%d,indexS:%d,length:%d\n",indexFirst,indexSecond,length);
    				if(checkIsHuiWen(s,indexFirst,indexSecond))
    				{
    					maxSize = indexSecond - indexFirst + 1;
    					maxClip = clipStr(s,indexFirst,maxSize) ;
    				}
    			}
    			indexSecond --;
    		}	
    	}
    	return maxClip ;
    }
    
    /*
    总结： ①字符串复制：malloc时要length+1 ,最后一位放'\0' ！
    	  ②字符串临时变量：不要盲目使用malloc，合理使用star和length进行临时保存
      	  ③在处理“最长”等问题时，合理使用maxSize来减少循环次数
     	  ④字符串通过首尾坐标计算长度时一定要+1
    */
     
    ```
