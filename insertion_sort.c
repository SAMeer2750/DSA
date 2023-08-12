#include <stdio.h>
#include <stdlib.h>

void creation(int a[], int n){
    printf("\nEnter the elements :");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
}

void insertion_sort(int *a, int n)
{
    int i, j, f;
    for (i = 1; i < n; i++)//first element is sorted by default
    {
        f = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > f)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = f;
    }
}

int main()
{
    int i;
    int a[100];
    int n;
    printf("Enter the no elements: ");
    scanf("%d",&n);
    creation(a,n);
    printf("Elements before sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    insertion_sort(a, n);
    printf("\nElements after sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}