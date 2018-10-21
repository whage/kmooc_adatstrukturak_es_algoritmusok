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

    int multiplier;

    cout << "enter multiplier: ";
    cin >> multiplier;

    for (int i = 0; i < SIZE; i++) {
        if (a[i] == a[max_index]) {
            a[i] = a[i] * multiplier;
        }
    }

    // print out final array
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << " ";
    }
}
