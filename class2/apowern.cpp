#include<stdlib.h>
#include<math.h>


long long int power(long long int num, long long int powe)
{
	if (powe > 0)
	{	
		return (num * power(num, powe-1))%((int)pow((double)10,9)+7);
	}
	if (powe)
		return 0;
	return 1;
}