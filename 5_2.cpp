#include <iostream>

#include "5.hpp"

// finds the first 10 p primes where p+10 is also prime
int main() {
    int count = 0;
    int p = 2; // first prime

    while (count < 10) {
        if (is_prime(p) && is_prime(p + 10)) {
            count++;
            std::cout << p << "\n";
        }

        p++;
    }
}
