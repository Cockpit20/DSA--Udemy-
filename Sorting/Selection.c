#include <stdio.h>

void swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void insertion_sort(int A[], int n)
{
    
    for (int i = n - 1; i >= 1; i--)
    {
        int max = A[0], max_index = 0;
        for (int j = 0; j <= i; j++)
        {
            if (A[j] > max)
            {
                max = A[j];
                max_index = j;
            }
        }
        swap(A, i, max_index);
    }
}

int main()
{
    int A[] = {8, 5, 7, 3, 2};
    insertion_sort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
}