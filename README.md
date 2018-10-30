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
