#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to delete a node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the list
void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}

// Main function to test the linked list implementation
int main() {
    struct Node* head = NULL;
    
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertBeginning(&head, 5);
    insertEnd(&head, 30);
    
    printf("Linked List: ");
    displayList(head);
    
    searchNode(head, 20);
    searchNode(head, 40);
    
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    displayList(head);
    
    return 0;
}
