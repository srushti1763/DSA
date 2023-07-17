#include<stdio.h>
void read()
{
    int i,n,j;
    char arr[8][8];




      printf("enter the row and column in chess board");
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            scanf("%s",&arr[i][j]);
        }
    }
    }
    void dispaly(int i)
{
int j;
   char arr[8][8];

    for(i=0;i<8;i++)
    {
          for(j=0;j<8;j++)
          {
              printf("%s the location is",arr[i][j]);
    }
    }
}

    int main()
    {
        int i,j,n;
        char coin[10];
        printf("enter the elements in chess board");
       read();
       display(i);




return 0;
}
