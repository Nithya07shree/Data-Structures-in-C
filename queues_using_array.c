#include<stdio.h>
#include<stdlib.h>
#define queue_size 5

void insert_rear(int item,int *r, int q[])
{
    if(*r==queue_size-1)
    {
        printf("Queue is full, insertion not possible\n");
        return;
    }
    *r=*r+1;
    q[*r]=item;
}

void delete_front(int*f, int*r, int q[])
{
    int item;
    if(*f>*r)
    {
        printf("Queue is empty, deletion not possible\n");
        return;
    }
    item=q[*f];
    printf("The deleted item is %d\n",item);
    *f=*f+1;
    if(*f>*r)
    {
        *f=0;
        *r=-1;
    }
}

void display(int f, int r, int q[])
{
    int i;
    if(f>r)
    {
        printf("Queue is empty\n");
        return;
    }
    for(i=f;i<=r;i++)
        printf("%d\t",q[i]);
}

int main()
{
    int f, r, choice, item, q[20];
    f=0;
    r=-1;
    for(;;)
    {
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        printf("Enter your choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to insert\t");
                   scanf("%d",&item);
                   insert_rear(item,&r,q);
                   break;
            case 2:delete_front(&f,&r,q);
                   break;
            case 3:printf("The contents of queue are\n");
                   display(f,r,q);
                   break;
            default:exit(0);
        }
    }
}
