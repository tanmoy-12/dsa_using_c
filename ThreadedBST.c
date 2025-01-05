#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *lchild, *rchild;
    bool lthread, rthread;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->lchild = temp->rchild = NULL;
    temp->lthread = temp->rthread = true;
    return temp;
}

// Inorder traversal of Threaded BST
void inorder(struct Node *root) {
    if (!root) return;

    struct Node *curr = root;
    while (curr->lthread == false)
        curr = curr->lchild;

    while (curr != NULL) {
        printf("%d ", curr->data);
        if (curr->rthread)
            curr = curr->rchild;
        else {
            curr = curr->rchild;
            while (curr && curr->lthread == false)
                curr = curr->lchild;
        }
    }
}

// Insert a new node into Threaded BST
struct Node* insert(struct Node *root, int key) {
    if (root == NULL) 
        return createNode(key);

    struct Node *parent = NULL, *curr = root;

    while (curr) {
        if (key == curr->data) {
            printf("Duplicate key %d not allowed.\n", key);
            return root;
        }
        parent = curr;

        if (key < curr->data) {
            if (curr->lthread == false)
                curr = curr->lchild;
            else
                break;
        } else {
            if (curr->rthread == false)
                curr = curr->rchild;
            else
                break;
        }
    }

    struct Node *newNode = createNode(key);

    if (key < parent->data) {
        newNode->lchild = parent->lchild;
        newNode->rchild = parent;
        parent->lchild = newNode;
        parent->lthread = false;
    } else {
        newNode->rchild = parent->rchild;
        newNode->lchild = parent;
        parent->rchild = newNode;
        parent->rthread = false;
    }

    return root;
}

// Search in Threaded BST
struct Node* search(struct Node *root, int key) {
    struct Node *curr = root;

    while (curr != NULL) {
        if (key == curr->data)
            return curr;

        if (key < curr->data) {
            if (curr->lthread == false)
                curr = curr->lchild;
            else
                break;
        } else {
            if (curr->rthread == false)
                curr = curr->rchild;
            else
                break;
        }
    }

    return NULL;
}

// Delete a node from Threaded BST
struct Node* deleteNode(struct Node *root, int key) {
    struct Node *parent = NULL, *curr = root;

    while (curr != NULL) {
        if (key == curr->data)
            break;

        parent = curr;
        if (key < curr->data) {
            if (curr->lthread == false)
                curr = curr->lchild;
            else
                break;
        } else {
            if (curr->rthread == false)
                curr = curr->rchild;
            else
                break;
        }
    }

    if (curr == NULL) {
        printf("Key %d not found in the tree.\n", key);
        return root;
    }

    // Case 1: Node to be deleted has both threads (leaf node)
    if (curr->lthread && curr->rthread) {
        if (parent == NULL) {
            free(curr);
            return NULL;
        }

        if (parent->lchild == curr) {
            parent->lchild = curr->lchild;
            parent->lthread = true;
        } else {
            parent->rchild = curr->rchild;
            parent->rthread = true;
        }

        free(curr);
    }
    // Case 2: Node to be deleted has only one child
    else if (curr->lthread || curr->rthread) {
        struct Node *child;

        if (curr->lthread == false)
            child = curr->lchild;
        else
            child = curr->rchild;

        if (parent == NULL) {
            free(curr);
            return child;
        }

        if (parent->lchild == curr)
            parent->lchild = child;
        else
            parent->rchild = child;

        free(curr);
    }
    // Case 3: Node to be deleted has two children
    else {
        struct Node *successor = curr->rchild;

        while (successor->lthread == false)
            successor = successor->lchild;

        int val = successor->data;
        root = deleteNode(root, successor->data);
        curr->data = val;
    }

    return root;
}

int main() {
    struct Node *root = NULL;

    int choice, item;
    while (1) {
        printf("\n1. Insert\n2. Inorder Traversal\n3. Search\n4. Delete\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter item to search: ");
                scanf("%d", &item);
                if (search(root, item))
                    printf("Item %d found in the tree.\n", item);
                else
                    printf("Item %d not found in the tree.\n", item);
                break;
            case 4:
                printf("Enter item to delete: ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
