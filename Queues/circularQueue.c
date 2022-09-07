#include <stdio.h>
#include <stdlib.h>

typedef struct qu
{
    int size;
    int front;
    int rear;
    int *s;
} queue;

void create(queue *arr, int size)
{
    arr->size = size;
    arr->front = arr->rear = 0;
    arr->s = (int *)malloc(arr->size * sizeof(int));
}

void enqueue(queue *arr, int x)
{
    if ((arr->rear + 1) % arr->size == arr->front)
        printf("Queue Overflow\n");
    else
    {
        arr->rear = (arr->rear + 1) % arr->size;
        arr->s[arr->rear] = x;
    }
}

int dequeue(queue *arr)
{
    int x = -1;

    if (arr->front == arr->rear)
        printf("Queue Underflow\n");
    else
    {
        arr->front = (arr->front + 1) % arr->size;
        x = arr->s[arr->front];
    }
    return x;
}
void display(queue arr)
{
    int i = arr.front + 1;
    do
    {

        printf("%d ", arr.s[i]);
        i = (i + 1) % arr.size;
    } while (i != (arr.rear + 1) % arr.size);

    printf("\n");
}
int main()
{
    queue arr;
    create(&arr, 5);

    enqueue(&arr, 10);
    enqueue(&arr, 20);
    enqueue(&arr, 30);
    enqueue(&arr, 40);
    enqueue(&arr, 50);
    enqueue(&arr, 60);

    display(arr);

    printf("%d ", dequeue(&arr));
}