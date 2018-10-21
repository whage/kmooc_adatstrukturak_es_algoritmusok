#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 110; i++) {
        if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0) {
            cout << i << " ";
        } else {
            if (i % 3 == 0) {
                cout << "Java";
            }

            if (i % 5 == 0) {
                cout << "Cpp";
            }

            if (i % 7 == 0) {
                cout << "Php";
            }

            cout << " ";
        }

        // add new line if we reached 11 items
        if (i % 11 == 0) {
            cout << endl;
        }
    }
}
