#include <stdio.h>

void mergeSparseMatrices(int a[][3], int b[][3], int c[][3], int *count)
{
    int i, j, k;
    i = j = k = 0;

    while (i < 4 && j < 4)
    {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            c[*count][0] = a[i][0];
            c[*count][1] = a[i][1];
            c[*count][2] = a[i][2] + b[j][2];
            (*count)++;
            i++;
            j++;
        }
        else if ((a[i][0] < b[j][0]) || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            c[*count][0] = a[i][0];
            c[*count][1] = a[i][1];
            c[*count][2] = a[i][2];
            (*count)++;
            i++;
        }
        else
        {
            c[*count][0] = b[j][0];
            c[*count][1] = b[j][1];
            c[*count][2] = b[j][2];
            (*count)++;
            j++;
        }
    }

    while (i < 4)
    {
        c[*count][0] = a[i][0];
        c[*count][1] = a[i][1];
        c[*count][2] = a[i][2];
        (*count)++;
        i++;
    }

    while (j < 4)
    {
        c[*count][0] = b[j][0];
        c[*count][1] = b[j][1];
        c[*count][2] = b[j][2];
        (*count)++;
        j++;
    }
}

void displaySparseMatrix(int c[][3], int count)
{
    c[0][0] = 4;
    c[0][1] = 3;
    c[0][2] = count - 1;

    printf("Merged Sparse Matrix:\n");

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[100][3];
    int b[100][3];
    int c[200][3];
    int countA, countB;
    int row1, col1, row2, col2;

    printf("Enter the number of non-zero elements for matrix A: ");
    scanf("%d", &countA);
    printf("Enter the number of rows and column: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the sparse matrix A in the format (row column value):\n");
    for (int i = 1; i <= countA; i++)
    {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }

    printf("Enter the number of non-zero elements for matrix B: ");
    scanf("%d", &countB);
    printf("Enter the number of rows and column: ");
    scanf("%d %d", &row2, &col2);
    printf("Enter the sparse matrix B in the format (row column value):\n");
    for (int i = 1; i <= countB; i++)
    {
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    }
    a[0][0] = row1;
    a[0][1] = col1;
    a[0][2] = countA;
    b[0][0] = row2;
    b[0][1] = col2;
    b[0][2] = countB;
    int countC = 1;
    mergeSparseMatrices(a, b, c, &countC);
    displaySparseMatrix(c, countC);

    return 0;
}
