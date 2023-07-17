#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    float sgpa;
    struct Node *next;
};


void displayInfo(struct Node *p)
{
    printf("\nName : %s   SGPA : %f",p->name,p->sgpa);
}


struct Node *getNode()
{
    return malloc(sizeof(struct Node));
};

struct Node *insertFront(struct Node *first, char name[], float sgpa)
{
    struct Node *nw,*last;

    nw = getNode();
    strcpy(nw->name,name);
    nw->sgpa = sgpa;

    if(first == NULL)
        first = nw->next = nw;
    else
    {
        for(last = first;last->next != first;last=last->next);
        last->next = nw;
        nw->next = first;
        first = nw;
    }
    return first;
};

void displayList(struct Node *first)
{
    struct Node *cur;

    if(first == NULL)
    {
        printf("\nList empty");
        return;
    }


    cur = first;
    do
    {
        displayInfo(cur);
        cur=cur->next;
    }while(cur != first);
}


void displayAbove9(struct Node *first)
{
    struct Node *cur;
    int count = 0;

    if(first == NULL)
    {
        printf("\nList empty");
        return;
    }


    cur = first;
    do
    {
        if(cur->sgpa >= 9.0)
        {
            displayInfo(cur);
            count++;
        }

        cur=cur->next;
    }while(cur != first);
}



struct Node *createBelow4(struct Node *first)
{
    struct Node *first2,*cur;


    if(first == NULL)
    {
        return NULL;
    }

    first2 = NULL;
    cur = first;
    do
    {
        if(cur->sgpa < 4.0)
        {
            first2 = insertFront(first2,cur->name,cur->sgpa);
        }

        cur=cur->next;
    }while(cur != first);
    return first2;
}


int main()
{
    struct Node *first = NULL,*first2 = NULL;
    int ch;
    char name[50];
    float sgpa;

    do{
        printf("\n1->Insert new node    2->Display List     3->Display above 9.0   4->Create list below 4.0   0->Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter new student name and sgpa : ");
                        scanf("%s%f",name,&sgpa);
                        first = insertFront(first,name,sgpa);
                        break;
            case 2: displayList(first);
                        break;
            case 3: displayAbove9(first);
                        break;
            case 4: first2 = createBelow4(first);
                        displayList(first2);
                        break;
            case 0: break;
        }
    }while(ch!=0);
    return 0;
}
