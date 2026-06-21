#include <stdio.h>

int main() 
{
    int size, target, count = 0;
    if (scanf("%d", &size) != 1 || size <= 0) return 1;
    int arr[size];
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    for (int i = 0; i < size; i++) if (arr[i] == target) count++;
    printf("%d", count);
    return 0;
}
