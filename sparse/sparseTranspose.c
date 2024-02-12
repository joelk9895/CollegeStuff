#include <stdio.h>

void transposeMatrix(int a[][3], int b[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i][0] = a[i][1];
        b[i][1] = a[i][0];
        b[i][2] = a[i][2];
    }
}

void sortSparseMatrix(int b[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i][0] > b[j][0])
            {
                int temp;

                temp = b[i][0];
                b[i][0] = b[j][0];
                b[j][0] = temp;

                temp = b[i][1];
                b[i][1] = b[j][1];
                b[j][1] = temp;

                temp = b[i][2];
                b[i][2] = b[j][2];
                b[j][2] = temp;
            }
        }
    }
}

void displayMatrix(int b[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main()
{
    int n, rows, cols;

    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", &n);
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int a[n][3];
    int b[n][3];

    printf("Enter the sparse matrix in the format (row column value):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    b[0][0] = rows;
    b[0][1] = cols;
    b[0][2] = n;

    transposeMatrix(a, b, n);
    sortSparseMatrix(b, n);
    printf("------------------------\n Transpose Matrix:\n");
    displayMatrix(b, n);

    return 0;
}
