#include <iostream>

#define SIZE 50

using namespace std;

int main() {
    long a[SIZE];
    
    cout << "enter first number: ";
    cin >> a[0];

    a[1] = a[0] * a[0];

    // compute elements
    for (int i = 2; i <= SIZE; i++) {
        a[i] = a[i-1] * a[i-2];
    }

    // print elements
    for (int i = 0; i < SIZE; i++) {
        cout << a[i] << endl;
    }
}
