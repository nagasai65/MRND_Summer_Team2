#include<stdlib.h>
struct nodenum{
	nodenum* next;
	int value;
};
nodenum* createlist(int *arr,int len)
{
	nodenum *head = (nodenum*)malloc(sizeof(nodenum));
	head->value = arr[0];
	for (int i = 1; i < len;i++)
}