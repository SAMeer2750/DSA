#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;
int count;
int choice = 1;
int pos, i = 1;

void creation()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void display()
{
    temp = head;
    count = 0;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("\nCurrent no. of nodes: %d", count);
}
void insertatbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data u want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void inseratend()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data u want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertbypos()
{
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Invallid position");
    }

    else if (pos == 1)
    {
        insertatbeg();
        display();
    }

    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data u want to insert: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
        display();
    }
    i = 1;
}
void delatbeg()
{
    if (head == NULL)
    {
        printf("list is empty--");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        display();
    }
}
void delatend()
{
    temp = head;
    struct node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        prev->next = NULL;
        free(temp);
        display();
    }
}
void delbypos()
{
    struct node *posnode;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        display();
    }
    else
    {
        temp = head;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        posnode = temp->next;
        temp->next = posnode->next;
        free(posnode);
        display();
    }
}
int main()
{
    head = NULL;

    while (choice)
    {
        creation();
        printf("do u want to creat another node(1 or 0): ");
        scanf("%d", &choice);
    }
    display();
    while (1)
    {
        int option;
        printf("\nenter the option\n1. insert new node at the beginning\n2. insert new node at the end\n3. insert after a given position\n4. deletion of first node\n5. deletion of the last node\n6. deletion by position\n7.exit\n");

        printf("\nEnter the option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            insertatbeg();
            display();
            break;
        }
        case 2:
        {
            inseratend();
            display();
            break;
        }
        case 3:
        {
            insertbypos();
            break;
        }
        case 4:
        {
            delatbeg();
            break;
        }
        case 5:
        {
            delatend();
            break;
        }
        case 6:
        {
            delbypos();
            break;
        }
        case 7:
            return 0;
        default:
        {
            printf("invalid option");
            break;
        }
        }
    }
    return 0;
}