#include<stdio.h>
#include<stdlib.h>
int * twocolorsort(int* array, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == 1)
			count++;
	}
	for (int i = 0; i < len - count; i++)
	{
		array[i] = 0;
	}
	for (int i = len - count; i < len; i++)
	{
		array[i] = 1;
	}
	return array;
}
int * threecolorsort(int* array, int len)
{
	int count2 = 0;
	int count1 = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == 1)
			count1++;
		else if (array[i] == 2)
			count2++;
	}
	for (int i = 0; i < len - count1 - count2; i++)
	{
		array[i] = 0;
	}
	for (int i = len - count1 - count2; i < len - count2; i++)
	{
		array[i] = 1;
	}
	for (int i = len - count2; i < len; i++)
	{
		array[i] = 2;
	}
	return array;
}

int * twocolorsort1(int* array, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += array[i];
	}
	for (int i = 0; i < len - sum ; i++)
	{
		array[i] = 0;
	}
	for (int i = len - sum ; i < len; i++)
	{
		array[i] = 1;
	}
	return array;
}

int * twocolorsort2(int* array, int len)
{
	int start = 0, end = len - 1,count=0;
	while (true)
	{
		while (array[start] != 1)
		{
			start++;
			count++;
		}
		while (array[end] != 0)
		{
			count++;
			end--;
		}
		if (count >= len)
		{
			break;
			}
		array[start] = 0;
		array[end] = 1;

	}
	return array;
}

void testthreecolorsort()
{
	int arrlen;
	int* array = (int*)malloc(sizeof(int) * 30);
	printf("enter length of array\n");
	scanf("%d", &arrlen);
	printf("enterarray\n");
	for (int i = 0; i < arrlen; i++)
	{
		scanf("%d", &array[i]);
	}
	int *res = threecolorsort(array, arrlen);
	for (int i = 0; i < arrlen; i++)
		printf("%d", res[i]);
}

void testtwocolorsort()
{
	int arrlen;
	int* array = (int*)malloc(sizeof(int) * 30);
	printf("enter length of array\n");
	scanf("%d", &arrlen);
	printf("enterarray\n");
	for (int i = 0; i < arrlen; i++)
	{
		scanf("%d", &array[i]);
	}
	int *res = twocolorsort(array, arrlen);
	for (int i = 0; i < arrlen; i++)
		printf("%d", res[i]);
}
void testtwocolorsort1()
{
	int arrlen;
	int* array = (int*)malloc(sizeof(int) * 30);
	printf("enter length of array\n");
	scanf("%d", &arrlen);
	printf("enterarray\n");
	for (int i = 0; i < arrlen; i++)
	{
		scanf("%d", &array[i]);
	}
	int *res = twocolorsort1(array, arrlen);
	for (int i = 0; i < arrlen; i++)
		printf("%d", res[i]);
}
void testtwocolorsort2()
{
	int arrlen;
	int* array = (int*)malloc(sizeof(int) * 30);
	printf("enter length of array\n");
	scanf("%d", &arrlen);
	printf("enterarray\n");
	for (int i = 0; i < arrlen; i++)
	{
		scanf("%d", &array[i]);
	}
	int *res = twocolorsort2(array, arrlen);
	for (int i = 0; i < arrlen; i++)
		printf("%d", res[i]);
}