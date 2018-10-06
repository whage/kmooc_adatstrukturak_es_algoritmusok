#include <stdio.h>
#include <stdlib.h>

double calculate_result(int n) {
    double result = 0;

    for (int i = 1; i <= n; i++) {
        // cast i to long so the result won't overflow for large number of iterations
        result += 1.0 / (long(i) * (i+2));
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: calculate_result <num_iterations>\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    
    printf("the value after %d iterations: %.12f\n", n, calculate_result(n));
}
