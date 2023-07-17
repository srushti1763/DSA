#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rollno;
    char name[25];
    float percentage;
}Student;

void addStudent(char filename[],Student s)
{

    FILE *fp;
    fp = fopen(filename,"a");
    fprintf(fp,"%d %s %f\n",s.rollno,s.name,s.percentage);
    fclose(fp);
}

void displayAll(char filename[])
{
    FILE *fp;
    Student s;
    fp = fopen(filename,"r");
    while(1)
    {
        fscanf(fp,"%d%s%f",&s.rollno,s.name,&s.percentage);
        if(feof(fp))
            break;
        printf("\nRollno : %d   Name : %s   Percentage : %f",s.rollno,s.name,s.percentage);
    }
    fclose(fp);
}

void search(char filename[],int rno)
{
    FILE *fp;
    Student s;
    fp = fopen(filename,"r");
    while(1)
    {
        fscanf(fp,"%d%s%f",&s.rollno,s.name,&s.percentage);
        if(feof(fp))
        {
            printf("\nRecord not found");
            break;
        }

        if(s.rollno == rno)
        {
            printf("\nRollno : %d   Name : %s   Percentage : %f",s.rollno,s.name,s.percentage);
            break;
        }
    }
    fclose(fp);
}

int main()
{
   char filename[] = "F:\\a;
   Student s;
    int ch,rno;

    do{
        printf("\n1->Add, 2->Modify, 3->Delete, 4->Search, 5->Display, 0->Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter student details : \n");
                        scanf("%d%s%f",&s.rollno,s.name,&s.percentage);

                        addStudent(filename,s);
                        printf("\n1 record added successfully");
                        break;
            case 5: displayAll(filename);
                        break;
            case 4: printf("\nEnter rollno to search : ");
                        scanf("%d",&rno);
                        search(filename,rno);
                        break;
            case 0: break;
        }
    }while(ch!=0);




    return 0;
}
