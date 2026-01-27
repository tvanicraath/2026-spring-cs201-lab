#include <stdio.h>

void printArray(char* msg, int arr[], int n) {
    printf("%s", msg);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void On2Solution(int prices[], int n) {
    int spans[n];
    for (int i = 0; i < n; i++) {
        spans[i] = 1; // At least the current day
        for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; j--) {
            spans[i]++;
        }
    }
    printArray("O(n^2) spans: ", spans, n);
}

void OnSolution(int prices[], int n) {
    int spans[n];
    int stack[n]; // Stack to store indices
    int top = -1; // Stack is initially empty

    for (int i = 0; i < n; i++) {
        while (top != -1 && prices[stack[top]] <= prices[i]) {
            top--; // Pop from stack
        }
        spans[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i; // Push current index onto stack
    }
    printArray("O(n) spans: ", spans, n);
}



int main() {
    int prices[] = {100, 80, 50, 60, 70, 40, 90};
    int n = sizeof(prices) / sizeof(prices[0]);
    
    On2Solution(prices, n);
    OnSolution(prices, n);

    return 0;
}