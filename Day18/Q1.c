#include <stdio.h>

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n, i;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 1;
    }
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) 
        {
            return 1;
        }
    }
    
    bubbleSort(arr, n);
    
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
