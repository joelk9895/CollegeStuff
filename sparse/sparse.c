#include <stdio.h>

int sparseConvert(int sp[][3], int comp[][3], int rows, int cols)
{
    int i, j, count = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (sp[i][j] != 0)
            {
                comp[++count][0] = i;
                comp[count][1] = j;
                comp[count][2] = sp[i][j];
            }
        }
    }
    comp[0][0] = rows;
    comp[0][1] = cols;
    comp[0][2] = count;
    return count;
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int sparse[rows][cols];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &sparse[i][j]);
        }
    }

    int compressed[100][3];
    int i, j, count = 0;

    count = sparseConvert(sparse, compressed, rows, cols);

    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", compressed[i][j]);
        }
        printf("\n");
    }

    return 0;
}
