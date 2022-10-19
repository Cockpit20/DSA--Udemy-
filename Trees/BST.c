#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} * NODE;

NODE root = NULL;

void insert(int key)
{
    NODE t = root;
    NODE r, p;
    if (root == NULL)
    {
        p = (NODE)malloc(sizeof(NODE));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t)
    {
        r = t;
        if (key < p->data)
            t = t->lchild;
        else if (key > p->data)
            t = t->rchild;
        else
            return;
    }
    p = (NODE)malloc(sizeof(NODE));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else if (key > r->data)
        r->rchild = p;
}

NODE RInsert(NODE p, int key)
{
    if (p == NULL)
    {
        NODE t;
        t = (NODE)malloc(sizeof(NODE));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
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

NODE search(int key)
{
    NODE t = root;
    while (t)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}


int Height(NODE p)
{
    int x, y;
    if (p)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

NODE InPre(NODE p)
{
    while (p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

NODE InSucc(NODE p)
{
    while (p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

NODE Delete(NODE p, int key)
{
    NODE q;
    if (p == NULL)
        return NULL;

    if (!p->lchild && !p->rchild)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    root = RInsert(root, 50);
    root = RInsert(root, 10);
    root = RInsert(root, 40);
    root = RInsert(root, 20);
    root = RInsert(root, 30);

    inorder(root);

    root=Delete(root,50);

    inorder(root);

    NODE temp = search(30);
    if (temp)
        printf("Found");
    else
        printf("NoT Found");
}