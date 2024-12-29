#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *head = NULL;
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addBeg(int data){
    struct Node* current = createNode(data);
    if(head == NULL){
        head = current;
        return;
    }
    current->next = head;
    head = current;
}
void addEnd(int data){
    struct Node* current = createNode(data);
    if(head == NULL){
        head = current;
        return;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = current;
}
void delBeg(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void delEnd(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    while(current->next!=NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}
int search(int data){
    struct Node* temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void display(){
    struct Node *temp = head;
    printf("List : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int item, choice;
    while(1){
        printf("Enter 1.Add at beginning 2.Add at end 3.Display 4.Exit : ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter an item to add at beginning : ");
                scanf("%d", &item);
                addBeg(item);
                break;
            case 2:
                printf("Enter an item to add at end : ");
                scanf("%d", &item);
                addEnd(item);
                break;
            case 3:
                display();
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("Enter an item to search : ");
                scanf("%d", &item);
                if(search(item)){
                    printf("%d found in the list\n", item);
                }
                else{
                    printf("%d not found in the list\n", item);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}