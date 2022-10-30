#include <stdio.h>

void swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(A, i, j);
    } while (i < j);
    swap(A, l, j);
    return j;
}

void quick_sort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quick_sort(A, l, j);
        quick_sort(A, j + 1, h);
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 65535};
    quick_sort(A, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}