#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insert_rear(int item, NODE first)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
    {
        first=temp;
        return first;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("List empty!!Deletion not possible \n");
        return first;
    }
    temp=first;
    first=first->link;
    printf("The deleted item is %d\n",temp->info);
    free(temp);
    return first;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The contents of list are \n");
    cur=first;
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

int main()
{
    NODE first;
    int choice, item;
    first=NULL;
    for(;;)
    {
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to insert\t");
                   scanf("%d",&item);
                   first=insert_rear(item,first);
                   break;
            case 2:first=delete_front(first);
                   break;
            case 3:display(first);
                   break;
            default:exit(0);
        }
    }
    return 0;
}
