#include <stdio.h>

int findMax(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int a = 15;
    int b = 30;
    int result = findMax(a, b);
    
    printf("The maximum is: %d\n", result);
    
    return 0;
}
