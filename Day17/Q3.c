#include <stdio.h>

void findIntersection(int arr1[], int size1, int arr2[], int size2) 
{
    printf("Intersection: ");
    int foundAny = 0;
    
    for (int i = 0; i < size1; i++) 
    {
        int isDuplicate = 0;
        for (int k = 0; k < i; k++) 
        {
            if (arr1[i] == arr1[k]) 
            {
                isDuplicate = 1;
                break;
            }
        }
        
        if (isDuplicate) 
        {
            continue;
        }
        
        for (int j = 0; j < size2; j++) 
        {
            if (arr1[i] == arr2[j]) 
            {
                printf("%d ", arr1[i]);
                foundAny = 1;
                break;
            }
        }
    }
    
    if (!foundAny) 
    {
        printf("No common elements");
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 1, 2};
    int arr2[] = {2, 3, 5, 7, 2};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    findIntersection(arr1, size1, arr2, size2);
    
    return 0;
}
