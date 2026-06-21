#include <stdio.h>

int main() {
    int size;
    int principal_sum = 0;
    int secondary_sum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[size][size];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        principal_sum += matrix[i][i];
        secondary_sum += matrix[i][size - i - 1];
    }

    printf("Sum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}
