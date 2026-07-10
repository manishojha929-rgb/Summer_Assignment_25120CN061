#include <stdio.h>
#include <string.h>

void sortWords(char arr[][100], int n) 
{
    char temp[100];
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strlen(arr[j]) > strlen(arr[j + 1])) 
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() 
{
    char words[5][100] = {"banana", "apple", "kiwi", "strawberry", "fig"};
    int n = 5;

    sortWords(words, n);

    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
