#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head1, *temp, *newnode,*head2;
int count;
void display(struct node *head, struct node *temp)
{

    temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        count++;
        temp = temp->next;
    }
}
void datafree(struct node *head){
    temp=head;
    while (temp!=NULL)
    {
        free(temp);
        temp=temp->next;
    }
    
}
void split()
{
    int pos;
    pos=count/2;
    int i=1;
    temp = head1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    head2=temp->next;
    temp->next=NULL;
}
int main(){
    head1 = NULL;
    int choice = 1;
    
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head1 == NULL)
        {
            head1 = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("do u want to creat another node(1 or 0): ");
        scanf("%d", &choice);
    }
    display(head1,temp);
    split();
    printf("\nFirst node: ");
    display(head1, temp);
    printf("\nSecond node: ");
    display(head2, temp);
    datafree(head1);
    datafree(head2);
}

