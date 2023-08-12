#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head, *tail, *newnode;
int count = 0;

void display()
{
    struct node *temp;
    temp = head;
    count = 0;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        count++;
        temp = temp->next;
    }
}

void insertatbeg(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data u want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insertatend(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data u want to insert: ");
    scanf("%d", &newnode->data);
    newnode->prev = tail;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
}

void insertbypos(){
    int pos, i = 1;
    struct node *temp;
    temp = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertatbeg();
    }
    else
    {
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void delatbeg(){
    struct node *temp;
    temp = head;
    head->next->prev = NULL;
    head = temp->next;
    free(temp);
}

void delatend(){
    struct node *temp;
    temp = tail;
    tail->prev->next = NULL;
    tail = temp->prev;
    free(temp);
}

void delbypos(){
    int pos, i = 1;
    printf("Enter the poition: ");
    scanf("%d", &pos);
    struct node *temp;
    temp = head;
    if (pos == 1)
    {
        delatbeg();
    }
    else if (pos == count)
    {
        delatend();
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
}

int main()
{

    int choice = 1;
    head = NULL;
    // creation
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Do u want to creat another node(1,0): ");
        scanf("%d", &choice);
    }

    display();
    while (1)
    {
        printf("\nenter the option\n1. insert new node at the beginning\n2. insert new node at the end\n3. insert after a given position\n4. deletion of first node\n5. deletion of the last node\n6. deletion by position\n7.exit\n");
        int option;
        printf("Enter the option: ");
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
            insertatend();
            display();
            break;
        }

        case 3:
        {
            insertbypos();
            display();
            break;
        }

        case 4:
        {
            delatbeg();
            display();
            break;
        }

        case 5:
        {
            delatend();
            display();
            break;
        }

        case 6:
        {
            delbypos();
            display();
            break;
        }

        case 7:
            return 0;

        default:
            printf("Invalid option------ <>_<|>");
            break;
        }
    }
}