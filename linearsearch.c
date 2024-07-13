#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int main()
{
    int a[10],i,n,key;
    printf("enter n value\n");
    scanf("%d",&n);
    printf("enter array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter key\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
        printf("search is successful\n");
        printf("element is in %d position\n",i+1);
        exit(0);
        }
    }
    printf("search is unsuccessful\n");
}
