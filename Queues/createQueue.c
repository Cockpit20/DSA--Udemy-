#include <stdio.h>
#include <stdlib.h>

typedef struct qu
{
    int size;
    int front;
    int rear;
    int *s;
} queue;

void create(queue *arr)
{
    printf("Enter size of the queue: ");
    scanf("%d", &arr->size);
    arr->s = (int *)malloc(arr->size * sizeof(int));
    arr->front = -1;
    arr->rear = -1;
}

void enqueue(queue *arr, int item)
{
    if (arr->rear==arr->size-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        arr->rear++;
        arr->s[arr->rear] = item;
    }
}

int dequeue(queue *arr)
{
    int var = -1;
    if (arr->rear == arr->front)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        arr->front++;
        var=arr->s[arr->front];
    }
    printf("%d is dequeued. \n",var);
    return var;
}

void display(queue *arr)
{
    for (int i = arr->front+1; i <=arr->rear; i++)
    {
        printf("%d ", arr->s[i]);
    }
    printf("\n");
}

int main()
{
    queue q;
    create(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);
}