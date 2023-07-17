#include<stdio.h>
void read(int a[10][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void disp(int a[10][10],int m,int n)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
            }
}

void matrix(int a[10][10],int m,int n)
{
   int i,j,b[10][10];

   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           b[i][j]=a[i][j];

        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }




}
void main()
{

  int a[10][10],m,n,b[10][10],i,j,c;
  scanf("%d",&c);
  if(c==0)
  {


   printf("Enter m and n");

  scanf("%d%d",&m,&n);

 printf("Enter 1st array:");
  read(a,m,n);
disp(a,m,n);





  printf("symmetry of matrix:\n");
  matrix(a,m,n);

}
else
{
    printf("aymmetry matrix");
}

printf("\n");


  return 0;
}
