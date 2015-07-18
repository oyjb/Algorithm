/**********************************************************
 * Author        : oyjb
 * Email         : jbouyang@126.com
 * Last modified : 2015-07-18 19:21
 * Filename      : PalindromeLinkedList.cpp
 * Description   : copy right for oyjb
 * *******************************************************/
#include <iostream>
using namespace std;

/*
 * Definition for singly-linked list
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

class Solution
{
public:
	/*--利用快慢指针的思想定位链表中间节点位置--*/
	bool isPalindrome(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return true;

		/*--slow为慢指针一次走一步，fast为快指针一次走两步--*/
		ListNode *slow = head;
		ListNode *fast = head;

		/*--考虑到链表长度的奇偶性，最终的fast指针有两种停留位确定while循环结束的条件--*/
		while (fast->next != NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		/*--无论slow和fast停留在何处，slow指针的下一个位置开始均代表链表后半部分，因此统一处理--*/
		ListNode *second = ReverseList(slow->next);
		
		/*--此时，second指针代表后半部分链表的逆序，因此从head位置开始与second位置开始比较判断是否时回文--*/
		ListNode *first = head;
		while (second != NULL)
		{
			if (first->val != second->val)
				return false;
			first = first->next;
			second = second->next;
		}
		return true;
	}

	/*--非递归的就地逆转单链表--*/
	ListNode *ReverseList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *current = head->next;
		head->next = NULL; //断开head头节点，开始逆转
		ListNode *nex;
		while (current != NULL)
		{
			nex = current->next; //保存下一个节点
			current->next = head; //逆转
			head = current; //更新逆转后的头节点
			current = nex;
		}
		return head;
	}
};
