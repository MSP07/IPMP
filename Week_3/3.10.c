#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool isPalindrome(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;
    struct Node* temp = NULL;

    // Move fast and slow pointers to middle of the list
    while(fast && fast->next) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // If the list has odd number of elements, move the slow pointer one step forward
    if(fast != NULL) {
        slow = slow->next;
    }

    // Compare the first half of the list (in reverse order) with the second half of the list
    while(slow != NULL) {
        if(slow->data != prev->data) {
            return false;
        }
        slow = slow->next;
        prev = prev->next;
    }

    return true;
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
    third->next = second;
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list:\n");
    printList(head);

    if(isPalindrome(head)) {
        printf("The linked list is a palindrome\n");
    }
    else {
        printf("The linked list is not a palindrome\n");
    }

    return 0;
}
