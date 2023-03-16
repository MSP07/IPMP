 #include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node** head, int data, int position) {
    struct node* new_node = create_node(data);
    if (*head == NULL) {
        new_node->next = new_node;
        *head = new_node;
        return;
    }
    if (position == 0) {
        new_node->next = *head;
        struct node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = new_node;
        *head = new_node;
        return;
    }
    struct node* current = *head;
    int i = 0;
    while (i < position - 1 && current->next != *head) {
        current = current->next;
        i++;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void display_list(struct node* head) {
    struct node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert_node(&head, 1, 0);
    insert_node(&head, 2, 1);
    insert_node(&head, 3, 2);
    insert_node(&head, 4, 3);
    printf("Original list: ");
    display_list(head);
    insert_node(&head, 5, 2);
    printf("List after inserting 5 at position 2: ");
    display_list(head);
    return 0;
}
