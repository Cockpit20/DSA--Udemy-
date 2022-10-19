
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