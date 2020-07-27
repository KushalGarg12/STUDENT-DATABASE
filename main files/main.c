#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

struct node
{
    long int rollno;
    char name[20];
    struct node *link;
};
struct node *START=NULL;
struct node *START1=NULL;
struct node *createnode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
};
void insertnode()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter the name of student :");
    scanf("%s",&temp->name);
    printf("Enter the roll number :");
    scanf("%d",&temp->rollno);

    temp->link=NULL;
    if(START==NULL)
    {
        START=temp;
    }
    else
    {
        t=START;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}
void viwlist(struct node *temp)
{
    struct node *p;
    p=temp;
    if(temp==NULL)
      printf("The list is empty!\n");
    while(p!=NULL)
    {
        printf("%s\t%d\n",p->name,p->rollno);
        printf("\n");
        p=p->link;
    }

}
struct node *deletenode(int delete)
{
    struct node *r,*result;
    r=START;
    if(START==NULL)
        printf("Empty list");


    while(1)
    {


            if(r->rollno==delete)
    {
        result=START;
        START=r->link;
        break;

    }

        if(r->link->rollno==delete)
        {
            result=r->link;
            r->link=r->link->link;
            break;
        }
        r=r->link;
    }
    result->link=NULL;
     return (result);
}
 void insertnode1(struct node *p)
{


     struct node *t1;

    if(START1==NULL)
        START1=p;
    else
    {
        t1=START1;
        while(t1->link!=NULL)
        {
            t1=t1->link;
        }
        t1->link=p;
    }

}

int main()
{


    MessageBox(0,"WELCOME","STUDENT RECORD",0);
    system("color f5");
    int a,i;
    struct node *p;
    char ch[8];
label:
    {
    printf("Enter the Adminstrator password\n");
    for(i=0;i<8;i++)
    {
        ch[i]=_getch();
        printf("*");
    }
    printf("\n");

    }
    ch[i]='\0';
    while(strcmp(ch,"kushalab")!=0)
    {

    printf("\nWrong password\n");
    printf("TRY AGAIN!!!\n");
    goto label;

    }
    {
    printf("\n*****************************************************************\n");
    printf("<1>Enter the record\n");
    printf("<2>Delete the record\n");
    printf("<3>show data\n");
    printf("<4>Show deleted records\n");
    printf("<5>EXIT\n");
    printf("*****************************************************************\n");
    }
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            insertnode();

            break;

        case 2:
            {
            int q;
            struct node *t;
            printf("Enter the roll number of record to be deleted:");
            scanf("%d",&q);

            t=deletenode(q);
                insertnode1(t);

            break;

            }
        case 4:
            viwlist(START1);

            break;
        case 5:
            exit(0);
        case 3:
            viwlist(START);

            break;

        }
    }
    return 0;
}
