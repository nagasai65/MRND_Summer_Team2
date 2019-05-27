#include"Headerlinkedlist.h"
#include<stdlib.h>

struct linkedlistnode * k_node_reverse(struct linkedlistnode *pointer, int k)
{
	int count = 1;
	struct linkedlistnode * head = pointer, *cursor = pointer;
	struct linkedlistnode * next = NULL, *extra;
	while (pointer->next && count < k)
	{
		count++;
		pointer = pointer->next;
	}

	if (count == k)
	{
		next = head;
		head = head->next;
		count--;
		while (count)
		{
			cursor->next = head->next;
			extra = head->next;
			head->next = next;
			next = head;
			head = extra;
			count--;
		}
		return next;
	}
	else
		return cursor;
}

struct linkedlistnode * n_k_node_reverse(struct linkedlistnode * head, int k)
{
	int count = 0, l;
	struct linkedlistnode * start = NULL, *next = NULL, *prev = NULL;
	while (head)
	{
		l = k;
		next = head;
		while (l-- && next)
		{
			next = next->next;
		}
		if (start == NULL)
		{
			start = k_node_reverse(head, k);
			prev = start;
		}
		else
			prev->next = k_node_reverse(head, k);
		prev = head;
		head = next;
	}
	return start;
}