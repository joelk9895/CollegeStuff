#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n = m;
    int ar[r];
    int k = 0;
    while (1)
    {
        if (l < m && n < r)
        {
            if (arr[l] < arr[n])
            {
                ar[k] = arr[l];
                l++;
                k++;
            }
            else
            {
                ar[k] = arr[n];
                n++;
                k++;
            }
        }
        else
        {
            break;
        }
    }
}