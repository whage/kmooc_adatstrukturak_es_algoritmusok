#include <iostream>
#include <cstdlib>
#include <cmath>

int **fill_matrix(int **matrix, int width, int height) { 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int current;
            
            std::cout << "element at (" << i << "," << j << "):";
            std::cin >> current;

            matrix[i][j] = current;
        }
    }

    return matrix;
}

double arithmetic_mean(int **matrix, int width, int height) {
    double result = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result += matrix[i][j];
        }
    }

    return result / (width * height);
}

double geometric_mean(int **matrix, int width, int height) {
    double result = 1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result *= matrix[i][j];
        }
    }

    return std::pow(result, 1.0 / (width * height));
}

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
    
    // allocate space for matrix
    int **matrix = (int **)malloc(sizeof(int*) * height);

    for (int i = 0; i < height; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * width);
    }

    //std::cout << arithmetic_mean(fill_matrix(matrix, width, height), width, height) << "\n";
    //std::cout << geometric_mean(fill_matrix(matrix, width, height), width, height) << "\n";
    
    print_lowest_elements(fill_matrix(matrix, width, height), width, height);
}
