#include<stdio.h>

int main()
{
    int rows, cols, i, j, sum = 0;

    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    int a[rows][cols];

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    if(rows == cols)
    {
        for(i = 0; i < rows; i++)
        {
            sum = sum + a[i][i];
        }
        printf("Sum of diagonal elements is %d", sum);
    }
    else
    {
        printf("Diagonal sum not possible (matrix is not square).");
    }

    return 0;
}
