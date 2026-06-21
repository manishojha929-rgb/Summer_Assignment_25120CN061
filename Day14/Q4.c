#include <stdio.h>

int main() 
{
    int arr[] = {4, 2, 7, 4, 8, 2, 4, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Duplicate elements: ");
    
    for (int i = 0; i < size; i++) 
    {
        int is_duplicate = 0;
        
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                is_duplicate = 1;
                break;
            }
        }
        
        if (is_duplicate) 
        {
            int already_printed = 0;
            for (int k = 0; k < i; k++) 
            {
                if (arr[i] == arr[k]) 
                {
                    already_printed = 1;
                    break;
                }
            }
            
            if (!already_printed) 
            {
                printf("%d ", arr[i]);
            }
        }
    }
    
    printf("\n");
    return 0;
}
