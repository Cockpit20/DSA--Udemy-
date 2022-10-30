#include <stdio.h>

void swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void selection_sort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j >= 1; j--)
        {
            if (A[j] < A[j - 1])
                swap(A, j - 1, j);
        }
    }
}

int main()
{
    int A[] = {8, 5, 7, 3, 2};
    selection_sort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
}