#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) 
    {
        if (arr1[i] < arr2[j]) 
        {
            result[k] = arr1[i];
            i++;
        } 
        else 
        {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() 
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int result[n1 + n2];

    mergeArrays(arr1, n1, arr2, n2, result);

    for (int l = 0; l < n1 + n2; l++) 
    {
        printf("%d ", result[l]);
    }
    printf("\n");

    return 0;
}
