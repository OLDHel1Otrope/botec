#include <stdio.h>
int main()
{
    int i, j, row, column;
    int arr[100][100];
    int count = 0;
    printf("enter the number of rows and columns in the array \t");
    scanf("%d%d", &row, &column);
    for (i = 0; i < row; i++)
    {
        printf("enter the row %d\t", i);
        for (j = 0; j < column; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // counting the number of non zero elements
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
                count++;
        }
    }
    printf("\nthe number of the non zero elements is %d\n", count);
    if (count < (row * column) / 2)
    {
        printf("the given matrix is sparse matrix, finding the three row triplet notation\n");
        int arrro3[3][count];
        int ele = 0;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                if (arr[i][j] != 0)
                {
                    arrro3[0][ele] = i;
                    arrro3[1][ele] = j;
                    arrro3[2][ele] = arr[i][j];
                    ele++;
                }
            }
        }

        for (int i = 0; i < count; i++)
        {
            printf("{%d,%d,%d}\t", arrro3[0][i], arrro3[1][i], arrro3[2][i]);
        }
        printf("\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d\t", arrro3[0][i]);
        }
        printf("\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d\t", arrro3[1][i]);
        }
        printf("\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d\t", arrro3[2][i]);
        }
        printf("\n");
    }

    return 0;
}
