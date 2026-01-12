#include<stdio.h>
#include<stdlib.h>
#include "vector.h"


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

void free_data(IntVector *v) {
    //after free, vector is reset to one with capacity 1 and size 0
    free(v->data);
    v->size = 0;
    v->capacity = 1;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

int search(IntVector *v, int val) {
    for (int i = 0; i < v->size; i++) {
        if (v->data[i] == val) {
            return i;
        }
    }
    return -1; // Return -1 if the value is not found
}