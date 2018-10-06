#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double calculate_result(int n) {
    double result = 1;

    for (int i = 2; i <= n; i++) {
        double term = 1.0 / pow(i, 2);
        
        if (i % 2 == 0) {
            result -= term;
        } else {
            result += term;
        }   
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
