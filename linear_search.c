#include<stdio.h>
#include<stdlib.h>

void creation(int *a, int *n)
{
    printf("\nEnter the elements :");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int search(int *a, int *n, int *e, int *f)
{
    for (int  i = 0; i < *n; i++)
    {
        if (a[i]==*e)
        {
            *f =1;
            return i;
        }
        
    }
}

int main(){
    int a[100], n, e;
    int f=0;
    printf("enter the no. of elements: ");
    scanf("%d", &n);
    creation(a, &n);
    printf("Enter the search element: ");
    scanf("%d", &e);
    int i = search(a, &n, &e, &f);
    if (f == 1)
    {
        printf("INDEX: %d",i);
    }
    else{
        printf("Element not found");
    }
    return 0;
}