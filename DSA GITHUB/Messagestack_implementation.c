#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE  5

typedef struct
{
    char revdTime[20];
    char phone[15];
    char message[255];
}Message;

typedef struct
{
    Message s[STACKSIZE];
    int top;
}Stack;

void readMessage(Message *p)
{
    printf("\nEnter message : \n");
    fflush(stdin);
    gets(p->revdTime);
    gets(p->phone);
    gets(p->message);
}

void displayMessage(Message m)
{
    printf("\nTime : %s   Phone : %s   Message %s",m.revdTime,m.phone,m.message);
}

int full(Stack stk)
{
    if(stk.top == STACKSIZE-1)
        return 1;
    else
        return 0;
}

int empty(Stack stk)
{
    if(stk.top == -1)
        return 1;
    else
        return 0;
}

void push(Stack *ps,Message data)
{
    ps->top = ps->top + 1;
    ps->s[ps->top] = data;

}


Message pop(Stack *ps)
{
    Message data = ps->s[ps->top];
    ps->top = ps->top - 1;
    return data;
}

Message stackTop(Stack stk)
{
    return stk.s[stk.top];
}

void displayStack(Stack stk)
{
    int i;
    printf("\nStack elements  : ");
    for(i=stk.top;i>=0;i--)
        displayMessage(stk.s[i]);
}

int main()
{
    Stack stk;
    int ch;
    Message data;

    stk.top = -1;

    do{
        printf("\n1->Push 2->Pop 3->Stack top 4->Display  5->Exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: if(full(stk))
                            printf("\nStack overflow");
                        else
                        {
                            readMessage(&data);
                            push(&stk,data);
                        }
                        break;
            case 2: if(empty(stk))
                            printf("\nStack underflow");
                        else
                        {
                            data = pop(&stk);
                            printf("\nPopped data : ");
                            displayMessage(data);
                        }
                        break;
            case 3: if(empty(stk))
                            printf("\nStack empty");
                        else
                        {
                            data = stackTop(stk);
                            printf("\n Top element :  ");
                            displayMessage(data);
                        }
                        break;
            case 4: if(empty(stk))
                            printf("\nStack empty");
                        else
                        {
                            displayStack(stk);
                        }
                        break;
            case 5: break;
        }
    }while(ch != 5);

    return 0;
}
