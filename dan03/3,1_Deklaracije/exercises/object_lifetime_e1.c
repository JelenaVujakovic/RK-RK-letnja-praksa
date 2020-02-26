#include <stdio.h>
#include <stdlib.h>

int foo(int x);

int main(void)
{
	printf("Local variable scope\n");
	int x;

	x = 42;
	foo(x);
	printf("After calling foo: x = %d\n", x);

	return EXIT_SUCCESS;
}

int foo(int x)
{
	x = 101;
	printf("Inside foo: x = %d\n", x);
	return x;
}
