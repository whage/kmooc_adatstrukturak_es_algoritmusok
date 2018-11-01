#include <iostream>
#include <cmath>

#include "5.hpp"

// finds the first 5 Mersenne-primes 
int main() {
    int count = 0;
    int p = 2; // first prime

    while (count < 5) {
        if (is_prime(p)) {
            int other = std::pow(2, p) - 1;

            if (is_prime(other)) {
                count++;
                std::cout << other << "\n";
            }
        }

        p++;
    }
}
