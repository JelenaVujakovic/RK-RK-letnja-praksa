#include <stdio.h>
#include <stdlib.h>

extern int sumAsm(int, int);
extern void printMessage();

int main(void)
{
	int a =10;
	int b = 3;
	int c = 0;

	printf("=============================================\n");
	printf("Exercise1 - Embedded functions  \n");
	printf("=============================================\n");

	// Embedding assembly code - xor swap function
	asm(" \
		eor  %0, %0, %1 \n\
		eor  %1, %1, %0 \n\
		eor  %0, %0, %1 \n"
		:"+r"(a), "+r"(b)
		:"r"(a), "r"(b)
		);
	printf("values of variables after xor swap function\n");
	printf("a = %d, b = %d, c = %d \n\n", a, b, c);

	printf("=============================================\n");
	
	// Embedding assembly code - swap function using intermediary register
	asm(" \
		mov  %%r0, %0 \n\
		mov  %0, %1 \n\
		mov  %1, %%r0 \n"
		:"+r"(a), "+r"(b)
		:
		:"r0"
		);
	printf("values of variables after second swap function\n");
	printf("a = %d, b = %d, c = %d \n\n", a, b, c);

	printf("=============================================\n");

	// Embedding assembly code - c = a + b
	printf("values of variables after adding\n");
	asm ("add  %0, %[operand1],%2; "
		:"=r"(c)
		:[operand1] "r"(a), "r"(b)
	);
	printf("a = %d, b = %d, c = %d\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function with parameters
	a = 0x10;
	b = 0x20;
	c = sumAsm(a, b);
	printf("values of variables after sumAsm function call\n");
	printf("a = %d, b = %d, c = %d\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function without paramaters
	printf("printMessage function call       \n");
	printMessage();

	return EXIT_SUCCESS;
}
