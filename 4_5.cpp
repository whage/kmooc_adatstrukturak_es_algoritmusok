#include <iostream>

#include "4.hpp"

int get_smallest_under_antidiagonal(int **matrix, int n) {
    // set smallest to top right element below the antidiagonal
    int smallest_i = 1;
    int smallest_j = n - 1;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j + i > n - 1 ; j--) {
            if (matrix[i][j] < matrix[smallest_i][smallest_j]) {
                smallest_i = i;
                smallest_j = j;
            }
        }
    }

    return matrix[smallest_i][smallest_j];
}

int main() { 
    int n;

    std::cout << "enter value of n (for an n x n matrix): ";
    std::cin >> n;
    
    int **matrix = allocate_matrix(n, n);

    fill_matrix(matrix, n, n);

    std::cout << get_smallest_under_antidiagonal(matrix, n);
}
