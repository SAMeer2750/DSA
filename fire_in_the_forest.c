#include <stdio.h>
#include <stdlib.h>
int a[100][100];
int x, y;
int count = 0;

void creation_of_the_forest(int n, int m)
{
    printf("\nEnter the forest and barran land: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}
int light_up_the_fire()
{
    if (a[x][y] == 0)
    {
        a[x][y] = 2;
    }
    else
    {
        printf("\nThere is no tree in the location--");
        return 0;
    }
}
void spread_the_fire(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 2)
            {
                if (a[i][j + 1] == 0)
                {
                    a[i][j + 1] = 2;
                }
                if (a[i][j - 1] == 0)
                {
                    a[i][j - 1] = 2;
                }
                if (a[i + 1][j] == 0)
                {
                    a[i + 1][j] = 2;
                }
                if (a[i - 1][j] == 0)
                {
                    a[i - 1][j] = 2;
                }
                if (a[i + 1][j + 1] == 0)
                {
                    a[i + 1][j + 1] = 2;
                }
                if (a[i - 1][j - 1] == 0)
                {
                    a[i - 1][j - 1] = 2;
                }
                if (a[i - 1][j + 1] == 0)
                {
                    a[i - 1][j + 1] = 2;
                }
                if (a[i + 1][j - 1] == 0)
                {
                    a[i + 1][j - 1] = 2;
                }
            }
        }
    }
    count++;
    if (count != (n * m))
        spread_the_fire(n, m);
}
int main()
{
    int n, m;
    printf("Enter the no. of rows and columns: ");
    scanf("%d%d", &n, &m);
    creation_of_the_forest(n, m);
    printf("Forest before fire--\n");
    display(n, m);
    printf("\nEnter the co-ordinate that lights up: ");
    scanf("%d%d", &x, &y);
    light_up_the_fire();
    spread_the_fire(n, m);
    printf("Forest after the fire--\n");
    display(n, m);
}