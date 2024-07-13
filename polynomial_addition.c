#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int cf;
    int px;
    struct node *link;
};
typedef struct node *NODE;

NODE insert_rear(int cf, int px, NODE head);
int compare(int x, int y);
void display(NODE head)
{
    NODE cur;
    if(head->link==head)
    {
        printf("Polynomial doesnot exist\n");
        return;
    }
    cur=head->link;
    while(cur!=head)
    {
        if(cur->cf>0)
            printf("+");
        printf("%dx^%d",cur->cf,cur->px);
        cur=cur->link;
    }
}

NODE read_poly(NODE head)
{
    int n, i, cf, px;
    printf("Enter the number of terms\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the coefficient and power of x of term %d\n",i);
        scanf("%d%d",&cf,&px);
        head=insert_rear(cf,px,head);
    }
    return head;
}

NODE insert_rear(int cf, int px, NODE head)
{
    NODE temp, cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->cf=cf;
    temp->px=px;
    temp->link=temp;
    cur=head->link;
    while(cur->link!=head)
        cur=cur->link;
    cur->link=temp;
    temp->link=head;
    return head;
}

NODE add_poly(NODE h1, NODE h2, NODE h3)
{
    int sumcf;
    NODE p1, p2;
    p1=h1->link;
    p2=h2->link;
    while((p1!=h1)&&(p2!=h2))
    {
        switch(compare(p1->px,p2->px))
        {
            case 0: sumcf=p1->cf+p2->cf;
                    if(sumcf>0)
                        h3=insert_rear(sumcf,p1->px,h3);
                    p1=p1->link;
                    p2=p2->link;
                    break;
            case 1: h3=insert_rear(p1->cf,p1->px,h3);
                    p1=p1->link;
                    break;
            case -1:h3=insert_rear(p2->cf,p2->px,h3);
                    p2=p2->link;
                    break;
        }
    }
    while(p1!=h1)
    {
        h3=insert_rear(p1->cf,p1->px,h3);
        p1=p1->link;
    }
    while(p2!=h2)
    {
        h3=insert_rear(p2->cf,p2->px,h3);
        p2=p2->link;
    }
    return h3;
}

int compare(int x, int y)
{
    if(x==y)
        return 0;
    else if(x>y)
        return 1;
    else
        return -1;
}

int main()
{
    NODE h1, h2, h3;
    h1=(NODE)malloc(sizeof(struct node));
    h1->link=h1;
    h2=(NODE)malloc(sizeof(struct node));
    h2->link=h2;
    h3=(NODE)malloc(sizeof(struct node));
    h3->link=h3;
    printf("Enter the first polynomial\n");
    h1=read_poly(h1);
    printf("Enter the second polynomial\n");
    h2=read_poly(h2);
    h3=add_poly(h1,h2,h3);
    printf("The first polynomial is\n");
    display(h1);
    printf("The second polynomial is\n");
    display(h2);
    printf("The resulting polynomial after addition is\n");
    display(h3);
    return 0;
}
