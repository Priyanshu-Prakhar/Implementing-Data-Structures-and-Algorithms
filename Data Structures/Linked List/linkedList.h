#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    int data;
    struct node *link;
} node; // Definition of a Node of Linked List

node* create_LL(int data);
void add_node(node *head, int value);
void get_last_node (node *head);
#endif