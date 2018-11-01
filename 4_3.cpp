#include <iostream>

#include "4.hpp"

double print_lowest_elements(int **matrix, int width, int height) {
    for (int i = 0; i < height; i++) {
        int lowest_index = 0;
        
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] <= matrix[i][lowest_index]) {
                lowest_index = j;
            }
        }
        
        std::cout << "lowest element in line " << i << ": " << matrix[i][lowest_index] << "\n";
    }
}

int main() { 
    const int width  = 3;
    const int height = 4;
    
    int **matrix = allocate_matrix(width, height);
    
    print_lowest_elements(fill_matrix(matrix, width, height), width, height);
}
