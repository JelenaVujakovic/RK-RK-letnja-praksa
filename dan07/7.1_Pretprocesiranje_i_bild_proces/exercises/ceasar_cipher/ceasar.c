#include "ceasar.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int encryptCeasar(const char* in, char* out, int shift)
{
	int i = 0;
	int inLength = strlen(in);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			c = tolower(c);
			out[i] = ((c - 'a') + shift) % 26 + 'a';
		}
		else
		{
			out[i] = in[i];
		}
	}

	return 1;
}

int decryptCeasar(const char* in, char* out, int shift)
{
	int i = 0;
	int inLength = strlen(in);

	for (i = 0; i < inLength; i++)
	{
		char c = in[i];
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			c = tolower(c);
			if ((c = c - 'a' - shift) < 0)
			{
				c += 26;
			}
			out[i] = c % 26 + 'a';
		}
		else
		{
			out[i] = in[i];
		}
	}

	return 1;
}
