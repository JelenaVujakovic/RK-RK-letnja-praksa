#include <stdio.h>
#include <stdlib.h>
#include "functionEg.h"

int main(void)
{
	int i;
	
	// Recursive functions
	printf("\n");
	printf("Fibonacci number 14 is %ld\n", fibonacci(14));
	printf("Factorial of 10 is %ld\n", factorial(10));

	// Static variable inside the function
	printf("\nExample of static used in function:\n");
	for (i=0; i<5; i++)
	{
		printf("ret = %d\n",staticInFunction());
	}

	return EXIT_SUCCESS;
}
