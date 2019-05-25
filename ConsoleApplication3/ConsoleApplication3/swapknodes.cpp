#include<stdio.h>
#include<stdlib.h>
#include"swapknodes.h"


node* createlist(char *arr, int k)
{
	node *head = (node *)malloc(sizeof(node));
	head->data = arr[0];
	head->next = NULL;
	node * start=head;
	for (int i = 1; i < k;i++)
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->data = arr[i];
		newnode->next = NULL;
		start->next = newnode;
		start=newnode;
	}
	return head;
}
node* reverse(node* head)
{
	node *t1, *t2,*newstart;
	newstart = head;
	t1 = head->next;
	t2 = t1->next;
	head->next = NULL;
	while (t2 != NULL)
	{
		t1->next = newstart;
		newstart = t1;
		t1 = t2;
		t2 = t2->next;
	}
	t1->next = newstart;
	return t1;
}
node *foo(int k,node* head)
{
	int flag = 1;
	node* revstart=head;
	node *start=head;
	if (head == NULL)
		return NULL;
	for (int i = 1; head!= NULL;i++)
	{
		if (i%k==0)
		{
			head = head->next;
			node* stop = revstart;
			while (stop->next != head)
				stop = stop->next;
			stop->next = NULL;
			revstart = reverse(start);
			node *connect = revstart;
			while (connect->next != NULL)
				connect = connect->next;
			connect->next = head;
			if (flag)
			{
				flag = 0;
				node *temp = start;
				start = revstart;
				revstart = temp;
			}
			revstart = head;
		}
		else{
			head = head->next;
		}
	}
	return start;
}

void testswapknodes()
{
	node *curr;
	char list[7] = { '1', '2', '3', '4', '5', '6', '7' };
	node *head = createlist(list, 7);
	/*head = foo(7, head);
	curr = head;
	while (curr!=NULL)
	{
		printf("%c->", curr->data);
		curr = curr->next;
	}
	printf("/n");
	*/head = createlist(list, 7);
	head = foo(3, head);
	curr = head;
	while (curr != NULL)
	{
		printf("%c->", curr->data);
		curr = curr->next;
	}
}
