#include <stdio.h>

void move_zeroes(int arr[], int n) {
    int write_index = 0;

    // Move non-zero elements to the front
    for (int read_index = 0; read_index < n; read_index++) {
        if (arr[read_index] != 0) {
            arr[write_index++] = arr[read_index];
        }
    }

    // Fill the remaining positions with zeros
    while (write_index < n) {
        arr[write_index++] = 0;
    }
}

void print_arr(int arr[], int n) {
    printf("Final array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    move_zeroes(arr, n);
    print_arr(arr, n);
    return 0;
}