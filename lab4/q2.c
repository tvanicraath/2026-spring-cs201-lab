#include <stdio.h>
#include "vector.h"

int main() {
    int N=100, k=30;
    IntVector dacoits = create_vector();
    for(int i=1; i<=N; i++) append(&dacoits, i);

    IntVector elimination_order = create_vector();
    int index = 0;
    while(dacoits.size > 0) {
        index = (index + k - 1) % dacoits.size;
        Node* dacoit = search_by_index(&dacoits, index);
        append(&elimination_order, dacoit->data);
        pop_index(&dacoits, index);
    }
    
    print_vector("Elimination order: ", &elimination_order);
    free_data(&dacoits);
    free_data(&elimination_order);
    return 0;
}