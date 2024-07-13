#include<stdio.h>
void bubble_sort(int n, int a[]);
int main()
{
    int a[100],i,n;
    printf("enter n value\n");
    scanf("%d",&n);
    printf("enter array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble_sort(n,a);
    printf("sorted elements of the list are\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    return 0;
}

void bubble_sort(int n, int a[])
{
    int i, j, temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
}
