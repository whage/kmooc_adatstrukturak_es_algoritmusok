#include <iostream>
#include <cstdlib>

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

int **allocate_matrix(int width, int height) {
    int **matrix = (int **)malloc(sizeof(int*) * height);

    for (int i = 0; i < height; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * width);
    }

    return matrix;
}
