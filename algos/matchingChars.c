/*
Write a function that takes two strings as arguments and returns a string 
containing only the characters found in both strings
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* matchingChars(const char* a, const char *b)
{
	if( a == NULL || b == NULL )
		return NULL; 
    
	int lenA = strlen(a);
	int lenB = strlen(b);
	int index = 0;
	int count = 0;
	char c = 0; 
	int j = 0;
    char* f = (char*)malloc(sizeof(char) * 255);

	// set flag in first pass 
    for(index = 0; index < lenA; index++)	
	{
		c = a[index];		
		f[c]++;
	}

	// increment only unique duplicates
    for(index = 0; index < lenB; index++)	
	{
		c = b[index];
		if(f[c] == 1)
		{
			f[c]++;
			count++;
		}
	}
	
	char* r = (char*)malloc(sizeof(char) * count);

	// grab unique matching chars
    for(index = 0; index < lenB; index++)	
	{
		c = b[index];
		if(f[c] > 1)
		{
			f[c]--;
			r[j++] = c;
		}
	}
		
	r[j] = '\0'; 

	free(f);
	return r;
}

int main()
{
	char a[] = "abba";
	char b[] = "bobcat";

	printf("String a: %s, String b: %s, Matching Chars: %s\n", a, b, matchingChars(a, b));
	return 0;
}
