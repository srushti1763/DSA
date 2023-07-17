#include<stdio.h>
struct stack
{

    struct Node *s[100];
    int top;
}stack;


void push(stack *ps ,int data)
{
    ps->top=ps->top+1;
    ps->s[ps->top]=data;

}

int empty(stack stk)
{
    if(stk.top==-1)
        return 1;
    else
        return 0;
}


int pop(stack *ps,int data )

{

  data=ps->s[ps->top];
  ps->top=ps->top-1;
  return data;

}

void dfs(struct Node **al,int v,int visited[])
{
    struct Node *cur=NUll;
        struct stack stk;
        printf("visited :%d",v);
        visited[v]=1;
        stk.top=-1;
        push(&stk,al[v]);
        while(1)
        {
            if(cur==NULL)
            {
                if(empty(stk))
                    break;
                cur=pop(&stk);

            }
            if(visited[v]==0)
            {
                printf("visited:%d",cur=>v);
                visited[cur->v]=1;
                push(&stk,al);
            }
        }
}

int main()
{
    struct node **al;
    int n;
    int *visited;
    printf("enter number of vertices");
    scanf("%d",&n);
    al=createadjacency(n);
    visited=caloc(size of(int)*n);
    dfs(al,visited,0);
}
