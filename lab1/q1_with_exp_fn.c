#include<stdio.h>
#include<time.h>

void experiment(long (*fib_func)(int), char *label, int n) {
    clock_t start = clock();
    long result = fib_func(n);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for %s(%d): %f seconds\n", label, n, cpu_time_used);
}

long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long fib_iterative(int n) {
    if (n <= 1) return n;
    long second_last = 0, last = 1, curr;
    for (int i = 2; i <= n; i++) {
        curr = second_last + last;
        second_last = last;
        last = curr;
    }
    return last;
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    experiment(fib_recursive, "fib_recursive", n);
    experiment(fib_iterative, "fib_iterative", n);
    return 0;
}