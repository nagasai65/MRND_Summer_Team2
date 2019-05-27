#include<string.h>

int num_to_string(char *input, int count, int index)
{
	int len = 0, num = count, i = 1;
	if (count > 1)
	{
		while (count){
			len++;
			count /= 10;
		}
		while (num){
			input[index + len - i] = '0' + num % 10;
			num = num / 10;
			i++;
		}
	}
	return len;
}

void compress_string(char * str)
{
	if (str != NULL)
	{
		int length = strlen(str);
		int i, j = 0;
		int count = 0;
		char c;
		for (i = 0; i < length; i++)
		{
			c = str[i];
			count = 1;
			str[j++] = c;
			while (str[i + 1] == c)
			{
				count++;
				i++;
			}
			j += num_to_string(str, count, j);
		}
		str[j] = '\0';
	}
}