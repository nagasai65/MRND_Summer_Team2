#include<stdlib.h>
#include<stdio.h>

enum direct { notset, top, down, left, right, topright, topleft, downright, downleft };

long count_using_recursion(char ** strarr, int rows, int cols, int indx, int indy, char * str, int ind, int startx, int starty, enum direct dirct)
{
	if (str[ind] == '\0')
	{
		printf("starting : %d  %d     ending : %d  %d\n", startx, starty, indx, indy);
		return 1;
	}
	int count = 0;
	int flag = 0;
	if (dirct == notset)
		flag = 1;
	if ((dirct == notset || dirct == right) && indy + 1 < cols && strarr[indx][indy + 1] == str[ind]){
		dirct = right;
		count += count_using_recursion(strarr, rows, cols, indx, indy + 1, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == down) && indx + 1 < rows && strarr[indx + 1][indy] == str[ind]){
		dirct = down;
		count += count_using_recursion(strarr, rows, cols, indx + 1, indy, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == downright) && indy + 1 < cols && indx + 1 < rows && strarr[indx + 1][indy + 1] == str[ind]){
		dirct = downright;
		count += count_using_recursion(strarr, rows, cols, indx + 1, indy + 1, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == top) && indy - 1 > -1 && strarr[indx][indy - 1] == str[ind]){
		dirct = top;
		count += count_using_recursion(strarr, rows, cols, indx, indy - 1, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == left) && indx - 1 > -1 && strarr[indx - 1][indy] == str[ind]){
		dirct = left;
		count += count_using_recursion(strarr, rows, cols, indx - 1, indy, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == topleft) && indx - 1 > -1 && indy - 1 > -1 && strarr[indx - 1][indy - 1] == str[ind]){
		dirct = topleft;
		count += count_using_recursion(strarr, rows, cols, indx - 1, indy - 1, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == topright) && indx - 1 > -1 && indy + 1 < cols && strarr[indx - 1][indy + 1] == str[ind]){
		dirct = topright;
		count += count_using_recursion(strarr, rows, cols, indx - 1, indy + 1, str, ind + 1, startx, starty, dirct);
	}
	if (flag)
		dirct = notset;
	if ((dirct == notset || dirct == downleft) && indx + 1 < rows && indy - 1 > -1 && strarr[indx + 1][indy - 1] == str[ind]){
		dirct = downleft;
		count += count_using_recursion(strarr, rows, cols, indx + 1, indy - 1, str, ind + 1, startx, starty, dirct);
	}
	return count;
}

long ocurrence(char ** strarr, int rows, int cols, char * str)
{
	if (str == NULL)
		return -1;
	int i, j, count = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (strarr[i][j] == str[0])
			{
				enum direct dirct = notset;
				count += count_using_recursion(strarr, rows, cols, i, j, str, 1,  i, j, dirct);
			}
		}
	}
	return count;
}