#include <stdio.h>

int main() 
{
    int arr[] = {4, 2, 4, 3, 2, 1, 5, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                for (int k = j; k < n - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
