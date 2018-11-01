#include <iostream>

#include "4.hpp"

int get_lowest_under_antidiagonal(int **matrix, int n) {
    // set lowest to top right element below the antidiagonal
    int lowest_i = 1;
    int lowest_j = n - 1;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j + i > n - 1 ; j--) {
            if (matrix[i][j] < matrix[lowest_i][lowest_j]) {
                lowest_i = i;
                lowest_j = j;
            }
        }
    }

    return matrix[lowest_i][lowest_j];
}

int main() { 
    int n;

    std::cout << "enter value of n (for an n x n matrix): ";
    std::cin >> n;
    
    int **matrix = allocate_matrix(n, n);

    fill_matrix(matrix, n, n);

    std::cout << get_lowest_under_antidiagonal(matrix, n);
}
