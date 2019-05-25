void triple_color_sort(int *arr, int len)
{
	int zero_count = 0, one_count = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == 0)
			zero_count++;
		else if (arr[i] == 1)
			one_count++;
	}
	for (i = 0; i < zero_count; i++)
		arr[i] = 0;
	for (i = zero_count; i < zero_count + one_count; i++)
		arr[i] = 1;
	for (i = zero_count + one_count; i < len; i++)
		arr[i] = 2;
}