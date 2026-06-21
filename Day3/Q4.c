#include <stdio.h>

int main() 
{
    int a, b, x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    x = a;
    y = b;

    while(y != 0) 
    {
        int temp = y;
        y = x % y;
        x = temp;
    }

    int gcd = x;
    int lcm = (a * b) / gcd;

    printf("LCM = %d", lcm);

    return 0;
}