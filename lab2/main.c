#include <stdio.h>
#include "vector.h"
int main(){
    IntVector v = create_vector(1);
    for(int i = 0; i < 50; i++) append(&v, i);
    printf("Index of 23: %d\n", search(&v, 23));
    printf("Index of 201: %d\n", search(&v, 201));
    free_data(&v);
    // Free makes v a vector of size 0 and capacity 1
    printf("Index of 23 after free: %d\n", search(&v, 23));
    return 0;
}