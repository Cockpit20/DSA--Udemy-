#include <stdio.h>

void swap(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void insert(int A[], int n)
{
    int temp, i = n;
    temp = A[n];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void delete (int A[], int n)
{
    int x = A[n];
    int val = A[1];
    A[1] = A[n];
    int i = 1, j = 2 * i;
    while (j < n)
    {
        if (A[j + 1] > A[j])
            j++;
        if (A[i] < A[j])
        {
            swap(A, i, j);
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    A[n] = val;
}

int main()
{
    int H[] = {0, 5, 10, 30, 20, 35, 40, 15};
    for (int i = 2; i <= 7; i++)
    {
        insert(H, i);
    }

    for (int i = 7; i > 1; i--)
    {
        delete (H, i);
    }
    for (int i = 1; i < 8; i++)
    {
        printf("%d ", H[i]);
    }
}