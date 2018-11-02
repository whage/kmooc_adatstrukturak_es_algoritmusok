#include <iostream>
#include <cmath>

int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    return factorial(n - 1) * n;
}

int main() {
    for (int i = 100; i < 1000; i++) {
        int sum = 0;
        int product = 1;
        int temp = i;
        int digit;
        int f;

        for (int j = 0; j < 3; j++) {
            digit = temp % 10;
            f = factorial(digit);

            sum += f;
            product *= f;

            temp = temp / 10;
        }

        if (sum == i || product == i) {
            std::cout << i << std::endl;
        }
    }
}
