#include<stdio.h>
#include<time.h>

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

    start = clock();
    long result_recursive = fib_recursive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for fib(%d)=%ld (recursive): %f seconds\n", n, result_recursive, cpu_time_used);

    start = clock();
    long result_iterative = fib_iterative(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time for fib(%d)=%ld (iterative): %f seconds\n", n, result_iterative, cpu_time_used);
    return 0;
}