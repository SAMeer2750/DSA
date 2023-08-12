#include <stdio.h>

int main()
{
    int arr[100], i, n, p, ele;
    printf("Input the size of array : ");
    scanf("%d", &n);
    /* Stored values into the array*/
    printf("Input %d elements in the array in ascending order:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Input the value to be inserted : ");
    scanf("%d", &ele);
    printf("The exist array list is :\n");
    for (i = 0; i < n; i++)
        printf("% 5d", arr[i]);
    /* Determine the position where the new value will be insert.*/
    for (i = 0; i < n; i++)
    {

        if (ele < arr[i])
        {
            p = i;
            break;
        }
        else
        {
            p = i + 1;
        }
    }
    /* move all data at right side of the array */
    for (i = n + 1; i >= p; i--)
        arr[i] = arr[i - 1];
    /* insert value at the proper position */
    arr[p] = ele;
    printf("\n\nAfter Insert the list is :\n");
    for (i = 0; i <= n; i++)
        printf("% 5d", arr[i]);
    printf("\n");
}
