#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}; // Node of Linked List
int main(){
    struct node *head = NULL; // Initialisiing the head node.
    head = malloc(sizeof(struct node));

    head->data = 45;
    head->link = NULL; /* All nodes including the head node point to NULL when initialised.
    This gives us freedom to expand the list later if we need to */
    
    return 0;
}