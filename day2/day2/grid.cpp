#include<stdio.h>

int traversal(char grid[2][5], char*string,int strpointer, int direction, int length,int i,int j,int count,int row,int col,int initialr,int initialc)
{
	if (strpointer == length)
	{
		printf("%d,%d-%d,%d\n", initialr, initialc, i, j);
		return 1;
	}
	switch (direction) 
	{
	case 0:
		//up
		if (i - 1 >= 0 && string[strpointer] == grid[i - 1][j])
		{
			count+= traversal(grid, string, 2,1, length, i - 1, j,count,row,col,initialr,initialc);
		}
		//topright
		if (i - 1 >= 0 &&j+1<col&& string[strpointer] == grid[i - 1][j+1])
		{
			count += traversal(grid, string, 2, 2, length, i - 1, j + 1, count, row, col, initialr, initialc);
		}
		//right
		if (j + 1<col && string[strpointer] == grid[i][j + 1])
		{
			count += traversal(grid, string, 2, 3, length, i, j + 1, count, row, col, initialr, initialc);
		}
		//bottomright
		if (i + 1<row&&j + 1<col && string[strpointer] == grid[i + 1][j + 1])
		{
			count += traversal(grid, string, 2, 4, length, i + 1, j + 1, count, row, col, initialr, initialc);
		}
		//bottom
		if (i + 1<row && string[strpointer] == grid[i + 1][j])
		{
			count += traversal(grid, string, 2, 5, length, i + 1, j, count, row, col, initialr, initialc);
		}
		//bottomleft
		if (i + 1<row&&j - 1 >= 0 && string[strpointer] == grid[i + 1][j - 1])
		{
			count += traversal(grid, string, 2, 6, length, i + 1, j - 1, count, row, col, initialr, initialc);
		}
		//left
		if (j - 1 >= 0 && string[strpointer] == grid[i ][j-1])
		{
			count += traversal(grid, string, 2, 7, length, i , j-1, count, row, col, initialr, initialc);
		}
		//topleft
		if (i - 1 >= 0 && j - 1 >= 0 && string[strpointer] == grid[i - 1][j - 1])
		{
			count += traversal(grid, string, 2, 8, length, i - 1, j - 1, count, row, col, initialr, initialc);
		}
		return count;
		break;
	case 1:
		//up
		
		if (i - 1 >= 0 && string[strpointer] == grid[i - 1][j])
		{

			return traversal(grid, string, strpointer+1, 1, length, i - 1, j,count, row, col, initialr, initialc);
		}
		break;

	case 2:
		//top-right
		if (i - 1 >= 0&&j+1<col && string[strpointer] == grid[i - 1][j+1])
		{

			return traversal(grid, string, strpointer + 1, 2, length, i - 1, j+1,count, row, col, initialr, initialc);
		}
		break;

	case 3:
		//right
		if ( j + 1<col && string[strpointer] == grid[i ][j + 1])
		{

			return traversal(grid, string, strpointer + 1, 3, length, i , j + 1,count, row, col, initialr, initialc);
		}
		break;

	case 4:
		//bottomright
		if (i + 1 <row && j + 1<col && string[strpointer] == grid[i + 1][j + 1])
		{

			return traversal(grid, string, strpointer + 1, 4, length, i + 1, j + 1,count, row, col, initialr, initialc);
		}

		break;

	case 5:
		//bottom
		if (i + 1 < row && string[strpointer] == grid[i + 1][j ])
		{

			return traversal(grid, string, strpointer + 1, 5, length, i + 1, j,count, row, col, initialr, initialc);
		}

		break;

	case 6:
		//bottom-left
		if (i +1 <row && j-1>=0 && string[strpointer] == grid[i + 1][j - 1])
		{

			return traversal(grid, string, strpointer + 1, 6, length, i + 1, j - 1,count, row, col, initialr, initialc);
		}

		break;

	case 7:
		//left
		if (j - 1 >=0 && string[strpointer] == grid[i ][j-1])
		{

			return traversal(grid, string, strpointer + 1, 7, length, i , j-1 ,count, row, col, initialr, initialc);
		}

		break;

	case 8:
		//topleft
		if (i - 1 >= 0 && j -1 >=0 && string[strpointer] == grid[i - 1][j - 1])
		{

			return traversal(grid, string, strpointer + 1, 8, length, i - 1, j - 1,count, row, col, initialr, initialc);
		}

		break;

	}
}

void search(char grid[2][5], int rows, int cols, char*string)
{
	int len = 0;
	int occurences=0;
	while (string[len] != NULL)
		len++;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == string[0])
				occurences += traversal(grid, string, 1, 0, len, i, j,0, rows, cols, i, j);
		}
	}
	printf("\nnumber of occurencess =%d", occurences);
}
	/*
			if (string[0] == grid[i][j])
			{//down
				if (j + len < cols)
				{
					int flag = 1;
					int gpointer = j ;
					int stringpointer = 1;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[i][gpointer++])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//up
				if (j -len>=0)
				{
					int flag = 1;
					int gpointer = j -1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[i][gpointer--])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//left
				if (i - len>0)
				{
					int flag = 1;
					int gpointer = i-1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer--][j])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//right
				if (j + len<cols)
				{
					int flag = 1;
					int gpointer = i + 1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer++][j])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//bottomleft
				if (i+ len<rows&&j-len>=0)
				{
					int flag = 1;
					int gpointer1 =  i+1;
					int gpointer2 = j-1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer1++][gpointer2--])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//bottomright
				if (i+len<rows && j +len<cols)
				{
					int flag = 1;
					int gpointer1 = i + 1;
					int gpointer2 = j + 1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer1++][gpointer2++])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//topleft
				if (i - len >= 0&&j-len>=0)
				{
					int flag = 1;
					int gpointer1 = i - 1;
					int gpointer2 = j - 1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer1--][gpointer2--])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
				//topright
				if (i-len>=0&&j+len<cols)
				{
					int flag = 1;
					int gpointer1 = i -1;
					int gpointer2 = j + 1;
					int stringpointer = 2;
					while (string[stringpointer++] != '\0')
					{
						if (string[stringpointer] != grid[gpointer1--][gpointer2++])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
						occurences++;
					flag = 1;
				}
			}
		}
	}
	printf("%d",occurences);
	*/


