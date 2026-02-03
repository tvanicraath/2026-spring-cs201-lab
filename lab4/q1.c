// ## Part 1: Stock Price History
// You are given daily stock prices of a company in an array.
// Given a list of daily stock prices, calculate the "span" for each day. 
// The span is the maximum number of consecutive days (backwards from the current day) that the price has been less than or equal to that day's price.
// Write a $O(n^2)$ solution first, and then optimize it to $O(n)$ time using a well-known[^hint-stocks] data structure.

// [^hint-stocks]: Use a (monotonic) stack. 

// **Example:**
// Input: `[100, 80, 50, 60, 70, 40, 90]`
// Output: `[1, 1, 1, 2, 3, 1, 6]`

#include <stdio.h>

void print_array(const char* msg, const int arr[], int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void naive(const int prices[], int n, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = 1; // At least the current day
        for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; j--) {
            result[i]++;
        }
    }
}

void optimized(const int prices[], int n, int result[]) {
    int stack[n];
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && prices[stack[top]] <= prices[i]) {
            top--;
        }
        result[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}

int main() {
    int prices[] = {100, 80, 50, 60, 70, 40, 90};
    int n = sizeof(prices) / sizeof(prices[0]);

    int naive_result[n], optimized_result[n];
    naive(prices, n, naive_result);
    print_array("Naive Result:\t\t", naive_result, n);
    optimized(prices, n, optimized_result);
    print_array("Optimized Result:\t", optimized_result, n);
    return 0;
}