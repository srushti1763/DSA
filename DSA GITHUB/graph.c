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

int **create(int v)
{
    int **am,i;

}
