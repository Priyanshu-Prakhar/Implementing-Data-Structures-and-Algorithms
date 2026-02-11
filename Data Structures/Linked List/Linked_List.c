#include<stdio.h>
#include<stdlib.h>
// #include "linkedList.h"

typedef struct node{
    int data;
    struct node *link;
} node; // Definition of a Node of Linked List

node* create_LL(int data);
void add_node(node *head, int value);
node* get_last_node (node *head);

node* create_LL (int data){
    node *head = (node*)malloc(sizeof(node));
    head->data = data;
    head->link = NULL;
    return head;
    
}

void add_node (node *head, int value){
    node *current = malloc(sizeof(node));
    current->data = value;
    current->link = NULL;
    head->link = current;
}

node* get_last_node (node *head){
    node *ptr;
    ptr = head;
    while(ptr -> link != NULL){
        ptr = ptr->link;
    };
    return ptr;
}

int main(){
    node* list1 = create_LL(5);
    add_node(list1, 6);
    printf("%d", get_last_node(list1)->data);

    return 0;
}

// struct node{
//     int data;
//     struct node *link;
// }; // Node of Linked List

// int main(){
//     struct node *head = NULL; // Initialisiing the head node.
//     head = malloc(sizeof(struct node));

//     head->data = 45;
//     head->link = NULL; /* All nodes including the head node point to NULL when initialised.
//     This gives us freedom to expand the list later if we need to */
//     printf("Size of struct node = %d\n", sizeof(struct node));

//     printf("Data in head node = %d", head->data);
//     return 0;
// }