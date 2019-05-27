#include<stdio.h>
#include<stdlib.h>

void two_color_count(int *arr, int len);
void two_color_sum(int *arr, int len);
void two_color_swap(int *arr, int len);

void parse_1d_array(int * arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void count_method_helper()
{
	int i, len;
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	parse_1d_array(arr, len);
    two_color_count(arr, len);
	parse_1d_array(arr, len);
}

void sum_method_helper()
{
	int i, len;
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	parse_1d_array(arr, len);
	two_color_sum(arr, len);
	parse_1d_array(arr, len);
}

void swap_method_helper()
{
	int i, len;
	scanf("%d", &len);
	int *arr = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	parse_1d_array(arr, len);
	two_color_swap(arr, len);
	parse_1d_array(arr, len);
}