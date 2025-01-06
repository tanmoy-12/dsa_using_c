#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to insert a node into the priority queue
struct Node* enqueue(struct Node* head, int data, int priority) {
    struct Node* temp = newNode(data, priority);

    // If the queue is empty or the new node has higher priority than the head
    if (head == NULL || head->priority < priority) {
        temp->next = head;
        return temp;  // New head
    }

    // Traverse the queue to find the correct position for the new node
    struct Node* start = head;
    while (start->next != NULL && start->next->priority >= priority) {
        start = start->next;
    }
    temp->next = start->next;
    start->next = temp;

    return head;  // Head remains unchanged
}

// Function to remove and return the highest-priority element
struct Node* dequeue(struct Node* head, int* data) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        *data = -1;
        return NULL;
    }

    struct Node* temp = head;
    *data = temp->data;
    head = head->next;
    free(temp);

    return head;  // Return the updated head
}

// Function to display the priority queue
void display(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

// Main function to test the priority queue
int main() {
    struct Node* pq = NULL;
    int data;

    pq = enqueue(pq, 10, 2);
    pq = enqueue(pq, 20, 5);
    pq = enqueue(pq, 30, 3);
    pq = enqueue(pq, 40, 5);
    pq = enqueue(pq, 50, 1);

    printf("Initial Priority Queue:\n");
    display(pq);

    pq = dequeue(pq, &data);
    printf("\nDequeued element: %d\n", data);

    printf("\nPriority Queue after dequeue:\n");
    display(pq);

    return 0;
}
