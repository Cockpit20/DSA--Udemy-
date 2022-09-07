#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} *NODE;

NODE start=NULL;
NODE last=NULL;

void enqueue(int item)
{
    NODE new_node=(NODE)malloc(sizeof(NODE));
    new_node->data=item;
    if(start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
        last=new_node;
    }
    else
    {
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
    }
}

int dequeue()
{
    int x=-1;
    if(start==NULL)
    {
        printf("Queue Underflow.");
    }
    else
    {
        NODE ptr=start;
        start=start->next;
        x=ptr->data;
        printf("%d is dequeued.\n",x);
        free(ptr);
    }
    return x;
}

void display()
{
    NODE ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();
}