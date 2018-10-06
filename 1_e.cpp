#include <stdio.h>
#include <stdlib.h>

int fac(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * fac(n-1);
}

double calculate_e(int n) {
    double result = 1;

    for (int i = 1; i < n; i++) {
        result += (1.0 / fac(i));
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: calculate_e <num_iterations>\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    
    printf("the value after %d iterations: %.12f\n", n, calculate_e(n));
}
