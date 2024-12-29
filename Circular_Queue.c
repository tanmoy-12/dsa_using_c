//Circuular Queue
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
int arr[MAX];
int rear = -1, front = -1;
int isFull(){
    return (rear == MAX - 1) || (rear + 1 == front);
}
int isEmpty(){
    return (front == -1) || (front == rear+1);
}
void enqueue(int item){
    if(isFull()){
        printf("Queue Overflow");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    arr[rear] = item;
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow");
        return INT_MIN;
    }
    int item = arr[front];
    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
    return item;
}
int peek(){
    if(isEmpty()){
        printf("Queue is Empty");
        return INT_MIN;
    }
    return arr[front+1];
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty");
        return;
    }
    printf("Queue : ");
    int i=front;
    while(i!=rear+1){
        printf("%d ", arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main(){
    int item, choice;
    while(1){
        printf("Enter 1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter an item to push : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                printf("Popped item : %d\n", dequeue());
                break;
            case 3:
                printf("Top item : %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}