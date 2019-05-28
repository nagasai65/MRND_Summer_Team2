#include <stdlib.h>
#include <stdio.h>

struct dllnode{
	dllnode *next;
	dllnode *prev;
	int value;
};

dllnode* createdllist(int *arr, int len)
{
	dllnode *head = (dllnode*)malloc(sizeof(dllnode));
	head->prev = NULL;
	head->next = NULL;
	head->value = arr[0];
	dllnode* curr = head;

	for (int i = 1; i < len; i++)
	{
		dllnode *newnode = (dllnode*)malloc(sizeof(dllnode));
		newnode->value = arr[i];
		newnode->next = NULL;
		newnode->prev = curr;
		curr->next = newnode;

		curr = curr->next;
	}
	return head;
}

dllnode* merge(dllnode*l1,dllnode* l2)
{
	dllnode *l1pointer=l1;
	dllnode *l2pointer=l2;
	dllnode *start,*current;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->value < l2->value)
	{
		start = l1;
		l1 = l1->next;
		//l1->prev = NULL;
	}
	else
	{
		start = l2;
		l2 = l2->next;
		//l2->prev = NULL;
	}
	current = start;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->value < l2->value)
		{
			current->next = l1;
			l1->prev = current;
			l1 = l1->next;
			current = current->next;
			//l1->prev = NULL;
		}
		else
		{
			current->next = l2;
			l2->prev = current;
			l2 = l2->next;
			current=current->next;
			//l2->prev = NULL;
		}
	}
		while (l1 != NULL)
		{
			current->next = l1;
			l1->prev = current;
			l1 = l1->next;
			current = current->next;
			//l1->prev = NULL;
		}
		while (l2!=NULL)
		{
			current->next = l2;
			l2->prev = current;
			l2 = l2->next;
			current = current->next;
			//l2->prev = NULL;
		}
		return start;
	}


dllnode* getmidnode(dllnode* head)
{
	dllnode* start=head;
	int length=0;
	while (start->next!=NULL)
	{
		length++;
		start = start->next;
	}
	for (int i = length/2; i>0;i--)
	{
		start = start->prev;
	}
	start->prev->next = NULL;
	start->prev = NULL;
	return start;
}
dllnode* mergesort(dllnode* head)
{
	if (head->next != NULL)
	{
		dllnode* mid = getmidnode(head);
		dllnode *l1=mergesort(head);
		dllnode* l2=mergesort(mid);
		return merge(l1, l2);
	}
	return head;
}


void mergesortstart()
{
	int length;
	printf("enter length of array\n");
	scanf_s("%d", &length);

	int *arr = (int *)malloc(sizeof(int)*length);
	printf("enter array\n");
	for (int i = 0; i < length; i++)
		scanf_s("%d", &arr[i]);
	dllnode* head = createdllist(arr, length);
	
	dllnode* res = mergesort(head);
	while (res->next != NULL)
	{
		printf("%d", res->value);
		res = res->next;
	}
	printf("%d", res->value);
}