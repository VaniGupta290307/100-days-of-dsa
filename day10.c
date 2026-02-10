#include<stdio.h>
int main()
{
    char s[100];
    int len=0,found=1,i;
    printf("Enter the string");
    scanf("%s",s);
    for(i=0;s[i]!=0;i++)
    {
        len++;
    }
    for(i=0;i<len;i++)
    {
        if(s[i]!=s[len-1-i])
        {
            found=0;
        }
    }
    if(found==1)
    {
        printf("Pallidrome");
    }
    else
    {
        printf("Not pallidrome");
    }
    
}
