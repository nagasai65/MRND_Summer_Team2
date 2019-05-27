void two_color_swap(int *arr, int len)
{
	int starting_pointer = 0, ending_pointer = len-1, swapvar;
	while (starting_pointer < ending_pointer)
	{
		while (arr[starting_pointer] == 0)
			starting_pointer++;
		while (arr[ending_pointer] == 1)
			ending_pointer--;
		if (starting_pointer < ending_pointer)
		{
			swapvar = arr[starting_pointer];
			arr[starting_pointer] = arr[ending_pointer];
			arr[ending_pointer] = swapvar;
			starting_pointer++;
			ending_pointer--;
		}
	}
}