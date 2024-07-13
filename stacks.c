#include<stdio.h>
#include<stdlib.h>
#define stacksize 5

void push(int item,int *top,int s[])
{
    if(*top==stacksize-1)
    {
        printf("Stack overflow occured\n");
        return;
    }
    *top=*top+1;
    s[*top]=item;
}
int pop(int *top, int s[])
{
    int item;
    if(*top==-1)
    {
        return-1;
    }
    item=s[*top];
    *top=*top-1;
    return item;
}

void display(int *top,int s[])
{
    int i;
    if(*top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i=0;i<=*top;i++){
        printf("%d \n",s[i]);
    }
}

void main()
{
    int top,choice,item,s[30],del;
    top=-1;
    for(;;)
    {
        printf("\n\n1.Push\t2.Pop\t3.Display\t4.Exit\n\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :printf("Enter the item to push\n");
                    scanf("%d",&item);
                    push(item,&top,s);
                    break;
            case 2 :del=pop(&top,s);
                    if(del==-1){
                        printf("Stack underflow occured\n");
                    }
                    else{
                        printf("Deleted item is %d \n",del);
                    }
                    break;
            case 3 :printf("Stack contents are \n");
                    display(&top,s);
                    break;
            default:exit(0);
        }
    }
}
