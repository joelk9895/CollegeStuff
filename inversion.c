#include <stdio.h>

// find total number of inversion with complexity o(n)

int main()
{
    int a[] = {1, 2, 8, 9, 9, 3, 7, 2, 5, 1, 2};
    int i, j, count = 0;
    int n = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
            if (a[i] > a[j])
                count++;
    }
    printf("Total number of inversion is %d\n", count);
    return 0;
}