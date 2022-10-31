#include <stdio.h>

void binary_search(int A[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target == A[mid])
        {
            printf("%d is found at index %d", target, mid);
            return;
        }
        else if (target < A[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("%d not found!", target);
    return;
}

int main()
{
    int A[] = {2, 4, 8, 17, 32};
    binary_search(A, 5, 34);
}