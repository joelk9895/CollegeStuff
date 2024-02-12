#include <stdio.h>
int i, j, m1, m2, n1, n2, a[100][100], b[100][100], s[100][100], t[100][100], sum[100][100];
void sparsread(int sparse[100][100])
{
    printf("First Matrix");
    printf("\nenter no of rows;\n");
    scanf("%d", &m1);
    printf("enter nof columns;\n");
    scanf("%d", &n1);
    printf("\nEnter the matrix:\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Second Matrix");
    printf("\nenter no of rows;\n");
    scanf("%d", &m2);
    printf("enter no of columns;\n");
    scanf("%d", &n2);
    printf("\nEnter the matrix:\n");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
}
void sparse(int a[100][100], int m, int n, int s[100][100])
{
    int i;
    j;
    k = 1;
    s[0][0] = m;
    s[0][1] = n;
    for (i = 0; i < m; i++);
    {
        for (j = o; j < n; j++)
            ;
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
            }
        }
    }
    s[0][2] = k - 1;
}
void sparsadd(int s[100][3], int t[100][3], int sum[100][3])
{
    int i, j, k, m, n, k;
    int r1 = s[0][0];
    int r2 = t[0][0];
    int c1 = s[0][1];
    int c2 = t[0][1];

    if (r1 != r2 || c1 != c2)
    {
        printf("incompactable matrix\n");
    }
    else
    {
        sum[0][0] = r1;
        sum[0][1] = c1;
        m = 1;
        n = 1;
        k = 1;
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                if (s[m][0] == i && s[m][1] == j && t[n][0] == i && t[n][0] == j)
                {
                    sum[k][0] = s[m][0];
                    sum[k][1] = s[m][1];
                    sum[k][2] = s[m][2] + t[n][2];
                    m++;
                    n++;
                    k++;
                }
                else if (s[m][0] == i && s[m][1] == j)
                {
                    sum[k][0] = s[m][0];
                    sum[k][1] = s[m][1];
                    sum[k][2] = s[m][2];
                    m++;
                    k++;
                }
                else if (t[n][0] == i && t[n][0] == j)
                {
                    sum[k][0] = t[m][0];
                    sum[k][1] = t[m][1];
                    sum[k][2] = t[m][2];
                    n++;
                    k++;
                }
            }
        }

        sum[0][2] = k - 1;

        printf("\nSum:\n");
        for (i = 0; i < k; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    sparsread(a);
    sparse(b);
    sparse(a, m1, n1, s);
    sparse(b, m2, n2, t);
    sparsadd(s, t, sum);
}