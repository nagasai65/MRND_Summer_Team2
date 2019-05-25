#include<stdio.h>
#include<stdlib.h>
int **trans(int** matrix,int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	int ** nmatrix = (int**)malloc(sizeof(int*)*col);
	for (int i = 0; i < col; i++)
		nmatrix[i] = (int*)malloc(sizeof(int)*row);

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			nmatrix[i][j] = matrix[j][i];
		}
	}
	return nmatrix;
}
void createtransposetest()
{
	int row = 2, col = 3;
	int ** matrix = (int**)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; i++)
		matrix[i] = (int*)malloc(sizeof(int)*col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf("%d", &matrix[i][j]);
	}
	int **res = trans(matrix, row, col);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%d",res[i][j]);
		}
		printf("\n");
	}
}