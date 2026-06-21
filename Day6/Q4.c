#include <stdio.h>

unsigned int countSetBits(unsigned int n) 
{
    unsigned int count = 0;
    while (n) 
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() 
{
    unsigned int num = 29;
    printf("Number of set bits in %u is %u\n", num, countSetBits(num));
    return 0;
}
