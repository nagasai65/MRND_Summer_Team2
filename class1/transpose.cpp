#include<stdlib.h>

int ** transpose(int **arr, int m, int n)
{
	int i, j;
	int **res = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		res[i] = (int *)malloc(sizeof(int)*m);
	}
	for (i = 0; i < m; i++)
 	{
		for (j = 0; j < n; j++)
		{
			res[j][i] = arr[i][j];
		}
	}
	return res;
}