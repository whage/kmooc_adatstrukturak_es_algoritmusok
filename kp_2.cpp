#include <iostream>

#include "4.hpp"

// Ideas:
// 1. always process top row, remove row, rotate matrix, repeat - recursive?
// 2. find rules for direction of movement based on current coordinates

// implementing idea #2
int *list_numbers_in_spiral(int **matrix, int N) {
    int counter = 0;
    int i = 0;
    int j = 0;
    int *list = (int*)(malloc(sizeof(int) * N*N));
    
    while (counter <= N*N) {
        list[counter++] = matrix[i][j];
        
        if (i <= j && i + j < N-1) {
            //std::cout << "right ";
            j += 1;
            continue;
        }

        if (i < j && i + j >= N-1) {
            //std::cout << "down ";
            i += 1;
            continue;
        }

        if (i >= j && i + j > N-1) {
            //std::cout << "left ";
            j -= 1;
            continue;
        }

        if (i > j && i + j <= N-1) {
            if (i == j+1) {
                //std::cout << "right ";
                j += 1;
            } else {
                //std::cout << "up ";
                i -= 1;
            }
        }
    }

    return list;
}

int main() {
    const int N = 5;

    int **matrix = allocate_matrix(N, N);

    fill_matrix(matrix, N, N);

    int *list = list_numbers_in_spiral(matrix, N);

    for (int i = 0; i < N*N; i++) {
        std::cout << list[i] << " ";
    }
}
