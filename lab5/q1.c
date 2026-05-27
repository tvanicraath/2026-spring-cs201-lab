#include <stdio.h>

typedef struct {
    int index, value;
} Pair;

void print_array(const char *msg, const int arr[], int size) {
    printf("%s", msg);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void naive(const int prices[], int n, int k, int result[]) {
    for (int i = 0; i <= n - k; i++) {
        int max_price = prices[i];
        for (int j = 1; j < k; j++) {
            if (prices[i + j] > max_price) {
                max_price = prices[i + j];
            }
        }
        result[i] = max_price;
    }
}

int monotone_push(Pair deque[], int left, int right, int i, int val) {
    while(right >= left && deque[right].value <= val) {
        //val dominates the last element
        right--;
    }
    deque[++right] = (Pair){i, val};
    return right;
}

void optimized(const int prices[], int n, int k, int result[]) {
    Pair deque[n]; // Deque to store pairs of (index, value).
    // for simplicity, size is set to n
    // can optimize it to k by using circular array
    
    int left = 0, right = -1; // Deque implemented with two pointers
    for (int i = 0; i < n; i++) {
        // 1. Remove elements that have fallen out of the window
        if (left <= right && deque[left].index <= i - k) {
            left++;
        }

        // 2. Monotonic Property: Remove smaller elements from the back
        // because the current element prices[i] will outlive them and is larger.
        while (right >= left && deque[right].value <= prices[i]) {
            right--;
        }

        // 3. Add current element to the back
        deque[++right] = (Pair){i, prices[i]};

        // The front of the deque (left) is always the maximum.
        if (i >= k - 1) {
            result[i - k + 1] = deque[left].value;
        }
    }
}

int main() {
    int prices[] = {100, 80, 50, 60, 70, 40, 90};
    int n = sizeof(prices) / sizeof(prices[0]);
    int k = 3;
    // assume: 1 <= k <= n and n is small enough to fit in stack

    int naive_ans[n-k+1], optimized_ans[n-k+1];
    naive(prices, n, k, naive_ans);
    print_array("Naive Solution:\t\t", naive_ans, n-k+1);
    optimized(prices, n, k, optimized_ans);
    print_array("Optimized Solution:\t", optimized_ans, n-k+1);

    return 0;
}