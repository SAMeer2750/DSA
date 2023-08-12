// Perform a 2D array operations of creating 2 matrics and adding, substracting, multiplying, and transpose of the matrics

#include <stdio.h>
#include <stdlib.h>

int myarr1[100][100];
int myarr2[100][100];
int c[100][100];
//Creation of first matrix
void creation1(int n, int m)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &myarr1[i][j]);
        }
    }
}
//Creation of second matrix
void creation2(int n, int m)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &myarr2[i][j]);
        }
    }
}
//Addition of matrics
void add(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            c[i][j] = myarr1[i][j] + myarr2[i][j];
        }
    }
}
//Substraction of matrics
void sub(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            c[i][j] = myarr1[i][j] - myarr2[i][j];
        }
    }
}
//Multiplication of matrics
void mul(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            c[i][j] = 0;
            c[i][j] += myarr1[i][j] * myarr2[i][j];
        }
    }
}
//Transpose of first matrix
void trans1(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            myarr1[i][j]=myarr1[j][i];
        }
    }
}
//Transpose of second matrix
void trans2(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            myarr2[i][j] = myarr2[j][i];
        }
    }
}
//Display function
void display(int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            printf("%d ", c[i][j]);
        }
    }
}
//Main function
int main()
{
    int n;
    int m;
    printf("Enter the no. of rows and columns of  Matrics: ");
    scanf("%d%d", &n, &m);
    printf("Enter the elements of first matrix: ");
    creation1( n, m);
    printf("Enter the elements of second matrix: ");
    creation2(n, m);
    
    while (1)
    {
        printf("\nChoose from the following array operations :-\n1. Addition of two matrics.\n2. Substraction of two matrics.\n3. Multiplication of two matrics.\n4. Transpose of the  first matrics\n5. Transpose of the  first matrics\n6. Exit\nChoice : ");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1:
            {
                add(&n,&m);
                printf("Sum of two matrics is: ");
                display(&n,&m);
                break;
            }
            case 2:
            {
                sub(&n,&m);
                printf("Difference between two matrics is: ");
                display(&n,&m);
                break;
            }
            case 3:
            {
                trans2(&n, &m);
                mul(&n,&m);
                printf("Product of the two matrics is: ");
                display(&n,&m);
                break;
            }
            case 4:
            {
                trans1(&n,&m);
                break;
            }
            case 5:
            {
                trans2(&n, &m);
                break;
            }
            case 6: return 0;
            default:
            {
                printf("Invalid input..");
            }
        }
    }
    return 0;
}