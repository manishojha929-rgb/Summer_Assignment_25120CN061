#include <stdio.h>
#include <math.h>

int main() 
{
    int n, temp, digits = 0;
    int sum = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    temp = n;

    while(temp != 0) 
    {
        digits++;
        temp /= 10;
    }

    temp = n;

    while(temp != 0) 
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if(sum == n)
        printf("Armstrong Number");
    else
        printf("Not Armstrong Number");

    return 0;
}