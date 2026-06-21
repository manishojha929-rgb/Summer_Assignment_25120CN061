#include <stdio.h>
#include <limits.h>

int main() 
{
    int n;
    
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 2) 
    {
        printf("Invalid input. Array must have at least 2 elements.\n");
        return 1;
    }
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    int first = INT_MIN;
    int second = INT_MIN;
    
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > first) 
        {
            second = first;
            first = arr[i];
        } 
        else if (arr[i] > second && arr[i] < first) 
        {
            second = arr[i];
        }
    }
    
    if (second == INT_MIN) 
    {
        printf("There is no distinct second largest element.\n");
    } else 
    {
        printf("The second largest element is: %d\n", second);
    }
    
    return 0;
}
