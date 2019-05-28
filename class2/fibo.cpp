#include<stdlib.h>
long long int fibo(long long int num, long long int * arr)
{
	if (arr[num] != 0)
		return arr[num];
	arr[num] = fibo(num - 1, arr) + fibo(num - 2, arr);
	return arr[num];
}

long long int fibo_main(long long int num)
{
	long long int * arr = (long long int *)calloc(num+1, sizeof(long long int));
	if (num < 2)
		return num;
	return fibo(num, arr);
}