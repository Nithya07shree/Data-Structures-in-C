#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE insert_BST(int item, NODE root)
{
    NODE temp, cur, prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
    {
        return temp;
    }
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(item<cur->info)
            cur=cur->llink;
        else if(item>cur->info)
            cur=cur->rlink;
        else
        {
            printf("Duplicate item!Insertion not possible\n");
            free(temp);
            return root;
        }
    }
    if(item<prev->info)
        prev=prev->llink=temp;
    else 
        prev->rlink=temp;
    return root;
}

//preorder NLR
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

//postorder LRN
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->info);
    }
}

//inorder LNR
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->info);
        inorder(root->rlink);
    }
}

void display(NODE root, int height)
{
    int i;
    if(root==NULL)
        return;
    display(root->rlink,height+1);
    for(i=1;i<=height;i++)
        printf("   ");
    printf("%d\n",root->info);
    display(root->llink, height+1);
}

int main()
{
    NODE root=NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Inorder\t3.Preorder\t4.Postorder\t5.Display\t6.Exit\n");
        printf("Enter your choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to be inserted\t");
                   scanf("%d",&item);
                   root=insert_BST(item,root);
                   break;
            case 2:if(root==NULL)
                       printf("Root is empty\n");
                   else
                   {
                       printf("Ther inorder traversal is\n");
                       inorder(root);
                   }
                   break;
            case 3:if(root==NULL)
                       printf("Root is empty\n");
                   else
                   {
                       printf("Ther preorder traversal is\n");
                       preorder(root);
                   }
                   break;
            case 4:if(root==NULL)
                       printf("Root is empty\n");
                   else
                   {
                       printf("Ther postorder traversal is\n");
                       postorder(root);
                   }
                   break;
            case 5:if(root==NULL)
                   {
                    printf("The tree is empty\n");
                   }
                   else
                   {
                    display(root,0);
                   }
                   break;
            default:exit(0);
        }
    }
}
