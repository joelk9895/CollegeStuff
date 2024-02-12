#include <stdio.h>

int isSymmetric(int a[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                printf("a[%d][%d] = %d, a[%d][%d] = %d\n", i, j, a[i][j], j, i, a[j][i]);
                return 0;
            }
        }
    }
    return 1;
}

void displayMatrixInfo(int a[][3], int n)
{
    printf("Original Matrix Info:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
    }
}

int main()
{
    int n;
    int rows, cols;

    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &n);
    printf("Enter the number of rows and column: ");
    scanf("%d %d", &rows, &cols);
    int a[n][3];
    int b[n][3];

    printf("Enter the sparse matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    int result = isSymmetric(a, n);

    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = n;

       displayMatrixInfo(a, n);
    if (result == 1)
    {
        printf("The original matrix is symmetric to its transpose.\n");
    }
    else
    {
        printf("The original matrix is not symmetric to its transpose.\n");
    }

    return 0;
}
