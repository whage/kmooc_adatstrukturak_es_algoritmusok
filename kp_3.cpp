#include <iostream>
#include <cstdlib>

// assumes sets - every element is unique in the arrays
int *get_intersection(int *a, int a_length, int *b, int b_length) {
    int max = a_length > b_length ? a_length : b_length;
    int min = a_length > b_length ? b_length : a_length;

    int *longer_one = max == a_length ? a : b;
    int *shorter_one = max == a_length ? b : a;
    
    // allocate space for maximum possible size
    int *results = (int*)(malloc(sizeof(int) * max));

    int counter = 0;

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < min ; j++) {
            if (longer_one[i] == shorter_one[j]) {
                results[counter++] = longer_one[i];
                break;
            }
        }
    }

    // allocate only as much space as needed
    int *final_results = (int*)(malloc(sizeof(int) * counter));

    for (int i = 0; i < counter; i++) {
        final_results[i] = results[i];
    }

    std::cout << "[ ";

    for (int i = 0; i < counter; i++) {
        std::cout << final_results[i] << " ";
    }

    std::cout << "]\n";
}

int main() {
    int t1[] = {2, 1, 3, 5, 4, 10, 8, 7};
    int t2[] = {2, 4, 0, 6, 7, 9};

    get_intersection(t2, 6, t1, 8);
}
