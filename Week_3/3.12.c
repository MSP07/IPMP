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

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;
    second->next = third;

    printf("Original linked list:\n");
    printList(head);

    reverseList(&head);

    printf("Reversed linked list:\n");
    printList(head);

    return 0;
}
