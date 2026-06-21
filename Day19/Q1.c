#include <stdio.h>

int main() 
{
    int r, c, i, j;
    scanf("%d %d", &r, &c);
    int m1[r][c], m2[r][c], sum[r][c];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &m1[i][j]);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &m2[i][j]);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            sum[i][j] = m1[i][j] + m2[i][j];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
    return 0;
}
