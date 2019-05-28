// day2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include "recsum.h"
#include<map>

int main()
{/*
	//printf("%d",power(7,3));
	//test();
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
		arr[i] = -1;
	printf("%d", climb(4, 2,arr));


	int* arr = (int*)malloc(sizeof(int) * 10);
for (int i = 0; i < 10; i++)
	arr[i] = -1;
	printf("%d", fibo(6, arr));
	//
	int *nlarray = (int*)malloc(sizeof(int) * 30);
	//nlimit(3, nlarray, 0);
*/
	int *ndarray = (int*)malloc(sizeof(int) * 30);

	int *previous = (int*)malloc(sizeof(int) * 30);
	ndarray[0] = 1;
	ndarray[1] = 3;
	ndarray[2] = 5;
	ndarray[3] = 7;
	ndist(4,ndarray,previous,0,4);

// mergesortstart();
	//printf("%d", matrixfibo(5));
	
	/*
	char **grid=(char**)malloc(sizeof(char*)*2);
	grid[0] = (char*)malloc(sizeof(char) * 5);
	grid[1] = (char*)malloc(sizeof(char) * 5);
	strcpy(grid[0], "hihihi");
	strcpy(grid[0], "hihih");
	strcpy(grid[1], "eehhee");
	*/
	char grid[2][5] = { { 'h', 'i', 'h', 'i', 'h' }, { 'e', 'e', 'h', 'e', 'e' } };
	//search(grid, 2,5, "hi");
	char rev[] = { '1', '2', 'E', 'h', 'S', '9', 'L', '8', '6' };
	ndistrev(4, ndarray, previous, 0, 4,rev);
	return 0;
}

