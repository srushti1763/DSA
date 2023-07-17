// Selection Sort Algorithm
#include <stdio.h>

void display(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        int imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[imin])
                imin = j;
        }
        int temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }

    printf("Sorted array\n");
    display(n, arr);
}

int main()
{
    int arr[100];
    int n,i;
    printf("enter how many elements");
    scanf("%d",&n);
    printf("enter the numbers");
    for(i=0;i<n;i++)
    {

    scanf("%d",&arr[i]);
    }

    printf("Your array\n");
    display(n, arr);
    selection_sort(n, arr);
    return 0;
}
