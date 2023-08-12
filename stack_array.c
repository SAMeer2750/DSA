#include<stdio.h>
#include<stdlib.h>
int stack[5];
int n=5;
int top=-1;
void push(){
    if(top>=(n-1)){
        printf("\n...Stack overlow!!!...");
    }
    else{
        top++;
        int val;
        printf("\nEnter the element to push: ");
        scanf("%d",&val);
        stack[top]=val;
    }
}
void pop(){
    if(top<=-1){
        printf("\n...Stack underflow!!!...");
    }
    else{
        printf("\nPoped element is: %d",stack[top]);
        top--;
    }
}
void display(){
    printf("\nStack elements are: ");
    for(int i=top;i>=0;i--){
        printf(" %d ",stack[i]);
    }
}
int main(){
    int option;
    while (1)
    {
        printf("\n---Menu---\n\n1.Push operation\n2.Pop operation\n3.Display\n4.Exit\n\nEnter your opetion: ");
        scanf("%d", &option);
        switch (option){
            case 1:{
                push();
                display();
            }
            break;

            case 2:{
                pop();
                display();
            }
            break;

            case 3:{
                display();
            }
            break;

            case 4: return 0;

            default: {
                printf("\n...Invalid option...");
            }
            break;
        }
    }
}    