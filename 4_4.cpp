#include <iostream>

#include "4.hpp"

double add_matrices(int **a, int**b, int**sum, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() { 
    const int width  = 3;
    const int height = 4;
    
    int **a = allocate_matrix(width, height);
    int **b = allocate_matrix(width, height);

    int ** sum = allocate_matrix(width, height);

    fill_matrix(a, width, height);
    fill_matrix(b, width, height);
    
    add_matrices(a, b, sum, width, height);

    std::cout << "sum of matrices:\n";
    print_matrix(sum, width, height);
}
