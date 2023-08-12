#include<stdio.h>
#include<stdlib.h>
#define N 5

int s1[N],s2[N];
int count=0;
int top1=-1;
int top2=-1;

void push1(int data1){
    if (top1 == (N - 1))
    {
        printf("\n...Stack overlow!!!...");
    }
    else
    {
        top1++;
        s1[top1] = data1;
    }
}
void push2(int data2){
    if (top2 == (N - 1))
    {
        printf("\n...Stack overlow!!!...");
    }
    else
    {
        top2++;
        s2[top2] = data2;
    }
}
int pop1(){
    int s;
    s=s1[top1];
    top1--;
    return s;
}
int pop2(){
    int s;
    s = s2[top2];
    top2--;
    return s;
}

void enqueue(int val){
    push1(val);
    count++;
}

void dequeue(){
    if (top1 == -1 && top2 == -1){
        printf("\n...Queue underflow!!!...");
    }
    else{
        int a,b;

        for (int i = 0; i < count; i++)
        {
            push2(pop1());
        }
        b=pop2();
        printf("\n%d id dequeued...",b);
        count--;

        for (int i = 0; i < count; i++)
        {
            push1(pop2());
        }
    }
}

void display(){
    printf("\nQueue elements: ");
    if(top1==-1){
        printf("Queue is empty..");
    }
    for (int i = 0; i <= top1; i++)
    {
        printf(" %d ",s1[i]);
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
            int x;
            printf("\nEnter the element to enqueue: ");
            scanf("%d",&x);
            enqueue(x);
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