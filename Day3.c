#include<stdio.h>
int main()
{
    int a[20],n,i,k,found=0,c=0;
    printf("Enter size of array");
    scanf("%d",&n);
    printf("Enter array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search");
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            found=1;
            printf("Element found at index %d\n",i);
            printf("Total comparisons= %d\n",c);
            break;
        }
        c++;
    }
    if(found==0)
    {
        printf("Element not found");
    }
    
}
