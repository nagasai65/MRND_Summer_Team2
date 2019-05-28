#include<stdio.h>
void spiral()
{
	int count = 0;
	int imin = 0, imax = 3, jmin = 0, jmax = 3;
	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int res[16] = { 0 };
	for (int count = 0; count < 16;)
	{
		int j = jmin;
		int i = imin;
		for (j; j <= jmax;j++)
		{
			res[count++] = arr[i][j];
		}
		imin++;
		for (--j,i++; i <= imax; i++)
		{
			res[count++] = arr[i][j];
		}
		jmax--;
		for (--i,--j; j  >=jmin; j--)
		{
			res[count++] = arr[i][j];
		}
		imax--;
		for (j++,i--; i >= imin; i--)
		{
			res[count++] = arr[i][j];
		}
		jmin++;

	}
	for (int i = 0; i < 16; i++)
		printf("%d,",res[i]);
}