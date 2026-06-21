#include <stdio.h>

void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    printf("Fibonacci Series: ");
    printFibonacci(terms);
    return 0;
}
