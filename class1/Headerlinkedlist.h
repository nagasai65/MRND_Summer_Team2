#include<stdlib.h>
#include<stdio.h>

struct linkedlistnode * loop_in_list(struct linkedlistnode * head);

struct linkedlistnode
{
	int value;
	struct linkedlistnode * next;
};

struct linkedlistnode * new_linked_list_node(int value)
{
	struct linkedlistnode * node = NULL;
	node = (struct linkedlistnode *)malloc(sizeof(struct linkedlistnode));
	node->value = value;
	node->next = NULL;
	return node;
}

struct linkedlistnode * linked_list_generation(int *arr, int length)
{
	int i;
	struct linkedlistnode  * ptr, *head = NULL;
	if (length)
	{
		ptr = new_linked_list_node(arr[0]);
		head = ptr;
		for (i = 1; i < length; i++)
		{
			ptr->next = new_linked_list_node(arr[i]);
			ptr = ptr->next;
		}
	}
	return head;
}

void linked_list_parser(struct linkedlistnode * head)
{
	while (head)
	{
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
}
