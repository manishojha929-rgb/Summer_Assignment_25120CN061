#include <stdio.h>
int main()
{
    int i,j,q,p,k,m,n,sum=0;
    int a[10][10], b[10][10], multiply[10][10];

    printf("enter the number of row and columns of first matrix\n");
    scanf("%d%d", &m, &n);
    printf("enter the elemnts of first matrix\n");

    for(i=0; i<m; i++)
    for(j=0; j<n; j++)

    scanf("%d", &a[i][j]);

    printf("enter the number of row and columns of second matrix\n");
    scanf("%d", &p, &q);

    if(m != q)

    printf("in this order matrix can not be multiply with each other\n");

    else
    {
        printf("enter the elements of second matrix\n");

        for(i=0; i<m; i++)
        for(j=0; j<n; j++)

        scanf("%d", &b[p][q]);

        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)
            {
                for(k=0; k<p; k++)
                {
                    sum= sum + a[i][k]*b[k][j];
                }
                multiply[i][j] = sum;
                sum=0;
            }
        }
        printf("products of enter matrixs:-\n");

        for(i=0; i<m; i++)
        {
            for(j=0; j<q; j++)

            printf("%d\t", multiply[i][j]);

            printf("\n");
        }
        
    }
    return 0;
}