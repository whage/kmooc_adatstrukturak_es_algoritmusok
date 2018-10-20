#include <iostream>
#include <cstdlib>

using namespace std;

struct grid {
    int width;
    int height;
    char **cells;
};

void print_grid(grid g) {
    // iterate each line
    for (int i = 0; i < g.height; i++) {
        // iterate each char in current line
        for (int j = 0; j < g.width; j++) {
            cout << g.cells[i][j];
        }

        // add new line character
        cout << endl;
    }
}

grid exercise_1(grid g) {
    for (int i = 0; i < g.height; i++) {
        int space_count = i;
        
        for (int s = 0; s < space_count; s++) {
            g.cells[i][s] = ' ';
        }

        for (int j = space_count; j < g.width; j++) {
            // convert int to corresponding numeric character
            g.cells[i][j] = j - space_count + 49;
        }
    }

    return g;
}

grid exercise_2(grid g) {
    for (int i = 0; i < g.height; i++) {
        int space_count = i;

        for (int j = 0; j < g.width - space_count; j++) {
            g.cells[i][j] = g.width - space_count - j + 48;
        }
        
        for (int s = g.width - space_count; s < g.width; s++) {
            g.cells[i][s] = ' ';
        }
    }

    return g;
}

grid allocate_grid(int width, int height) {
    grid g;
    g.width = g.height = 8;

    // allocate memory for grid: 8 * 8 * sizeof(char)
    g.cells = (char**)malloc(sizeof(char*) * g.width);

    for (int i = 0; i < g.height; i++) {
        g.cells[i] = (char*)malloc(sizeof(char*));
    }

    return g;
}

int main() {
    print_grid(exercise_1(allocate_grid(8, 8)));
    print_grid(exercise_2(allocate_grid(8, 8)));
}
