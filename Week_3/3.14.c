#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node** head, struct node* new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void delete_last_node(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

void display_list(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert_node(&head, create_node(1));
    insert_node(&head, create_node(2));
    insert_node(&head, create_node(3));
    insert_node(&head, create_node(4));
    printf("Original list: ");
    display_list(head);
    delete_last_node(&head);
    printf("List after deleting last node: ");
    display_list(head);
    return 0;
}
