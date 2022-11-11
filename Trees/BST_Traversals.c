#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} * NODE;

NODE root = NULL;

NODE insert(NODE ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (NODE)malloc(sizeof(NODE));
        ptr->data = key;
        ptr->lchild = ptr->rchild = NULL;
    }
    else if (key < ptr->data)
        ptr->lchild = insert(ptr->lchild, key);
    else if (key > ptr->data)
        ptr->rchild = insert(ptr->rchild, key);
    return ptr;
}

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

int main()
{
    int choice;
    printf("You can perform the following operations on a BST: \n");
    printf("1.Insert a key \n");
    printf("2.Preorder Traversal \n");
    printf("3.Inorder Traversal \n");
    printf("4.Postorder Traversal \n");
    printf("5.To EXIT \n");
    scanf("%d", &choice);
    while (choice != 5)
    {
        if (choice == 1)
        {
            int val;
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            root = insert(root, val);
        }
        if (choice == 2)
        {
            preorder(root);
            printf("\n");
        }
        if (choice == 3)
        {
            inorder(root);
            printf("\n");
        }
        if (choice == 4)
        {
            postorder(root);
            printf("\n");
        }

        printf("Enter your choice again: ");
        scanf("%d", &choice);

        if (choice == 5)
            printf("Program Terminated!");
    }
}