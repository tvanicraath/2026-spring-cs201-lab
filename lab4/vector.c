#include<stdio.h>
#include<stdlib.h>
#include "vector.h"


IntVector create_vector() {
    IntVector v;
    v.size = 0;
    v.head = NULL;
    return v;
}

Node *create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void append(IntVector *v, int value) {
    if(v->head == NULL) {
        v->head = create_node(value);
    } else {
        Node* p = v->head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = create_node(value);
    }
    v->size++;
}

void free_nodes(Node* node) {
    if (node == NULL) return;
    free_nodes(node->next);
    free(node);
}

void free_data(IntVector *v) {
    free_nodes(v->head);
    v->head = NULL;
    v->size = 0;
}

Node* search_by_index(IntVector *v, int index) {
    Node* p = v->head;
    while(p != NULL) {
        if(index-- == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL; // Return NULL if the value is not found
}

void pop_index(IntVector *v, int index) {
    if (index < 0) {
        // Do nothing if index is out of bounds
        return;
    }
    Node* current = v->head;
    Node* previous = NULL;
    while(current != NULL && index > 0) {
        previous = current;
        current = current->next;
        index--;
    }
    if (current == NULL) {
        // Do nothing if index is out of bounds
        return;
    }
    if (previous == NULL) {
        // Removing the head node
        v->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current); 
    v->size--; 
}

void print_vector(char *msg, IntVector *v) {
    printf("%s", msg);
    Node* p = v->head;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}