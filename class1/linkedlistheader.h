#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};

struct node * loop_in_list(struct node * head);

struct node * new_linkedlist_node(int value)
{
	struct node * ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}

struct node * linked_list_generation(int * arr, int len)
{
	if (len)
	{
		struct node * head, *ptr;
		head = new_linkedlist_node(arr[0]);
		ptr = head;
		for (int i = 1; i < len; i++)
		{
			ptr->next = new_linkedlist_node(arr[i]);
			ptr = ptr->next;
		}
		return head;
	}
	return NULL;
}

void loopstartingnode_testing_helper()
{
	int i, len;
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	struct node * ptr = linked_list_generation(arr, len);
	struct node * temp = ptr, *parser = ptr;
	int count = len / 2;
	while (count--)
	{
		temp = temp->next;
	}
	parser = temp;
	while (parser->next)
	{
		parser = parser->next;
	}
	parser->next = temp;
	ptr = loop_in_list(ptr);
	printf("%d   %d\n", temp, ptr);
}