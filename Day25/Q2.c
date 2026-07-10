#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[256];
    char str2[256];
    int freq1[256] = {0};
    int freq2[256] = {0};

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    for (int i = 0; str1[i] != '\0'; i++) 
    
    {
        freq1[(unsigned char)str1[i]]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) 
    {
        freq2[(unsigned char)str2[i]]++;
    }

    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 256; i++) 
    {
        if (freq1[i] > 0 && freq2[i] > 0) 
        {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("None");
    }
    printf("\n");

    return 0;
}
