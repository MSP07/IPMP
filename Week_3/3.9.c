#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

void removeLoop(struct Node* head, struct Node* loopNode) {
    struct Node* ptr1 = head;
    struct Node* ptr2 = loopNode;
    while(ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    // Creating a loop in the linked list
    fourth->next = third;

    struct Node* loopNode = detectLoop(head);
    if(loopNode != NULL) {
        printf("Loop detected at node with data: %d\n", loopNode->data);
        removeLoop(head, loopNode);
        printf("Loop removed from the linked list\n");
    }
    else {
        printf("No loop detected in the linked list\n");
    }

    printf("Linked list after removing the loop:\n");
    printList(head);

    return 0;
}
