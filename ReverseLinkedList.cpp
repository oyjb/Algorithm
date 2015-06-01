#include <iostream>
/*Definition for singly-linked list.*/
struct ListNode
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*非递归版本*/
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL)
			return NULL;
		ListNode *p, *q;
		p = head->next;
		head->next = NULL;
		while (p != NULL)
		{
			q = p->next; //保存下一节点
			p->next = head; //逆转
			head = p;
			p = q;
		}
		return head;
	}
};

/*递归版本/Recursive*/
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		//递归出口：1、空节点，2、节点下一节点为空
		if (head == NULL || head->next == NULL)
			return head; // head->next==NULL is the base case for recursion
		ListNode *nex = head->next;
		head->next = NULL;

		//以第二个节点为头节点执行递归
		ListNode *newHead = reverseList(nex);

		nex->next = head;
		return newHead;
	}
};
