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
