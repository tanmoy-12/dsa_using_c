//Queue Implementation Uisng Array
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
int isEmpty(){
    return front==rear;
}
int isFull(){
    return (rear == MAX - 1);
}
void enqueue(int item){
    if(isFull()){
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear]=item;
    return;
}
void dequeue(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued item is %d\n",queue[++front]);
    return;
}
void peek(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Front item is %d\n",queue[front+1]);
    return;
}
void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(i=front+1;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
    return;
}
int main(){
    while (1)
    {
        int choice,item;
        printf("Enter 1 to enqueue 2 to dequeue 3 to peek 4 to display 0 to exit : ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    
}