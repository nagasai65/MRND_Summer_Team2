#include<stdio.h>
#include<stdlib.h>

void triple_color_sort(int *arr, int len);

void one_dimensional_array_traversal(int * arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void sort_method_helper()
{
	int i, len;
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	one_dimensional_array_traversal(arr, len);
	triple_color_sort(arr, len);
	one_dimensional_array_traversal(arr, len);
}