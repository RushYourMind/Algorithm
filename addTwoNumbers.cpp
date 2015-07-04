#include "stdafx.h"
#include "addTwoNumbers.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

ListNode* Solution2::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int last = 0;
	ListNode* returnNode = new ListNode(0), *cur = returnNode;
	while (l1 != NULL || l2 !=NULL)
	{
		int value1 = getNodeValue(l1);
		int value2 = getNodeValue(l2);
		int sum = value1 + value2 + last;
		int value = sum % 10;
		last = sum / 10;
		ListNode* node = new ListNode(value);
		cur->next = node;
		cur = node;


		if(l1!=NULL)
			l1 = l1->next;
		if(l2!=NULL)
			l2 = l2->next;
	}
	if (last > 0)
	{
		ListNode* node = new ListNode(last);
		cur->next = node;
	}
	return returnNode->next;
}


int Solution2::getNodeValue(ListNode* node)
{
	int r = 0;
	if (node != NULL)
	{
		r = node->val;
	}
	return r;
}
