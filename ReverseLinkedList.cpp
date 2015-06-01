#include <iostream>
/*Definition for singly-linked list.*/
struct ListNode
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*�ǵݹ�汾*/
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
			q = p->next; //������һ�ڵ�
			p->next = head; //��ת
			head = p;
			p = q;
		}
		return head;
	}
};

/*�ݹ�汾/Recursive*/
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		//�ݹ���ڣ�1���սڵ㣬2���ڵ���һ�ڵ�Ϊ��
		if (head == NULL || head->next == NULL)
			return head; // head->next==NULL is the base case for recursion
		ListNode *nex = head->next;
		head->next = NULL;

		//�Եڶ����ڵ�Ϊͷ�ڵ�ִ�еݹ�
		ListNode *newHead = reverseList(nex);

		nex->next = head;
		return newHead;
	}
};
