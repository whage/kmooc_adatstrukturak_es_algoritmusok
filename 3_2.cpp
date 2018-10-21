#include <iostream>

#define SIZE 5

using namespace std;

int main() {
    int a[SIZE];
    
    // ask for numbers
    for (int i = 0; i < SIZE; i++) {
        cout << "enter item #" << i << " :";
        cin >> a[i];
    }
    
    int max_index = 0;
    
    // find max index
    for (int i = 0; i < SIZE; i++) {
        if (a[i] >= a[max_index]) {
            max_index = i;
        }
    }

    // save max value to variable
    int max = a[max_index];

    // shift each item from 0..max_index to the right
    for (int i = max_index - 1; i >= 0; i--) {
        a[i+1] = a[i];
    }

    // move max to first place
    a[0] = max;

    // print out final array
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
}
