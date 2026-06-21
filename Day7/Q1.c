#include <stdio.h>

unsigned long long factorial(int n) 
{
    if (n <= 1) 
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() 
{
    int num;
    if (scanf("%d", &num) != 1 || num < 0) 
    {
        return 1;
    }
    printf("%llu\n", factorial(num));
    return 0;
}
