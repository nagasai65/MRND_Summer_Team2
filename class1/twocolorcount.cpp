void two_color_count(int *arr, int len)
{
	int i, count = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == 0)
		{
			count++;
		}
	}
	for (i = 0; i < count; i++)
	{
		arr[i] = 0;
	}
	for (i = count; i < len; i++)
	{
		arr[i] = 1;
	}
}