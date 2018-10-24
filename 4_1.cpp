#include <iostream>

//typedef int[3][3] three_by_three_matrix;

int **fill_matrix() {
    int matrix[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int current;
            std::cout << "element at (" << i << "," << j << "):";
            std::cin >> current;

            matrix[i][j] = current;
        }
    }
}

int main() {
    fill_matrix();
}
