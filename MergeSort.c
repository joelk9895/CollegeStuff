#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int h)
{
    int i = l, j = m + 1, k = 0;
    int n1 = m - l + 1;
    int n2 = h - m;
    int *A = (int *)malloc(n1 * sizeof(int));
    int *B = (int *)malloc(n2 * sizeof(int));
    for (int p = 0; p < n1; p++)
        A[p] = arr[l + p];
    for (int q = 0; q < n2; q++)
        B[q] = arr[m + 1 + q];

    int C[h - l + 1];
    while (i < n1 && j < n2)
    {
        if (A[i - 1] < B[j - m - 1])
        {
            C[k++] = A[i++ - 1];
        }
        else
        {
            C[k++] = B[j++ - m - 1];
        }
    }
    for (; i < n1; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n2; j++)
    {
        C[k++] = B[j];
    }
    for (int i = 0; i < h - l + 1; i++)
    {
        arr[l + i] = C[i];
    }
}
void mergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}