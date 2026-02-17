#include<stdio.h>

int main()
{
    int rows, cols, i, j, flag = 1;

    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    if(rows != cols)
    {
        printf("Not a symmetric matrix");
        return 0;
    }

    int a[rows][cols];

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(a[i][j] != a[j][i])
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
    }

    if(flag == 1)
        printf("Symmetric matrix");
    else
        printf("Not a symmetric matrix");

    return 0;
}
