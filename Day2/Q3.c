#include <stdio.h>

int main() 
{
    int n, product = 1;

    printf("Enter number: ");
    scanf("%d", &n);

    while(n != 0) 
    {
        product *= n % 10;
        n /= 10;
    }

    printf("Product = %d", product);

    return 0;
}