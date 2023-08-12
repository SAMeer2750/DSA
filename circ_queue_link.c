#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front, *rare;

void enqueue()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to Enqueue: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (front == NULL && rare == NULL)
    {
        front = rare = newnode;
        rare->next = front;
    }
    else
    {
        rare->next = newnode;
        rare = newnode;
        rare->next = front;
    }
}

void dequeue()
{
    if (front == NULL && rare == NULL)
    {
        printf("\n...Queue underflow!!!...");
    }
    else
    {
        struct node *temp;
        temp = front;
        if (front == rare)
        {
            front = rare = NULL;
            free(temp);
        }
        else
        {
            front = front->next;
            rare->next = front;
            free(temp);
        }   
    }
}

void display()
{
    printf("\nQueue elments are: ");
    if (front == NULL && rare == NULL)
    {
        printf("..Queue is empty!!!..");
    }
    else
    {
        struct node *temp;
        temp = front;
        while (temp->next != front)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf(" %d ", temp->data);
    }
}

int main()
{
    front = rare = NULL;
    int option;
    while (1)
    {
        printf("\n---Menu---\n\n1.Enqueue operation\n2.Dequeue operation\n3.Display\n4.Exit\n\nEnter your opetion: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            enqueue();
            display();
        }
        break;

        case 2:
        {
            dequeue();
            display();
        }
        break;

        case 3:
        {
            display();
        }
        break;

        case 4:
            return 0;

        default:
        {
            printf("\n...Invalid option...");
        }
        break;
        }
    }
}
