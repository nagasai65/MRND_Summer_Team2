#include<stdlib.h>
int sum_of_array(int * arr, int n)
{
	if (arr==NULL || n==0 )
		return 0;
	return arr[n] + sum_of_array(arr, n-1);
}

