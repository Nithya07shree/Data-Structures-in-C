#include<stdio.h>
#include<stdlib.h>
#define maxsize 20

int insert_heap(int item, int a[], int n)
{
    int c, p;
    if(n==maxsize+1)
    {
        printf("Heap is full\n");
        return n-1;
    }
    c=n;
    p=c/2;
    while(p!=0 && item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=c/2;
    }
    a[c]=item;
    return n;
}

void display(int a[], int n)
{
    int i;
    if(n==0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("The contents of the heap are\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
}

int main()
{
    int a[100],n,choice,item;
    n=0;
    for(;;)
    {
        printf("1.Insert\t2.Display\n3.Exit\n");
        printf("Enter the choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to insert\t");
                   scanf("%d",&item);
                   n=insert_heap(item,a,n+1);
                   break;
            case 2:display(a,n);
                   break;
            default:exit(0);
        }
    }
}
