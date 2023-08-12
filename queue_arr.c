#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N];
int front =-1;
int rare =-1;

void enqueue(){
    if(rare == (N-1) ){
        printf("\n...Queue Overflow!!!...");
    }
    else if (front == -1 && rare == -1)
    {
        front=rare=0;
        int val;
        printf("\nEnter the element to Enqueue: ");
        scanf("%d", &val);
        q[rare]=val;
    }
    else{
        rare++;
        int val;
        printf("\nEnter the element to Enqueue: ");
        scanf("%d", &val);
        q[rare] = val;
    }
    
}

void dequeue(){
    if (front == -1 && rare == -1){
        printf("\n...Queue Underflow!!!...");
    }
    else if (front==rare){
        front=rare=-1;
    }
    else {
        front++;
    }
}

void display(){
    printf("\nQueue elements are: ");
    if (front == -1 && rare == -1){
        printf("..Queue is empty!!!..");
    }
    else{
        for (int i = front; i < rare + 1; i++)
        {
            printf(" %d ", q[i]);
        }
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
