#include "swapknodes.h"
#include<stdio.h>
#include<stdlib.h>
node* createloop()
{
	char arr[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	node* head = createlist(arr,9);
	node *end = head;
	while (end->next != NULL)
		end = end->next;
	node *curr = head;
	for (int i = 0; i < 5; i++)
	{
		curr = curr->next;
	}
	end->next = curr;
	return head;
}
void findmerge(node* head)
{
	node*slow=head, *fast=head;
	slow = slow->next;
	fast = fast->next->next;
	while (slow!=fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	node* merge = head;
	while (merge!=slow)
	{
		merge = merge->next;
		slow = slow->next;
	}
	printf("node at address %d,with value %c is merge point",&merge,merge->data);
}