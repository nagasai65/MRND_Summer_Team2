int power(int n, int a)
{
	if (n == 1)
		return a;
	int x = power(n / 2,a);
	if (n % 2 == 0)
		return x*x;
	else
		return x*x*a;
}