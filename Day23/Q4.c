#include <stdio.h>
#include <string.h>

char getMaxOccurringChar(char* str) 
{
    int count[256] = {0};
    int len = strlen(str);
    int max = 0;
    char result = '\0';

    for (int i = 0; i < len; i++) 
    {
        count[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < len; i++) 
    {
        if (count[(unsigned char)str[i]] > max) 
        {
            max = count[(unsigned char)str[i]];
            result = str[i];
        }
    }

    return result;
}

int main() 
{
    char str[] = "sample string";
    char maxChar = getMaxOccurringChar(str);
    
    printf("Maximum occurring character: %c\n", maxChar);
    
    return 0;
}
