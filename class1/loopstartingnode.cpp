#include"linkedlistheader.h"

struct node * loop_in_list(struct node * head)
{
	struct node *slow = head, *fast = head;
	while (slow != fast && slow && fast)
	{
		slow = slow->next;
		if (fast->next)
		{
			fast = fast->next;
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	if (slow == NULL)
		return NULL;
	while (head != slow)
	{
		head = head->next;
		slow = slow->next;
	}
	return head;
}