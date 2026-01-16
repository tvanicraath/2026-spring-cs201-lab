#include <stdio.h>
#include "vector.h"

int main() {
    int N=100, k=30;
    IntVector dacoits = create_vector(1);
    for(int i=1; i<=N; i++) append(&dacoits, i);

    IntVector elimination_order = create_vector(1);
    int index = 0;
    while(dacoits.size > 0) {
        index = (index + k - 1) % dacoits.size;
        append(&elimination_order, dacoits.data[index]);
        pop_index(&dacoits, index);
    }

    printf("Elimination order: ");
    for(int i=0; i<elimination_order.size; i++) {
        printf("%d ", elimination_order.data[i]);
    }
    printf("\n");
    free_data(&dacoits);
    free_data(&elimination_order);
    return 0;
}