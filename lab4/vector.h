#ifndef VECTOR_H // This is called an include guard. Pretend this is a syntax, you will learn about it later.
#define VECTOR_H // Start of the guard

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} IntVector;

IntVector create_vector();
void append(IntVector *v, int value);
void free_data(IntVector *v);
Node* search_by_index(IntVector *v, int index);
void pop_index(IntVector *v, int index);
void print_vector(char* msg, IntVector *v);
#endif // End of the guard