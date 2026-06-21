#include <stdio.h>

int main() 
{
    int start, end;

    printf("Enter range: ");
    scanf("%d %d", &start, &end);

    for(int n = start; n <= end; n++) 
    {
        int flag = 1;

        if(n <= 1)
            flag = 0;

        for(int i = 2; i * i <= n; i++) 
        {
            if(n % i == 0) 
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            printf("%d ", n);
    }

    return 0;
}