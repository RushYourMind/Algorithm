#include "stdafx.h"
#include "reverseKGroup.h"


ListNode* Solution25::reverseKGroup(ListNode *head, int k)
{
	ListNode* h(0);
	h->next = head;
	ListNode*p = h;
	while (p->next != NULL)
	{
		ListNode*q = p;
		int i = 0;
		while (q->next != NULL && i< k)
			q = q->next;
		ListNode* tempp = NULL;
		tempp = p->next;
		p->next = q;
		p = tempp;
		while (tempp != q)
		{
			ListNode* temp = tempp->next;
			tempp->next = q->next;
			q->next = tempp;
			tempp = temp;
		}
	}
	return h->next;
}
