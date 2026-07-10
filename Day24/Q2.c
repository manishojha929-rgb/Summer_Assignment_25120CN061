#include <stdio.h>
#include <string.h>

void compressString(const char *src, char *dst) 
{
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (i < len) 
    {
        dst[j++] = src[i];
        int count = 1;
        
        while (i + 1 < len && src[i] == src[i + 1]) 
        {
            count++;
            i++;
        }
        
        j += sprintf(&dst[j], "%d", count);
        i++;
    }
    dst[j] = '\0';
}

int main() 
{
    char str[] = "aaabbccccccd";
    char compressed[100];

    compressString(str, compressed);

    printf("Original: %s\n", str);
    printf("Compressed: %s\n", compressed);

    return 0;
}
