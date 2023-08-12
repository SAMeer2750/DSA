#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node  *tail,*newnode;
void creation(){
    int choice=1;
    tail=NULL;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do u want to create another node(0/1): ");
        scanf("%d",&choice);
    }
}
void display(){
    struct node *temp;
    if(tail==NULL){
        printf("list is empty..");    
    }
    else{
        temp=tail->next;
        while (temp->next!=tail->next)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf(" %d ",temp->data);
    }
}
void insertatbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data u want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=tail
    ->next;
    tail->next=newnode;
}
void insertatend(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data u want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}
int getlength(){
    int count=0;
    struct node*temp;
    temp=tail->next;
    while (temp->next!=tail->next)
    {
        count++;
        temp=temp->next;
    }
    count++;
    return count;
}
void insertbypos(){
    int pos,l,i=1;
    printf("Enter the position: ");
    scanf("%d",&pos);
    l=getlength();
    if(pos<0||pos>l){
        printf("Invalid position");
    }
    else if (pos==1)
    {
        insertatbeg();
    }
    else{
        struct node *temp;
        temp=tail->next;
        while (i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data u want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void delatbeg(){
    struct node *temp;
    temp=tail->next;
    tail->next=temp->next;
    free(temp);
}
void delatend(){
    struct node *temp,*prevnode;
    temp=tail->next;
    while (temp->next!=tail->next){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=temp->next;
    tail=prevnode;
    free(temp);
}
void delbypos(){
    int pos,l,i=1;
    l=getlength();
    printf("Enter the position: ");
    scanf("%d",&pos);
    if (pos==1){
        delatbeg();
    }
    else if(pos==l){
        delatend();
    }
    else{
        struct node *temp, *posnode;
        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        posnode = temp->next;
        temp->next = posnode->next;
        free(posnode);
    }
}
int main(){
    int option;
    creation();
    display();
    
    while (1)
    {
        printf("\n1. insert new node at the beginning\n2. insert new node at the end\n3. insert at a given position\n4. deletion of first node\n5. deletion of the last node\n6. deletion by position\n7.exit\n");
        printf("\nEnter the option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            insertatbeg();
            display();
        }
        break;

        case 2:
        {
            insertatend();
            display();
        }
        break;

        case 3:
        {
            insertbypos();
            display();
        }
        break;

        case 4:
        {
            delatbeg();
            display();
        }

        case 5:
        {
            delatend();
            display();
        }
        break;

        case 6:
        {
            delbypos();
            display();
        }
        break;

        case 7:
            return 0;

        default:
            printf("Invalid option...");
            break;
        }
    }
    
    
}