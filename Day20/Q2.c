#include <stdio.h>

int main() 
{
    int rows, cols;
    int is_symmetric = 1;

    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2) 
    {
        return 1;
    }

    if (rows != cols) 
    {
        printf("The matrix is not symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (scanf("%d", &matrix[i][j]) != 1) 
            {
                return 1;
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (matrix[i][j] != matrix[j][i]) 
            {
                is_symmetric = 0;
                break;
            }
        }
        if (!is_symmetric) 
        {
            break;
        }
    }

    if (is_symmetric) 
    {
        printf("The matrix is symmetric.\n");
    } 
    else 
    {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
