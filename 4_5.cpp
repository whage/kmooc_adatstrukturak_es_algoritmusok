#include <iostream>

#include "4.hpp"

int get_lowest_in_antidiagonal(int **matrix, int n) {
    int lowest_i = 0;
    int lowest_j = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
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

    std::cout << get_lowest_in_antidiagonal(matrix, n);
}
