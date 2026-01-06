#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} IntVector;

IntVector create_vector(int capacity) {
    // Allocate memory for the data array. capacity must be > 0
    IntVector v = {
        .data = (int *)malloc(capacity * sizeof(int)),
        .size = 0,
        .capacity = capacity
    };
    return v;
}

void append(IntVector *v, int value) {
    if (v->size == v->capacity) {
        // Handle capacity overflow
        printf("Resizing from %d to %d...\n", v->capacity, v->capacity * 2);
        v->capacity *= 2;
        // Realloc frees old memory and allocates new memory
        // Copies contents from old data to the new data, up to the old size
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
        // If realloc fails, it returns NULL. HW: handle this case properly
    }
    v->data[v->size++] = value;
}

void free_vector(IntVector *v) {
    // v *should not be used* after this call
    // Free allocated memory. HW: handle NULL pointer case
    free(v->data);
}

int main(){
    IntVector v = create_vector(1);
    for(int i = 0; i < 50; i++) append(&v, i);
    free_vector(&v);
    return 0;
}