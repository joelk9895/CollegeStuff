#include <stdio.h>
void swap(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
int partition(int arr[], int l, int h)
{
    int i = l-1;
    int j = h+1;
    int pivot = arr[l];
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(arr, i, j);
        }
    }
    swap(arr, l, j);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}