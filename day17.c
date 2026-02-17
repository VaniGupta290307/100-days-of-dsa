#include<stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);
    int a[n];

    // Input array
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max = a[0];
    int min = a[0];

    // Find max and min
    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }
