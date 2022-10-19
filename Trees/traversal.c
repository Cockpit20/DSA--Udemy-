#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *s;
} st;

void createStack(st *arr, int size)
{
    arr->size = size;
    arr->s = (int *)malloc(arr->size * sizeof(int));
    arr->top = -1;
}

int is_empty(st *arr)
{
    if (arr->top == -1)
        return 1;
    else
        return 0;
}

int is_full(st *arr)
{
    if (arr->top == arr->size - 1)
        return 1;
    else
        return 0;
}

void push(st *arr, int item)
{
    if (!is_full(arr))
    {
        arr->top++;
        arr->s[arr->top] = item;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop(st *arr)
{
    int var = -1;
    if (arr->top != -1)
    {
        var = arr->s[arr->top];
        arr->top--;
    }
    else
    {
        printf("Stack Underflow.\n");
    }
    return var;
}

int peek(st *arr, int pos)
{
    if (arr->top - pos + 1 < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    return arr->s[arr->top - pos + 1];
}

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} * NODE;

NODE root = NULL;

typedef struct qu
{
    int size;
    int front;
    int rear;
    NODE *s;
} queue;

void createQueue(queue *arr, int size)
{
    arr->size = size;
    arr->front = arr->rear = 0;
    arr->s = (NODE *)malloc(arr->size * sizeof(NODE));
}

void enqueue(queue *arr, NODE item)
{
    if ((arr->rear + 1) % arr->size == arr->front)
        printf("Queue Overflow\n");
    else
    {
        arr->rear = (arr->rear + 1) % arr->size;
        arr->s[arr->rear] = item;
    }
}

NODE dequeue(queue *arr)
{
    NODE x = NULL;
    if (arr->front == arr->rear)
        printf("Queue Underflow\n");
    else
    {
        arr->front = (arr->front + 1) % arr->size;
        x = arr->s[arr->front];
    }
    return x;
}

int isEmpty(queue *arr)
{
    return (arr->rear == arr->front);
}

void create_tree()
{
    NODE p, t;
    int x;
    queue q;
    createQueue(&q, 100);

    printf("Enter the root value: ");
    scanf("%d", &x);
    root = (NODE)malloc(sizeof(NODE));
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (NODE)malloc(sizeof(NODE));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (NODE)malloc(sizeof(NODE));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// void IPreorder(NODE p)
// {
//     st stk;
//     createStack(&stk,100);

//     while(p || !is_empty(&stk))
//     {
//         if(p)
//         {
//             printf("%d ",p->data);
//             push(&stk,p);
//             p=p->lchild;
//         }
//         else
//         {
//             p=pop(&stk);
//             p=p->rchild;
//         }
//     }
// }

void preorder(NODE p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(NODE p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(NODE p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void LevelOrder(NODE p)
{
    queue q;
    createQueue(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, p);

    while (!isEmpty(&q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->lchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count(NODE p)
{
    if (p)
        return (count(p->lchild) + count(p->rchild) + 1);
    return 0;
}

int countLeaf(NODE p)
{
    int x,y;
    if (p)
    {
        x = countLeaf(p->lchild);
        y = countLeaf(p->rchild);
        if (!p->lchild && !p->rchild)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int height(NODE p)
{
    int x, y;
    if (p)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int main()
{
    create_tree();
    // LevelOrder(root);
    printf("%d ", count(root));
    printf("%d ", countLeaf(root));
    printf("%d ", height(root));
}