#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *front, *rare;

void enqueue()
{
    struct queue *newnode;
    newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->next = NULL;
    printf("\nEnter the element to Enqueue: ");
    scanf("%d", &newnode->data);
    if (front == NULL && rare == NULL)
    {
        front = rare = newnode;
    }
    else
    {
        rare->next = newnode;
        rare = newnode;
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
        struct queue *temp;
        temp = front;
        if (front == rare)
        {
            front = rare = NULL;
            free(temp);
        }
        else
        {
            front = front->next;
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
        struct queue *temp;
        temp = front;
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
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
