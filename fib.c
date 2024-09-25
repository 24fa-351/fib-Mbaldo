#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to calculate the Nth Fibonacci number
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to calculate the Nth Fibonacci number
int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 1;
    }

    // Parse the first argument (an integer)
    int input_num = atoi(argv[1]);

    // Parse the second argument (method: r or i)
    char method = argv[2][0];

    // Parse the third argument (filename)
    FILE *file = fopen(argv[3], "r");
    if (!file) {
        return 1;
    }

    // Read the integer from the file
    int file_num;
    fscanf(file, "%d", &file_num);
    fclose(file);

    // Add the two integers
    int N = input_num + file_num;

    // Calculate the (N - 1)th Fibonacci number based on the method
    int result;
    if (method == 'r') {
        result = fibonacci_recursive(N - 1);
    } else if (method == 'i') {
        result = fibonacci_iterative(N - 1);
    } else {
        return 1;
    }

    // Output only the result
    printf("%d\n", result);

    return 0;
}
