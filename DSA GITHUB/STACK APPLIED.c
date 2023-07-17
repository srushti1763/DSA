#include<stdio.h>
#define STRUCTSIZE 5

typedef struct
{
    int s[STRUCTSIZE];
    int top;
}stack;

int full(stack stk)
{
    if(stk.top==(STRUCTSIZE-1))
        return 1;
    else
        return 0;
}


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
int stacktop(stack stk)
{
    return stk.s[stk.top];
}
void display(stack stk)
{
    int i;
    printf("\nStack elements  : ");
    for(i=stk.top;i>=0;i--)
        printf("%d  ",stk.s[i]);
}

int main()
{
    stack stk;

    int data,ch;


    stk.top=-1;
    do
    {


    printf("\n 1:push  2: pop  3:stacktop  4:display stack 5:exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:if(full(stk))
                printf("\nstack overflow");
                else
                {
                    printf("\nEnter data");
                    scanf("%d",&data);
                    push(&stk,data);
                }
                break;
        case 2:if(empty(stk))
                printf("\nstack underflow");
                else
                {
                    data=pop(&stk,data);
                    printf("\n popped data:%d",data);
                    }
                    break;
        case 3:if(empty(stk))
                printf("\nstack empty");
                else
                {
                    data=stacktop(stk);
                    printf("\nstack top:%d",data);
                }
                break;
        case 4:display(stk);
                break;
        case 5:break;
    }
    }while(ch!=5);
}

