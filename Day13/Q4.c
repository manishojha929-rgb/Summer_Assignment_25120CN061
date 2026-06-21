#include <stdio.h>

int main() 
{
    int size;
    int even_count = 0;
    int odd_count = 0;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) 
    {
        return 1;
    }

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            return 1;
        }
    }

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] % 2 == 0) 
        {
            even_count++;
        } 
        else 
        {
            odd_count++;
        }
    }

    printf("Total even elements: %d\n", even_count);
    printf("Total odd elements: %d\n", odd_count);

    return 0;
}
