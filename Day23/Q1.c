#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char *str) 
{
    int freq[256] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) 
    {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < len; i++) 
    {
        if (freq[(unsigned char)str[i]] == 1) 
        {
            return str[i];
        }
    }

    return '\0';
}

int main() 
{
    char str[] = "geeksforgeeks";
    char result = findFirstNonRepeating(str);

    if (result != '\0') 
    {
        printf("The first non-repeating character is: %c\n", result);
    } 
    else 
    {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}