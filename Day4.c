#include<stdio.h>
int main()
{
    int n,a[100],i,j,temp;
    printf("Enter size");
    scanf("%d",&n);
    printf("Enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    printf("The reversed array is ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
