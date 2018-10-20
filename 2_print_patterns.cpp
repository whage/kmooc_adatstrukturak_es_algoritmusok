#include <iostream>
#include <cstdlib>

using namespace std;

struct pattern {
    int width;
    int height;
    char **grid;
};

void print_pattern(pattern p) {
    // iterate each line
    for (int i = 0; i < p.height; i++) {
        // iterate each char in current line
        for (int j = 0; j < p.width; j++) {
            cout << p.grid[i][j];
        }

        // add new line character
        cout << endl;
    }
}

pattern exercise_1() {
    pattern p;
    p.width = p.height = 8;

    // allocate memory for grid: 8 * 8 * sizeof(char)
    p.grid = (char**)malloc(sizeof(char*) * p.width);

    for (int i = 0; i < p.height; i++) {
        p.grid[i] = (char*)malloc(sizeof(char*));
    }

    for (int i = 0; i < p.height; i++) {
        int space_count = i;
        
        for (int s = 0; s < space_count; s++) {
            p.grid[i][s] = ' ';
        }

        for (int j = (p.width - i); j >= 0; j--) {
            // convert int to corresponding numeric character
            p.grid[i][j] = j + 49;
        }
    }

    return p;
}

int main() {
    print_pattern(exercise_1());
}
