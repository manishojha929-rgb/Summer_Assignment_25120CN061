#include <stdio.h>

int reverse_recursive(int num, int rev) 
{
    if (num == 0) 
    {
        return rev;
    }
    return reverse_recursive(num / 10, rev * 10 + num % 10);
}

int main() 
{
    int number;
    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) 
    {
        return 1;
    }
    
    int result = reverse_recursive(number, 0);
    printf("Reversed number: %d\n", result);
    
    return 0;
}
