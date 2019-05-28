void two_color_sum(int *arr, int len)
{
	int i, count = 0;
	for (i = 0; i < len; i++)
	{
		count += arr[i];
	}
	for (i = 0; i < len-count; i++)
	{
		arr[i] = 0;
	}
	for (i = len-count; i < len; i++)
	{
		arr[i] = 1;
	}
}