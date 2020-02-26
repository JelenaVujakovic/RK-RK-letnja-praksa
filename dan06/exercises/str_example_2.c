#include <string.h>
#include <stdio.h>

typedef struct _my_struct
{
	char text[20];
	int num;
} my_struct;

int main()
{
	my_struct ms;
	char strBuf[100] = "This text is too long for struct member text";
	ms.num = 55555;

	// Error situation (stack problem)
	printf("\nCopying longer string to shorter\n");
	char* ptr = strcpy(ms.text, strBuf);
	printf("my_struct text=%s, num=%d\n", ptr, ms.num);


	// Check if strings are equal
	printf("\nComparing two strings\n");
	char str1[20] = "This is text 1";
	char str2[20] = "This is text 2";
	if (strcmp(str1, str2) != 0)
	{
		printf("Strings are equal\n");
	}
	else
	{
		printf("Strings are not equal\n");
	}

	// Tokenizing
	printf("\nTokenizing string by space delimiter\n", s);
	char* s = "one two three four five";
	printf("string for tokenizing: \"%s\" \n", s);
	
	char* token = strtok(s, " ");
	printf("after 1st step, string is: \"%s\" \n", s);
	
	printf("token: %s\n", token);
	while (token != NULL)
	{
	    token = strtok(NULL, ".");
	    printf("token: %s\n", token);
	}

	return 1;
}
