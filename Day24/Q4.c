#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str) 
{
    if (str == NULL || *str == '\0') 
    {
        return;
    }

    int exists[256] = {0};
    int writeIndex = 0;

    for (int readIndex = 0; str[readIndex] != '\0'; readIndex++) 
    {
        unsigned char currentChar = (unsigned char)str[readIndex];
        
        if (exists[currentChar] == 0) 
        {
            exists[currentChar] = 1;
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }
    
    str[writeIndex] = '\0';
}

int main() 
{
    char testStr[] = "programming language";
    
    printf("Original: %s\n", testStr);
    removeDuplicates(testStr);
    printf("Modified: %s\n", testStr);
    
    return 0;
}
