#include<stdio.h>
#include<time.h>
int main()
{
    int n;
    srand(time(NULL));
    for(int i=0;i<50;i++)
    {
        n=rand()%1000;
        printf("%d ",n);
                       }
}
