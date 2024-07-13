#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int main()
{
    int a[10],n,i,key,low,high,mid;
    printf("enter the n value\n");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter the key\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("search is successful\n");
            printf("element is in %d position\n",mid+1);
            exit(0);
        }
        else if(a[mid]<key)
        low=mid+1;
        else
        high=mid-1;
    }
    printf("Search is unsuccessful\n");
}
