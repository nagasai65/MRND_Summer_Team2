// ConsoleApplication3.cpp : Defines the entry point for the console application.
//
#include "spiral.h"
#include "stdafx.h"
#include"colorsort.h"
#include <stdlib.h>
#include "swapknodes.h"
#include"transpose.h"
#include"linkedlistloop.h"
#include"random.h"

char* tostring(int x)
{
	char *res = (char*)malloc(sizeof(char) * 10);
	int i = 0;
	while (x > 0)
	{
		res[i] = '0' + x%10;
		x = x / 10;
		i++;
	}
	res[i] = '\0';
	//number-reverse
	char temp;
	for (int j = 0; j < --i;j++)
	{
		temp = res[i];
		res[i] = res[j];
		res[j] = temp;
	}
	return res;
}


char* compress(char* str)
{
	char*num;
	int current = 0, comparission = 0, forward = 1, count = 1;
	while (str[forward] != '\0')
	{
		if (str[comparission] != str[forward])
		{
			if (count > 1)
			{
				num = tostring(count);
				for (int numpointer = 0; num[numpointer] != '\0'; numpointer++)
					str[++current] = num[numpointer];
				num = '\0';
			}
			comparission = forward++;
			count = 1;
			str[++current] = str[comparission];
		}
		else
		{
			count++;
			forward++;
		}
	}
	num = tostring(count);
	for (int numpointer = 0; num[numpointer] != '\0'; numpointer++)
		str[++current] = num[numpointer];
	str[++current] = '\0';
	return str;
}

void testcompress()
{
	char* x = (char*)malloc(30);
	printf("enterstring to compress\n");
	scanf("%s", x);
	compress(x);
	printf("%s\n", x);
}

int main()
{/*
	testcompress();
	testtwocolorsort();
	testtwocolorsort1();
	testtwocolorsort2();
	testthreecolorsort()
	createtransposetest();
	findmerge(createloop());
	spiral();
	testrandom();
	*/
	testswapknodes();
	
	//return 0;
}

