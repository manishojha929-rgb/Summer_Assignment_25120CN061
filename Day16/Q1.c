#include <stdio.h>

int findMissingNumber(int arr[], int size) 
{
    int xor1 = 0;
    int xor2 = 0;
    
    for (int i = 0; i < size; i++) 
    {
        xor1 = xor1 ^ arr[i];
    }
    
    for (int i = 1; i <= size + 1; i++) 
    {
        xor2 = xor2 ^ i;
    }
    
    return xor1 ^ xor2;
}

int main() 
{
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missing = findMissingNumber(arr, size);
    
    printf("The missing number is: %d\n", missing);
    
    return 0;
}
