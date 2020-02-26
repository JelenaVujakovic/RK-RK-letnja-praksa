#include "rot13.h"
#include "ceasar.h"

int encryptROT13(const char* in, char* out)
{
	encryptCeasar(in, out, ROT13);
	return 1;
}

int decryptROT13(const char* in, char* out)
{
	encryptCeasar(in, out, ROT13);
	return 1;
}
