
#include <stdio.h>
#include <stdlib.h>

    int binary_search(int *a, int e, int l, int r){

    int mid = l + (r - l) / 2;
    if (l > r)
        return -1;
    if (a[mid] == e)
    {
        return mid;
    }
    else if (a[mid] > e)
    {
        return binary_search(a, e, l, mid - 1);
    }
    else if (a[mid] < e)
    {
        return binary_search(a, e, mid + 1, r);
    }
}

void creation(int *a, int *n){

    printf("\nEnter the sorted elements :");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int main(){
    int a[100], n, e, l, r;
    printf("enter the no. of elements: ");
    scanf("%d", &n);
    creation(a, &n);
    printf("Enter the search element: ");
    scanf("%d", &e);
    l = 0;
    r = (n - 1);
    int index = binary_search(a, e, l, r);
    printf("Index is: %d", index);
    return 0;
}