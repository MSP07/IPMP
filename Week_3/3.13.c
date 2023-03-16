#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtMiddle(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    struct Node* slow = *headRef;
    struct Node* fast = (*headRef)->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    newNode->prev = slow;
    newNode->next = slow->next;
    slow->next = newNode;
    newNode->next->prev = newNode;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    head->next = second;
    second->prev = head;
    second->next = NULL;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 4;
    second->next = third;
    third->prev = second;
    third->next = NULL;

    printf("Original doubly linked list:\n");
    printList(head);

    insertAtMiddle(&head, 3);

    printf("Doubly linked list after inserting a node at the middle:\n");
    printList(head);

    return 0;
}
