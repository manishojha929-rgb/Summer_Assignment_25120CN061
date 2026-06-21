#include <stdio.h>

void findPair(int arr[], int size, int target) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] + arr[j] == target) 
            {
                printf("Pair found: %d and %d\n", arr[i], arr[j]);
                return;
            }
        }
    }
    printf("No pair found with the given sum\n");
}

int main() 
{
    int arr[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    findPair(arr, size, target);
    return 0;
}
