#include<stdio.h>
#include<map>
using namespace std;


long sumrec(int* arr,int len)
{
	return len > 1 ? arr[0] + sumrec(&arr[1], --len) : arr[0];
}

void test()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("%d",sumrec(arr,5));
}

long fibo(long a,int* arr)
{
	if (a < 0)
		printf("error");
	if (arr[a]!=-1)
		return arr[a];
	if (a == 1 || a == 0)
		return a;
	arr[a]=fibo(a-1,arr)+fibo(a-2, arr);
	return arr[a];
}


void  nlimit(int limit,int *arr,int curr){
	if (curr == limit)
	{
		for (int i = 0; i < limit; i++)
			printf("%d", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 10; i++)
		{
			arr[curr] = i;
			nlimit(limit, arr, curr + 1);
		}
}


void  ndist(int limit, int *availablearr, int *prevchoice, int prevpointer, int availablelength){
	if (prevpointer == limit)
	{
		for (int i = 0; i < limit; i++)
			printf("%d", prevchoice[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < availablelength; i++)
	{
		prevchoice[prevpointer] = availablearr[i];
		for (int j = i; j < availablelength;j++)
		{
			availablearr[j] = availablearr[j + 1];
		}
		ndist(limit, availablearr, prevchoice,prevpointer + 1,availablelength-1);
		for (int j = availablelength; j>i; j--)
		{
			availablearr[j] = availablearr[j-1 ];
		}
		availablearr[i] = prevchoice[prevpointer];
	}
}

void  ndistrev(int limit, int *availablearr, int *prevchoice, int prevpointer, int availablelength,char* rev){
	if (prevpointer == limit)
	{
		for (int i = 0; i < limit; i++)
			printf("%c", rev[prevchoice[i]-1]);
		printf("\n");
		return;
	}
	for (int i = 0; i < availablelength; i++)
	{
		prevchoice[prevpointer] = availablearr[i];
		for (int j = i; j < availablelength; j++)
		{
			availablearr[j] = availablearr[j + 1];
		}
		ndistrev(limit, availablearr, prevchoice, prevpointer + 1, availablelength - 1,rev);
		for (int j = availablelength; j>i; j--)
		{
			availablearr[j] = availablearr[j - 1];
		}
		availablearr[i] = prevchoice[prevpointer];
	}
}