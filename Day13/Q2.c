#include <stdio.h>

int main() 
{
    int n;
    int sum = 0;
    float average;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        return 1;
    }

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            return 1;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];
    }

    average = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
