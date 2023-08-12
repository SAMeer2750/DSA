#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top,*newnode;
void push(int x){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}

void peek(){
    if(top==NULL) printf("\nStack is empty");
    else printf("\nTop of the stack is %d ",top->data);
}

void pop(){
    struct node *temp;
    temp=top;
    if (top==NULL)printf("\nUnderflow...");
    else{
        printf("\nTop element is %d ",top->data);
        top=temp->link;
        free(temp);
    }
}

int main(){
    top=NULL;
    int option;
    while(1){
        printf("\n---Menu---\n\n1.Push operation\n2.Pop operation\n3.Peak operation\n4.Display\n5.Exit\n\nEnter your opetion: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            {
                int x;
                printf("Enter the element to push: ");
                scanf("%d",&x);
                push(x);
            }
            break;

        case 2:
            {
                pop();
            }
            break;

        case 3:
            {
                peek();
            }    
            break;

        case 4:
            {
                display();
            }    
            break;

        case 5:
            {
                return 0;
            }    
        default:
            printf("Invalid option...");
            break;
        }
    }
}