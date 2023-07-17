//singly linked list
#include<stdio.h>
#include<stdlib.h>

 struct Node
 {

 int rollno;
    char name[20];
    float per;
    struct Node *Next;

};

struct Node *getnode()
{
    return malloc(sizeof(struct Node));
};
void freenode(struct Node *p)
{
    free(p);
}
void readinfo(struct Node *p)
{
    printf("enter the details\n");
                    printf("enter roll  no: Name :  percentage :\n");
    scanf("%d%s%f",&p->rollno,p->name,&p->per);
}
void displayinfo(struct Node *p)
{
    printf("%d %s %f",p->rollno,p->name,p->per);
}

//INSERT FUNCTION

struct Node *insertfront(struct Node *first)
{
    struct Node *nw;
    nw=getnode();
    readinfo(nw);
    nw->Next=first;
    first =nw;
    return(first);

};
void displaylist(struct Node *head)
{
    struct Node *cur;
    for(cur=head;cur!=NULL;cur=cur->Next)
    {
        displayinfo(cur);
    }
}

int main()
{
     int rollno;
    char name[20];
    float per;
    struct Node *first;
        struct Node *p;
    struct Node *head;
  int ch,q;

  printf("enter the choice ");
  scanf("%d",&ch);

  switch(ch)
  {
  case 1:printf("enter the number to be inserted");
      scanf("%d",&q);
        first=insertfront(first);
        break;
    case 2:displaylist(head);
    break;
  case 0: break;
  }
 return 0;
}
