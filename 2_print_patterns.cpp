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
    
    // add extra new line
    cout << endl;
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

grid exercise_3(grid g) {
    for (int i = 0; i < g.height; i++) {
        int space_count = g.width - (i + 1);

        for (int s = 0; s < space_count; s++) {
            g.cells[i][s] = ' ';
        }

        for (int j = space_count; j < g.width; j++) {
            g.cells[i][j] = g.width - j + 48;
        }
    }

    return g;
}

grid exercise_4(grid g) {
    int space_count = 7;
   
    // this time, we fill it up column-by-column (seems simpler)
    for (int i = 0; i < g.width; i++) {
        for (int s = 0; s < space_count; s++) {
            g.cells[s][i] = ' ';
        }

        for (int j = space_count, num = '1'; j < g.height; j++, num++) {
            g.cells[j][i] = num;
        }

        // if we are in the first 7 columns
        if (i < 7) {
            space_count -= 1;
        // from 8th column
        } else {
            space_count += 1;
        }
    }

    return g;
}

// same as exercise_4, but fills the grid from the bottom
grid exercise_5(grid g) {
    int space_count = 7;
   
    // this time, we fill it up column-by-column (seems simpler)
    for (int i = 0; i < g.width; i++) {
        for (int s = g.height - 1; s >= g.height - space_count; s--) {
            g.cells[s][i] = ' ';
        }

        for (int j = g.height - space_count - 1, num = '1'; j >= 0; j--, num++) {
            g.cells[j][i] = num;
        }

        // if we are in the first 7 columns
        if (i < 7) {
            space_count -= 1;
        // from 8th column
        } else {
            space_count += 1;
        }
    }

    return g;
}

grid allocate_grid(int width, int height) {
    grid g;
    g.width = width;
    g.height = height;

    // allocate memory for first dimension of grid
    g.cells = (char**)malloc(sizeof(char*) * g.width);

    for (int i = 0; i < g.height; i++) {
        // allocate memory for second dimension
        g.cells[i] = (char*)malloc(sizeof(char*));
    }

    return g;
}

int main() {
    cout << "1:" << endl;
    print_grid(exercise_1(allocate_grid(8, 8)));
    cout << "2:" << endl;
    print_grid(exercise_2(allocate_grid(8, 8)));
    cout << "3:" << endl;
    print_grid(exercise_3(allocate_grid(8, 8)));
    cout << "4:" << endl;
    print_grid(exercise_4(allocate_grid(15, 8)));
    cout << "5:" << endl;
    print_grid(exercise_5(allocate_grid(15, 8)));
}
