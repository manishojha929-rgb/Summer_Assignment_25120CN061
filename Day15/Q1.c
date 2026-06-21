#include <stdio.h>

void reverseArray(int arr[], int size) 
{
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() 
{
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) 
    {
        return 1;
    }

    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printf("Reversed array:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
