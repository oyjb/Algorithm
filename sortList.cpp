/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-06-25 13:51
 * Filename      : sortList.cpp
 * Description   : 
 * *******************************************************/
/**Definition of ListNode.*/
 struct ListNode
 {
 	int val;
  	ListNode *next;
 	ListNode(int x) : val(x),next(NULL);
 };
 
class Solution
{	
public:
	ListNode *sortList(ListNode *head)
	{
		if (!head || !head->next)//头结点为空或者只有一个结点
			return head;
		return mergeSort(head);
	}

	ListNode* mergeSort(ListNode *head)
	{
		if (!head || !head->next)
			return head;
		ListNode *p = head,*q = head,*pre = NULL;
		/*
		 * 找到链表中间节点
		 * 让p每次走一步，q每次走两步
		 * 并且记录p的前驱节点
		 */
		while (q && q->next != NULL)
		{
			q = q->next->next;
			pre = p;//记录p的前躯
			p = p->next;
		}

		pre->next = NULL;//从p节点处断开
		//recusive
		ListNode *lhalf = mergeSort(head);
		ListNode *rhalf = mergeSort(p);

		return merge(lhalf,rhalf);
	}

	ListNode* merge(ListNode *lh,ListNode *rh)
	{
		ListNode *temp = new ListNode(0);
		ListNode *p = temp;
		while (lh != NULL && rh != NULL)
		{
			if (lh->val <= rh->val)
			{
				p->next = lh;
				lh = lh->next;
			}
			else
			{
				p->next = rh;
				rh = rh->next;
			}
			p = p->next;
		}
		if (!lh) //如果左链表为空，则添加右链表到尾部,反之
			p->next = rh;
		else
			p->next = lh;
		p = temp->next;
		temp->next = NULL;
		delete temp;
		return p;
	}
};
