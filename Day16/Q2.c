#include <stdio.h>

int main() 
{
    int arr[] = {4, 5, 2, 4, 3, 4, 2, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_element = arr[0];
    int max_count = 0;

    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                count++;
            }
        }
        if (count > max_count) 
        {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("The maximum frequency element is %d and it appears %d times.\n", max_element, max_count);

    return 0;
}
