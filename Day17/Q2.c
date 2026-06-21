#include <stdio.h>

void printUnion(int arr1[], int size1, int arr2[], int size2) 
{
    int unionArr[100];
    int k = 0;

    for (int i = 0; i < size1; i++) 
    {
        int duplicate = 0;
        for (int j = 0; j < k; j++) 
        {
            if (unionArr[j] == arr1[i]) 
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) 
        {
            unionArr[k++] = arr1[i];
        }
    }

    for (int i = 0; i < size2; i++) 
    {
        int duplicate = 0;
        for (int j = 0; j < k; j++) 
        {
            if (unionArr[j] == arr2[i]) 
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) 
        {
            unionArr[k++] = arr2[i];
        }
    }

    printf("Union of the arrays: ");
    for (int i = 0; i < k; i++) 
    {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 2, 6};
    int arr2[] = {2, 3, 5, 7};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printUnion(arr1, size1, arr2, size2);

    return 0;
}
