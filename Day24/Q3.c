#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char str[1000];
    char longest[1000] = "";
    char current[1000] = "";
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    if (fgets(str, sizeof(str), stdin) == NULL) 
    {
        return 1;
    }

    while (str[i] != '\0') 
    {
        if (isalnum((unsigned char)str[i])) 
        {
            current[j++] = str[i];
        } 
        else 
        {
            if (j > 0) 
            {
                current[j] = '\0';
                if (strlen(current) > strlen(longest)) 
                {
                    strcpy(longest, current);
                }
                j = 0;
            }
        }
        i++;
    }

    if (j > 0) 
    {
        current[j] = '\0';
        if (strlen(current) > strlen(longest)) 
        {
            strcpy(longest, current);
        }
    }

    if (strlen(longest) > 0) 
    {
        printf("Longest word: %s\n", longest);
        printf("Length: %lu\n", (unsigned long)strlen(longest));
    } 
    else 
    {
        printf("No valid words found.\n");
    }

    return 0;
}
