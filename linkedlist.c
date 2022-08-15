#include <stdio.h>
#include <stdlib.h>

// Linked list implementation in C

typedef struct node node;

struct node {
    int value;
    struct node *next;
};

void remove_list_entry(node * head, node * entry){
    node * indirect = head;
    while(indirect != entry){
        indirect = indirect->next;
    }
    *indirect = *entry->next;
}

void remove_list_entry_2(node * head, node * entry){
    node * prev = NULL;
    node * walk = head;
    while(walk != entry){
        prev = walk;
        walk = walk->next;
    }
    if(!prev){
        
        *head = *entry->next;
    }  
    else{
        prev->next = entry->next;
    }
        
}

// print the linked list value
void printLinkedlist(node * p) {
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    // Initialize nodes
    node *head;
    node *one = NULL;
    node *two = NULL;
    node *three = NULL;

    // Allocate memory
    one = malloc(sizeof(node));
    two = malloc(sizeof(node));
    three = malloc(sizeof(node));

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // printing node-value
    head = one;
    node * new = malloc(sizeof(node));
    new = head->next;
    printLinkedlist(head);
    remove_list_entry(head, two);
    printLinkedlist(head);
    remove_list_entry_2(head, new);
    printLinkedlist(head);
}