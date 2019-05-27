#include "doublelinkedlistHelper.h"

struct node * reverse_linked_list(struct node  * head, struct node *prev)
{
	struct node * next = head->next;
	head->next = prev;
	if (next)
		reverse_linked_list(next, head);
	else
		return head;
}