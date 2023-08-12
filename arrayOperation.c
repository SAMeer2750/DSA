// Perform the array operations of creation, insertion by position and value, deletion by position and value, search and update, display, and exit.

#include<stdio.h>
#include<stdlib.h>

int myarr[100];
//creation of the array
void creation(int n){
    printf("\nEnter array elements : ");
    for (int i = 0; i < n; i++){
        scanf("%d", &myarr[i]);
    }
}
//insertion by position
void insertionbypos(int *n, int pos, int value){
    for (int i = *n - 1; i >= pos; i--){
        myarr[i + 1] = myarr[i];
    }
    myarr[pos] = value;
    (*n)++;
}
//insertion by value in multiple positions
void insertionbyval(int *n, int val1, int val2){
    for (int i = 0; i < *n; i++){
        if (myarr[i] == val1){
            int pos = i;
            for (int j = *n - 1; j >= pos; j--){
                myarr[j + 1] = myarr[j];
            }
            myarr[pos] = val2;
            (*n)++;
            i++;
        }
    }
}
//deletion by position
void deletionbypos(int *n, int pos){
    for (int i = pos; i < *n-1; i++){
        myarr[i] = myarr[i + 1];
    }
    (*n)--;
}
//deletion by value in multiple positions
void deletionbyval(int *n, int val){
    for (int i = 0; i < *n; i++){
        if (myarr[i] == val){
            for (int j = i; j < *n - 1; j++) {
                myarr[j] = myarr[j + 1];
            }
            (*n)--;
        }
    }
}
//search the value
void search(int n, int value){
    for (int i = 0; i < n; i++){
        if (myarr[i] == value){
            printf("\nNo. found at %dth index\n", i);
            return;
        }
    }
}
//display the array
void display(int n){
    printf("\nThe array elements are : ");
    for (int i = 0; i < n; i++){
        printf(" %d ", myarr[i]);
    }
}
//main function
int main(){
        int n;
        printf("\nEnter the size of the array : ");
        scanf("%d", &n);
        creation(n);

    while(1)
    {
        printf("\nChoose from the following array operations :-\n1. Insertion by position.\n2. Insertion by value.\n3. Deletion by position.\n4. Deletion by value\n5. Search element\n6. Update array.\n7. Display array\n8. Exit\nChoice : ");

        int choice;
        scanf("%d", &choice);
        switch (choice){
        case 1:
        {
            printf("\nYour choice is insertion by position.\nEnter the position and the replacing value : ");
            int pos, val;
            scanf("%d%d", &pos, &val);
            insertionbypos(&n, pos, val);
            break;
        }
        case 2:
        {
            printf("\nYour choice is insertion by value.\nEnter the value to be replaced and the replacing value : "); 
            int val1, val2;
            scanf("%d%d", &val1, &val2);
            insertionbyval(&n, val1, val2);
            break;
        }
        case 3:
        {
            printf("\nYour choice is deletion by position.\nEnter position of the element to be deleted : ");
            int pos;
            scanf("%d", &pos);
            deletionbypos(&n, pos);
            break;
        }
        case 4:
        {
            printf("\nYour choice is deletion by value\nEnter the value : ");
            int val;
            scanf("%d", &val);
            deletionbyval(&n, val);
            break;
        }
        case 5:
        {
            printf("\nYour choice is Searching an element\nEnter the value to be searched : ");
            int val;
            scanf("%d", &val);
            search(n, val);
            break;
        }
        case 6:
        { 
            printf("Your choice is to update the myarray : \nEnter the size of the myarray : ");
            scanf("%d", &n);
            creation(n);
            break;
        }
        case 7:
        {
            printf("Your choice is to display the elements of the myarray : \n");
            display(n);
            break;
        }
        case 8 : return 0;

        default:
        {
            printf("\nInvalid Input\n");
        }
        }
    }
    return 0;
}