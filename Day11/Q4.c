#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) {
        return 0;
    }
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    if (scanf("%d", &num) != 1) {
        return 1;
    }
    if (num < 0) {
        printf("Error\n");
    } else {
        printf("%llu\n", factorial(num));
    }
    return 0;
}
