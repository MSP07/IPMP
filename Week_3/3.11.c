#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void insertSorted(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty or the value is smaller than the first element
    if(*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;

    // Traverse the list to find the correct position to insert the new node
    while(current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    struct Node* head = NULL;
    insertSorted(&head, 3);
    insertSorted(&head, 1);
    insertSorted(&head, 4);
    insertSorted(&head, 2);
    insertSorted(&head, 5);

    printf("Sorted linked list:\n");
    printList(head);

    return 0;
}
