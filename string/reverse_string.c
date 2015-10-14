/*
  Reverse the order of the words in a string
*/
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "ctype.h"

char* reverse(char* s, char* e)
{
    char* r = s;
    char t = 0;
    int i = 0, j = (e-s); 

    if(s == NULL || e == NULL)
        return NULL;

    while(i < j)
    { 
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;j--;
    }

    return r;
}

char* reverseWordInString(char *s)
{
    if(s == NULL)
        return NULL; 

    char* r = reverse(s, s + strlen(s) - 1);
    int i = 0, j = 0; 
    bool startFound = false;
    
    while(s[i] != '\0')
    {
        if(isspace(s[i]) && (i != j))
        {
            reverse(&s[j], &s[i-1]);
            j = ++i; 
            startFound = false; 
        } 
        else if(isspace(s[i]))
        {
            i++; j++;
        }
        else if(startFound == false)
        {
            i++;
            startFound = true;
        }
        else 
        {
            i++;
        }
    }

    reverse(&s[j], &s[i-1]);
    return r;
}

int main()
{
    char string[] = "Good  Morning";
    printf("%s\n", reverseWordInString(string));
    return 0;
}
