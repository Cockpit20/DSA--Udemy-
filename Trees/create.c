#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} * NODE;

NODE root=NULL;

typedef struct qu
{
    int size;
    int front;
    int rear;
    NODE *s;
} queue;

void create(queue *arr,int size)
{
    arr->size=size;
    arr->front=arr->rear=0;
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
    NODE p,t;
    int x;
    queue q;
    create(&q,100);

    printf("Enter the root value: ");
    scanf("%d",&x);
    root=(NODE)malloc(sizeof(NODE));
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    enqueue(&q,root);

    while (!isEmpty(&q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(NODE)malloc(sizeof(NODE));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter the right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(NODE)malloc(sizeof(NODE));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(NODE p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(NODE p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(NODE p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main()
{
    create_tree();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}