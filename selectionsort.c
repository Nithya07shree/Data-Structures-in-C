#include<stdio.h>
void selection_sort(int a[], int n);
int main()
{
    int a[50],i,n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    printf("Sorted elements are \n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
void selection_sort(int a[], int n)
{
    int i,min,j,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    // printf("Sorted elements are \n");
    // for(i=0;i<n;i++){
    //     printf("%d\n",a[i]);
    // }
    // return
}
