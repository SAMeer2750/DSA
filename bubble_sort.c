#include<stdio.h>
#include<stdlib.h>
void creation(int *a, int *n){
for (int i=0; i<*n; i++){
    scanf("%d",&a[i]);
}
}
void sort(int n,int a[]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                int f = a[j];
                a[j] = a[j + 1];
                a[j + 1] = f;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main(){
    int a[100];
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    creation(a,&n);
    sort(n,a);
    return 0;
}
