#include<stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];   
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;    
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void permutations(int * arr, int actuallen, int level, int *res)
{
	if (level == 0)
	{
		int i;
		for (i = 0; i < actuallen; i++)
		{
			printf("%d", res[i]);
		}
		printf("\n");
		return;
	}
	int i, val;
	for (i = 0; i <actuallen; i++)
	{
		if (arr[i] != -1)
		{
			val = arr[i];
			res[actuallen - level] = arr[i];
			arr[i] = -1;
			permutations(arr, actuallen, level - 1, res);
			arr[i] = val;
		}
	}
}

void permutations_main()
{
	int arr[] = { 1, 4, 3, 4, 2 };
	int res[5];
	int actuallen = 5, len = 5;
	int i, j = 0;
	quickSort(arr, 0, 4);
	for (i = 0; i < len-1; i++)
	{
		if (arr[i] != arr[i + 1])
		{
			arr[j++] = arr[i];
			arr[j] = arr[i + 1];
		}
		else
		{
			actuallen--;
		}
	}
	permutations(arr, actuallen, actuallen, res);
}