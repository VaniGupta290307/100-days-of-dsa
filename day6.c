#include<stdio.h>
int main()
{
    int n,a[100],i;
    printf("Enter the size");
    scanf("%d",&n);
    printf("Enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n>0)
    {
        printf("%d",a[0]);
    }
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}
