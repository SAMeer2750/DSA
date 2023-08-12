#include<stdio.h>
#include<stdlib.h>
#define N 5

int q[N];
int front = -1;
int rare = -1;

void enqueue(){
    int val;
    if (front == -1 && rare == -1)
    {
        front = rare = 0;
        printf("\nEnter the element to Enqueue: ");
        scanf("%d",&val);
        q[rare]=val;
    }
    else if (((rare+1)%N)==front){
        printf("\n...Queue Overflow!!!...");
    }
    else
    {
        rare = (rare + 1) % N;
        printf("\nEnter the element to Enqueue: ");
        scanf("%d",&val);
        q[rare]=val;
    }
}

void dequeue(){
    if (front == -1 && rare == -1)
    {
        printf("\n...Queue Underflow!!!...");
    }
    else if (front == rare)
    {
        front = rare = -1;
    }
    else{
        front=(front+1)%N;
    }
}

void display(){
    printf("\nQueue elements are: ");
    if (front == -1 && rare == -1)
    {
        printf("..Queue is empty!!!..");
    }
    else{
        int i=front;
        while (i!=rare)
        {
            printf(" %d ",q[i]);
            i=(i+1)%N;
        }
        printf(" %d ",q[rare]);
    }
}

int main(){
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