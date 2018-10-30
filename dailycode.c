#include<stdio.h>

int * twoSum(int *nums,int numsSize,int target)
{
	int i , j ;
	int big ;
	int * result = (int *)malloc(sizeof(int)*2);
	
	for(i = 0 ; i < numsSize ; i++)
	{
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

struct ListNode
{
	int val;
	struct ListNode *next ;
};


struct ListNode * createNode(int val , struct ListNode * head)
{
	struct ListNode * temp  = (struct ListNode *)malloc(sizeof(struct ListNode));
	temp->val = val;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
	}
	else
	{
		struct ListNode * p ;
		p = head ;
		while(p->next)
		{
			p = p->next ;
		}
		p->next = temp;
	}
	return head;
}

void show(struct ListNode * head)
{
	while(head)
	{
		printf("%d->",head->val);
		head = head->next ;
	}
	printf("\n");
}
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
void showString(char * s, int size)
{
	int index = 0;
	for(; index < size ; index++)
	{
		printf("%c",s[index]);
	}
	printf("\n");
}

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

int main()
{
	char * input = "nfpdmpi";
	printf("%d\n",lengthOfLongestSubstring(input));
	return 0;
}
