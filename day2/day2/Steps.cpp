#include<stdio.h>
int climb(int n, int k,int*arr)
{
	if (n <= 1)
		return 1;
	if (arr[n] != -1)
		return arr[n];
	int res = 0;
	for (int i = 1; i <= k; i++)
		res += climb(n - i, k,arr);
	arr[n] = res;
	return res;
}