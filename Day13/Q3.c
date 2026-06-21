#include <stdio.h>

int main() 
{
    int arr[100];
    int size;
    int i;
    int largest;
    int smallest;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) 
    {
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) 
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            return 1;
        }
    }

    largest = arr[0];
    smallest = arr[0];

    for (i = 1; i < size; i++) 
    {
        if (arr[i] > largest) 
        {
            largest = arr[i];
        }
        if (arr[i] < smallest) 
        {
            smallest = arr[i];
        }
    }

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);

    return 0;
}
