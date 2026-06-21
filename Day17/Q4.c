#include <stdio.h>

int main() 
{
    int arr1[] = {4, 2, 9, 6, 2, 7, 1};
    int arr2[] = {2, 7, 5, 6, 2, 8};
    
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int common[100];
    int commonCount = 0;
    
    for (int i = 0; i < len1; i++) 
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j]) 
            {
                int alreadyAdded = 0;
                
                for (int k = 0; k < commonCount; k++)
                {
                    if (common[k] == arr1[i])
                    {
                        alreadyAdded = 1;
                        break;
                    }
                }
                
                if (!alreadyAdded) 
                {
                    common[scommonCount] = arr1[i];
                    commonCount++;
                }
                break;
            }
        }
    }
    
    printf("Common elements: ");
    for (int i = 0; i < commonCount; i++)
    {
        printf("%d ", common[i]);
    }
    printf("\n");
    
    return 0;
}
