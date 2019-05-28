long int number_of_ways_array(int pos, int k, int n, int *arr)
{
	if (pos == 0)
		return 1;
	if (pos < 0)
		return 0;
	long int i, count = 0;
	for (i = 0; i < k; i++)
	{
		count += number_of_ways_array(pos - arr[i], k, n, arr);
	}
	return count;
}

long int number_of_ways(int pos, int k, int n)
{
	if (pos == 0)
		return 1;
	if (pos < 0)
		return 0;
	long int i, count = 0;
	for (i = 1; i <= k; i++)
	{
		count += number_of_ways(pos - i, k, n);
	}
	return count;
}
long int stair_case(int n, int k)
{
	return number_of_ways(n, k, n);
}