#include <stdio.h>

int main() 
{
    int rows, cols, i, j;
    int a[100][100], b[100][100], diff[100][100];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Resultant matrix after subtraction:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;
}
