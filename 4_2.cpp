#include <iostream>
#include <cmath>

#include "4.hpp"

double geometric_mean(int **matrix, int width, int height) {
    double result = 1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result *= matrix[i][j];
        }
    }

    result = std::pow(result, 1.0 / (width * height));

    std::cout << "geometric mean: " << result << "\n";
}

int main() { 
    const int width  = 3;
    const int height = 4;
    
    int **matrix = allocate_matrix(width, height);

    geometric_mean(fill_matrix(matrix, width, height), width, height);
}
