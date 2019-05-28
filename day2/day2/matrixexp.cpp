#include<stdio.h>
#include<stdlib.h>
int** matrixmultiply(int**a, int**b)
{
	int **res = (int**)malloc(sizeof(int*) * 2);
	res[0] = (int*)malloc(sizeof(int) * 2);
	res[1] = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			res[i][j] = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}
int matrixfibo(int n)
{
	//int A[2][2] = { { 0, 1 }, { 1, 1 } };
	int** A = (int**)malloc(sizeof(int*) * 2);
	A[0] = (int*)malloc(sizeof(int) * 2);
	A[1] = (int*)malloc(sizeof(int) * 2);
	A[0][0] = 0;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 1;

	int** res = (int**)malloc(sizeof(int*)*2);
	res[0] = (int*)malloc(sizeof(int) * 2);
	res[1]=(int*)malloc(sizeof(int) * 2);
	res[0][0] = 1;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 1;

	while (n>0)
	{
		res = matrixmultiply(A, res);
		n--;
	}

		return (res[0][0]+res[0][1]);

}