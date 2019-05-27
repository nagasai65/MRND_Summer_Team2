#include<stdio.h>
#include<stdlib.h>

int ** transpose(int **arr, int m, int n);

void traverse_2d_array(int **arr, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void transpose_2d_array_testing_helper()
{
	int rows, cols, i, j;
	scanf("%d %d", &rows, &cols);
	int **arr = (int **)malloc(rows * sizeof(int *));
	for (i = 0; i < rows; i++)
	{
		arr[i] = (int *)malloc(sizeof(int)*cols);
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	traverse_2d_array(arr, rows, cols);
	int ** ptr = transpose(arr, rows, cols);
	traverse_2d_array(ptr, cols, rows);
}