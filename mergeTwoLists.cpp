#include "stdafx.h"

#include "mergeTwoLists.h"

ListNode *Solution21::mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode* node = new ListNode(0);
	ListNode* p = node;
	ListNode* h = p;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val > l2->val)
		{
			p->next = l2;
			l2 = l2->next;
		}
		else
		{
			p->next = l1;
			l1 = l1->next;
		}
		p = p->next;
	}
	if (l1 != NULL)
		p->next = l1;
	if (l2 != NULL)
		p->next = l2;
	return h->next;

}