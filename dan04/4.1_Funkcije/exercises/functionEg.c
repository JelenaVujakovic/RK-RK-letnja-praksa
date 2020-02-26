#include "functionEg.h"


long factorial(int n)
{
	return 1;
}

long fibonacci(long n)
{
	return 1;
}


int staticInFunction()
{
	static int i = 0;
	i++;
	{
		int j = 0;
		j = 5%i;
		i += j;

	}
	return i;
}
