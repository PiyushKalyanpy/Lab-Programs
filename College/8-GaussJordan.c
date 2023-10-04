#include <stdio.h>

void printMat(int n, int mat[][n + 1], char *msg)
{
    printf("\n");
    printf("------ %s -------\n", msg);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void gaussJordan(int n, int mat[][n + 1])
{

    // Converting to upper triangular matrix
    for (int i = 0; i < n; i++) // Changed the loop condition
    {
        for (int j = 0; j < n; j++) // Changed the loop condition
        {
            if (j != i)
            {
                float ratio = (float)mat[j][i] / mat[i][i];
                for (int k = i; k <= n; k++)
                {
                    mat[j][k] -= ratio * mat[i][k];
                }
            }
        }
    }

    printMat(n, mat, "Reduced Row-Echelon Form");

    // Back substitution
    float x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = (float)mat[i][n] / mat[i][i];
    }

    // Print the solution
    printf("\n ------  Solution -----\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %f\n", i + 1, x[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    int mat[n][n + 1];

    printf("Enter the augmented matrix coefficients:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    gaussJordan(n, mat);

    return 0;
}
