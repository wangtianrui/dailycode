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
int main()
{
	struct ListNode * headL1 = NULL ;
	struct ListNode * headL2 = NULL ;
	headL1 = createNode(1 , headL1) ;
	headL1 = createNode(8 , headL1) ;
//	headL1 = createNode(3 , headL1) ;
//	
//	headL2 = createNode(5 , headL2) ;
//	headL2 = createNode(6 , headL2) ;
	headL2 = createNode(0 , headL2) ;
	
	show(headL1);
	show(headL2);
	
	struct ListNode * result = NULL ;
	result = addTwoNumbers(headL1,headL2);
	show(result);
	return 0;
}
