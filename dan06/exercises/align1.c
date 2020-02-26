#include <stdio.h>

//#pragma pack(push)  /* push current alignment to stack */
//#pragma pack(1)     /* set alignment to 1 byte boundary */

typedef struct _example_struct
{
	unsigned char   char_a;
	unsigned int    uint_b;
	unsigned short  short_c;
	unsigned short  short_d;
//} example_struct;
} __attribute__ ((packed)) example_struct;

//#pragma pack(pop)   /* restore original alignment from stack */


int main(void)
{	
	char arr1[3];
	char arr2[1];
	example_struct ex_struct;
	
	printf("arr1     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr1),  &arr1,      ((int)(&arr1)%4)      ? "NO" : "YES");
	printf("arr2     size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(arr2),  &arr2,      ((int)(&arr2)%4)      ? "NO" : "YES");
	printf("struct   size %d  \taddr: %p (4-byte alligned: %s)\n", sizeof(example_struct), &ex_struct, ((int)(&ex_struct)%4) ? "NO" : "YES");
		
	return 0;
}
