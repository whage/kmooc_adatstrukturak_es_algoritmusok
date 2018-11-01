#include <iostream>

#include "4.hpp"

double arithmetic_mean(int **matrix, int width, int height) {
    double result = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result += matrix[i][j];
        }
    }

    std::cout << "arithmetic mean: " << result / (width * height) << "\n";
}

int main() { 
    const int width  = 3;
    const int height = 4;
    
    int **matrix = allocate_matrix(width, height);

    arithmetic_mean(fill_matrix(matrix, width, height), width, height);
}
