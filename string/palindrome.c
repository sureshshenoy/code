#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool isPalindrome(const char *s);

int main()
{
	printf(isPalindrome("malayalam") ? "palindrome \n" : "not palindrome \n");
	printf(isPalindrome("maverick")  ? "palindrome \n" : "not palindrome \n");
	printf(isPalindrome(NULL)        ? "palindrome \n" : "not palindrome \n");
	return 0;
}

bool isPalindrome(const char *s)
{
	bool status = true; 

	if(s == NULL)
		return false; 

	int i = 0;
	int j = strlen(s) - 1;

	while(i < j)
	{
		if(s[i++] != s[j--])
		{
			status = false;
			break;
		}
	}
	
	return status;
}
