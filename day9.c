#include<stdio.h>
int main()
{
    char str[100],i,len,temp;
    printf("Enter string");
    scanf("%s",&str);
    for(i=0;str[i]!=0;i++)
    {
        len++;
    }
    for(i=0;i<str[i]!=0;i++)
    {
        temp=str[i];
        str[i]=str[len-1];
        str[len-1]=temp;
    }
    for(i=0;str[i]!=0;i++)
    {
        printf("%c",str[i]);
    }
}
