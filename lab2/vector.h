#ifndef VECTOR_H // This is called an include guard. Pretend this is a syntax, you will learn about it later.
#define VECTOR_H // Start of the guard

typedef struct {
    int *data;
    int size;
    int capacity;
} IntVector;

IntVector create_vector(int capacity);
void append(IntVector *v, int value);
void free_data(IntVector *v);
int search(IntVector *v, int val);
#endif // End of the guard