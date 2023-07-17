#include<stdio.h>
#define Qsize 5
typedef struct
{
    int Q[Qsize];
    int front,rear;
    }queue;

    int main()
    {
        queue q;
        int data,ch;
        q.front=0;
        q.rear=-1;
        do
        {
            printf("\n1.enqueue 2.dequeue 3.peek 4.display 5.exit");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:if(full(q))
                printf("queue is full");
                else
                {
                    printf("enter data");
                    scanf("%d",&data);
                    enqueue(&q,data);
                }
                break;

                case 2:if(empty(q))
                printf("queue empty");
                else
                {
                    data=dequeue(&q);
                    printf("deleted data:%d",data);

                }
                break;

                case 3:if(empty(q))
                printf("queue empty");
                else
                {


                    printf("frontdata:%d",peek(q));

            }
            break;

            case 4:if(empty(q))
            printf("queue is empty");
            else
            {
                display(q);
            }
            break;

            case 5: break;

            }
        }while(ch!=5);

    }


    int empty(queue q)
    {
        return q.front>q.rear;
    }
    int full(queue q)
    {
        return q.rear==(Qsize-1);
            }
void enqueue(queue *pq,int data)
{
    pq->rear=pq->rear+1;
    pq->Q[pq->rear]=data;
}
int dequeue(queue *pq)
{
    int d;
    d=pq->Q[pq->front];
    pq->front=pq->front+1;
    return d;
}
int peek(queue q)
{
    return q.Q[q.front];
}
void display(queue q)
{
    int i;
    printf("queue elements:");
     for(i=q.rear;i>=0;i--)
     {
         printf("%d ",q.Q[i]);
     }
}
