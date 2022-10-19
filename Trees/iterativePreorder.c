void preorder(NODE t)
{
    struct stack st;
    while(t!=NULL || isEmpty(st))
    {
        if(t!=NULL)
        {
            print("%d",t->data);
            push(&st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&st);
            t=t->rchild;
        }
    }
}
 
void inorder(NODE t)
{
    struct stack st;
    while(t!=NULL || isEmpty(st))
    {
        if(t!=NULL)
        {
            push(&st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&st);
            print("%d",t->data);
            t=t->rchild;
        }
    }
}