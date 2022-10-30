#include <stdio.h>

int find_max(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void count_sort(int A[], int n)
{
    int size = find_max(A, n);

    int count_Arr[100];
    for (int i = 0; i <= size; i++)
        count_Arr[i] = 0;

    for (int i = 0; i < n; i++)
    {
        count_Arr[A[i]]++;
    }

    for (int i = 0; i <= size; i++)
    {
        printf("%d ", count_Arr[i]);
    }

    int j = 0;
    for (int i = 0; i < n;)
    {
        if (count_Arr[j] == 0)
            j++;
        else
        {
            while (count_Arr[j])
            {
                A[i++] = j;
                count_Arr[j]--;
            }
        }
    }
}

int main()
{
    int A[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
    count_sort(A, 10);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
}