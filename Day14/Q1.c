#include <stdio.h>

int main() 
{
    int array[100];
    int search;
    int i;
    int n;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &array[i]);
    }

    printf("Enter a number to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) 
    {
        if (array[i] == search) 
        {
            printf("%d is found at index %d.\n", search, i);
            found = 1;
            break;
        }
    }

    if (found == 0) 
    {
        printf("%d is not present in the array.\n", search);
    }

    return 0;
}
